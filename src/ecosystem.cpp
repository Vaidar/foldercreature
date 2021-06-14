#include "../include/ecosystem.h"

EcoSystem::EcoSystem(std::filesystem::path topDir) {
    this->topDir = topDir;
    this->time = 0;
}

void EcoSystem::tick() {
    this->time++;

    if (this->lifeForms.size() > 0) {
        for (std::list<Life>::iterator it = this->lifeForms.begin(); it != this->lifeForms.end(); ++it){
            //it->doAction(); // FIX: UNDEFINED REFERENCE ajg inte fortstor :((
        }

        // FIX: Varför funkar inte den här typen av loop?
        // for (auto& i : this->lifeForms) {
        //     i->doAction();
        // }
    }
}