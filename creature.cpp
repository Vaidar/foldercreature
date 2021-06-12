#include "creature.h"

Creature::Creature(std::string name, std::string path) {
    this->name = name;
    this->currentDir = path;

    string temp = path;
    this->fullPath = temp.append("/").append(name).append(".creature");

    // Create file and add name
    this->self.open(this->fullPath, std::fstream::out);
    this->self << name << std::endl;
    this->self << this->currentDir << std::endl;
}

string Creature::getName() {
    return this->name;
}

string Creature::getPath() {
    return this->currentDir;
}

// När den flyttas raderas allt innehåll i filen >:(
void Creature::move(string destination) {
    this->self.close();

    string newFullPath = this->currentDir;
    newFullPath.append("/").append(destination).append("/").append(this->name).append(".creature");
    
    std::filesystem::rename(this->fullPath, newFullPath);
    
    this->fullPath = newFullPath;
    this->self.open(this->fullPath, std::fstream::out);
    if (!this->self.is_open()) {
        std::cout << "Failed to create file. :(" << std::endl;
    }

    this->currentDir = this->currentDir.append("/").append(destination);
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

void Creature::kill() {
    this->self.close();
    std::remove(this->fullPath.c_str());
}