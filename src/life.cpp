#include "../include/life.h"
#include "../include/ecosystem.h"

Life::Life(std::string name, std::filesystem::path path) {
    this->name = name;
    this->currentDir = path;
}

std::string Life::getName() {
    return this->name;
}

std::string Life::getPath() {
    return this->currentDir.string();
}

// Override this method in all life subclasses.
void Life::doAction() {
    std::cout << this->name << " did its action." << std::endl;
}

std::string Life::getNewPath(std::filesystem::path origin, std::string destination) {
    std::filesystem::path test = origin;

    if (destination == "..") {
        // if (origin == topDir) { // FIX: Hur ska jag nå topDir? Vem ska veta om den??
        //     return "";
        // }
        return test.parent_path().string();
    } else {
        std::string newPath = test.string();
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

void Life::kill() {
    this->self.close();
    std::string temp = this->fullPath.string(); // BUG: Varför krävs det här mellansteget wtf
    remove(temp.c_str());
}