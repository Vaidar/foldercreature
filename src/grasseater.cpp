#include "../include/grasseater.h"

GrassEater::GrassEater(std::string name, std::string path) : Creature(name, LifeFormType::GrassEater, path) {

}

int GrassEater::doAction() {
    if (checkIfDead()) {
        return -1;
    }

    std::cout << this->currentDir << std::endl;
    this->move();
    this->eat();

    return 0;
}

void GrassEater::eat() {
    getNearbyFilesAndFolders();

    for (auto const& i : nearbyFiles) {
        size_t test = i.find_last_of(".");
        if (i.substr(test + 1) == "grass") {
            devourFile(i);
            this->self << "Ate: " << i << std::endl;
            break; // Only eat one grass
        }
    }
}