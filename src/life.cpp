#include "../include/life.h"

Life::Life(std::string name, LifeFormType type, std::filesystem::path path, int birthTime) {
    this->name = name;
    this->type = type;
    this->currentDir = path;
    this->birthTime = birthTime;

    std::string temp = path;
    std::string fileExtension = getFileExtensionFromLifeFormType();
    this->fullPath = temp.append("/").append(this->name).append(fileExtension);

    // Create file
    this->self.open(this->fullPath, std::fstream::out);
    if (!this->self.is_open()) {
        std::cout << "Failed to create file. :(" << std::endl;
    }
}

std::string Life::getName() {
    return this->name;
}

Life::LifeFormType Life::getType() {
    return this->type;
}

std::string Life::getPath() {
    return this->currentDir.string();
}

bool Life::isCoolDownOver(int currentTime) {
    return (currentTime - this->lastActionTime) >= this->actionCoolDownTime;
}

int Life::doAction(int time) {
    this->timeAlive++;

    if (isCoolDownOver(time)) {
        this->lastActionTime = time;

        // This value can be changed in doSpecificActions() if you want another cooldowntime.
        this->actionCoolDownTime = rand() % 10;
        return doSpecificActions();
    } else {
        return 0;
    }
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

// Override this method in all life subclasses.
int Life::doSpecificActions() {
    if (checkIfDead()) {
        return -1;
    }

    throw "doSpecificActions called in base class. Not good.";
    return 0;
}

std::string Life::getFileExtensionFromLifeFormType() {
    switch (this->type) {
        case Grass:
            return ".grass";
        case GrassEater:
            return ".grasseater";
        default:
            throw "Bad life form type!";
    }
}

bool Life::checkIfDead() {
    return !this->self.is_open();
}

void Life::getNearbyFilesAndFolders() {
    std::string tempName = this->name;
    tempName.append(getFileExtensionFromLifeFormType());

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