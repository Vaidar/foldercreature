#include "../include/ecosystem.h"

Ecosystem::Ecosystem(std::filesystem::path topDir) {
    this->topDir = topDir;
    this->time = 0;
}

void Ecosystem::tick() {
    this->time++;

    if (this->lifeForms.size() > 0) {
        for (std::list<Life*>::iterator it = this->lifeForms.begin(); it != this->lifeForms.end(); ++it){
            (*it)->doAction();
        }
    }
}

void Ecosystem::addLifeFormToList(Life* life) {
    this->lifeForms.push_back(life);
}