#include "../include/grasseater.h"

GrassEater::GrassEater(std::string name, std::string path) : Creature(name, LifeFormType::GrassEater, path) {

}

void GrassEater::doAction() {
    std::cout << "Grasseater override!!!" << std::endl;
    this->move();
    this->eat();
}

void GrassEater::eat() {
    getNearbyFilesAndFolders();

    for (auto const& i : nearbyFiles) {
        size_t test = i.find_last_of(".");
        if (i.substr(test + 1) == "grass") {
            // Detta funkar men hur ska den här klassen kunna ta bort gräset?
            
            // Jag har ju pathen till filen som ska bort men instansen av klassen gräs som
            // är kopplad till denna gräsfil måste också försvinna. Hur?

            break; // Only eat one grass
        }
    }
}