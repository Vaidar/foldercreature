#include "../include/ecosystem.h"

EcoSystem::EcoSystem(std::filesystem::path topDir) {
    this->topDir = topDir;
    this->time = 0;
}

void EcoSystem::tick() {
    this->time++;

    if (this->lifeForms.size() > 0) {
        for (std::list<Life*>::iterator it = this->lifeForms.begin(); it != this->lifeForms.end(); ++it){
            (*it)->doAction();
        }
    }
}

void EcoSystem::addLifeFormToList(Life* life) {
    this->lifeForms.push_back(life);
}