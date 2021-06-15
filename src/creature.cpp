#include "../include/creature.h"

Creature::Creature(std::string name, std::string path) : Life(name, path) {
    std::string temp = path;
    this->fullPath = temp.append("/").append(this->name).append(".creature");

    // Create file
    this->self.open(this->fullPath, std::fstream::out);
    if (!this->self.is_open()) {
        std::cout << "Failed to create file. :(" << std::endl;
    }

    this->self << name << std::endl;
    this->self << this->currentDir << std::endl;

    getNearbyFilesAndFolders();
    srand(time(NULL));
}

void Creature::doAction() {
    std::cout << "Is it overwritten???" << std::endl;
    this->move();
}

void Creature::move() { // TODO: Flytta över mesta av koden här till ny fysik/filehandler klass.
    this->self.close();
    std::string destination = chooseNewDestination();
    if (destination == "") {
        return;
    }

    // Get the path to the new directory
    std::string newFullPath = getNewPath(this->currentDir, destination);
    this->currentDir = newFullPath;

    newFullPath.append("/").append(this->name).append(".creature");

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

void Creature::eat(std::string file) {

}

void Creature::getNearbyFilesAndFolders() {
    std::string tempName = this->name;
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

std::string Creature::chooseNewDestination() {
    int index = rand() % (this->nearbyFolders.size() + 1);

    // If index same as size, move up a step else go to index in list.
    if (index == this->nearbyFolders.size()) {
        // If at top of cage and neighbour list is empty dont move.
        if (this->currentDir == "./Cage") { // TODO: Ta bort hårdkodad bur
            return "";
        } else {
            return "..";
        }
    } else {
        auto front = this->nearbyFolders.begin();
        std::advance(front, index);
        std::string newPath = *front;

        // Remove everything from the path except for the name of the directory.
        newPath.erase(0, this->currentDir.string().size() + 1);
        return newPath;
    }
}