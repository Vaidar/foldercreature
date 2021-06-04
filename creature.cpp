#include "creature.h"

Creature::Creature(std::string name, std::string path) {
    this->name = name;
    this->currentDir = path;
    this->fullPath = path.append("\\").append(name).append(".creature");

    // Create file and add name
    this->self.open(this->fullPath, std::fstream::out);
    this->self << name << std::endl;
}

string Creature::getName() {
    return this->name;
}

string Creature::getPath() {
    return this->currentDir;
}

void Creature::move(string destination) {
    //this->self.close();
    std::filesystem::rename(this->fullPath, "F:\\Hackerfolder\\Cpp-things\\foldercreature\\Cage\\1\\1-2");
    getNearbyFilesAndFolders();
}

void Creature::eat(string file) {

}

void Creature::getNearbyFilesAndFolders() {
    for (const auto & entry : std::filesystem::directory_iterator(this->currentDir)) {
        if (entry.is_directory()) {
            this->nearbyFolders.push_back(entry.path().string());
        } else {
            this->nearbyFiles.push_back(entry.path().string());
        }
    }
}