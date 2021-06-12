#include "creature.h"

Creature::Creature(std::string name, std::string path) {
    this->name = name;
    this->currentDir = path;

    string temp = path;
    this->fullPath = temp.append("/").append(name).append(".creature");

    // Create file and add name
    this->self.open(this->fullPath, std::fstream::out);
    if (!this->self.is_open()) {
        std::cout << "Failed to create file. :(" << std::endl;
    }

    getNearbyFilesAndFolders();

    this->self << name << std::endl;
    this->self << this->currentDir << std::endl;

    srand(time(NULL));
}

void Creature::move() {
    this->self.close();
    string destination = chooseNewDestination();
    if (destination == "") {
        return;
    }

    string newFullPath = this->currentDir;

    // Step up or down
    if (destination == "..") {
        size_t pos = this->currentDir.find_last_of("/");
        size_t length = this->currentDir.length();

        // Remove last dir from path
        this->currentDir.erase(pos, length - pos);

        newFullPath = this->currentDir;
        newFullPath.append("/").append(this->name).append(".creature");
    } else {
        newFullPath.append("/").append(destination).append("/").append(this->name).append(".creature");        
        this->currentDir = this->currentDir.append("/").append(destination);
    }

    // Move the creature
    std::filesystem::rename(this->fullPath, newFullPath);
    this->fullPath = newFullPath;

    // Reopen the file at the new location
    this->self.open(this->fullPath, std::fstream::out | std::fstream::app);
    if (!this->self.is_open()) {
        std::cout << "Failed to reopen file. :(" << std::endl;
    }

    this->nearbyFiles.clear();
    this->nearbyFolders.clear();

    this->self << this->currentDir << std::endl;    
    getNearbyFilesAndFolders();
}

void Creature::eat(string file) {

}

void Creature::getNearbyFilesAndFolders() {
    string tempName = this->name;
    tempName.append(".creature");

    for (const auto & entry : std::filesystem::directory_iterator(this->currentDir)) {        
        if (entry.is_directory()) {
            this->nearbyFolders.push_back(entry.path().string());
        } else {
            // Dont add self
            if (entry.path().filename().compare(tempName) != 0) {
                this->nearbyFiles.push_back(entry.path().string());
            }
        }
    }
}

string Creature::chooseNewDestination() {
    int index = rand() % (this->nearbyFolders.size() + 1);

    // If index same as size, move up a step else go to index in list.
    if (index == this->nearbyFolders.size()) {
        // If at top of cage and neighbour list is empty dont move.
        if (this->currentDir == "./Cage") { // HÅRDKODAD BUR
            return "";
        } else {
            return "..";
        }
    } else {
        auto front = this->nearbyFolders.begin();
        std::advance(front, index);
        string newPath = *front;

        // Remove everything from the path except for the name of the directory.
        newPath.erase(0, this->currentDir.size() + 1);
        return newPath;
    }
}

void Creature::kill() {
    this->self.close();
    std::remove(this->fullPath.c_str());
}