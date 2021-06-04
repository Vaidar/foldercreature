#include "creature.h"

Creature::Creature(std::string name, std::string path) {
    this->name = name;
    this->path = path;
}

string Creature::getName() {
    return this->name;
}

string Creature::getPath() {
    return this->path;
}

// std::fstream Creature::getSelf() {
//     return this->self;
// }

void Creature::move(string destination) {
    getNearbyFiles(this->nearbyFiles);
}

void Creature::eat(string file) {

}

void Creature::getNearbyFiles(std::list<string> nearbyFiles) {
    for (const auto & entry : std::filesystem::directory_iterator(this->path)) {
        std::cout << entry.path() << std::endl;
        nearbyFiles.push_back(entry.path().string());
    }
}

void Creature::getNearbyFolders(std::list<string> nearbyFolders) {

}