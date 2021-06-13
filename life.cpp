#include "life.h"
#include "ecosystem.h"

Life::Life(std::string name, std::filesystem::path path) {
    this->name = name;
    this->fullPath = path;
}

std::string Life::getNewPath(std::string origin, std::string destination) {
    std::filesystem::path test = origin;

    if (destination == "..") {
        // if (origin == topDir) { // FIX: Hur ska jag nå topDir? Vem ska veta om den??
        //     return "";
        // }
        return test.parent_path();
    } else {
        std::string newPath = test;
        newPath.append("/").append(destination);
        //std::cout << newPath << std::endl;

        if (std::filesystem::exists(newPath)) {
            return newPath;
        } else {
            std::cerr << "Tried to move to nonexistent directory." << std::endl;
            return "";
        }
    }
}