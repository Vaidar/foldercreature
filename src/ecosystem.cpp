#include "../include/ecosystem.h"

Ecosystem::Ecosystem(std::filesystem::path topDir) {
    this->topDir = topDir;
    this->time = 0;
}

void Ecosystem::tick() {
    this->time++;

    if (this->lifeForms.size() > 0) {
        for (std::list<Life*>::iterator it = this->lifeForms.begin(); it != this->lifeForms.end(); ++it){
            int value = (*it)->doAction();

            switch (value) {
                case 0:
                    break;
                case -1:
                    removeLifeFormFromList(*it);
                    (*it)->kill();
                    break;
                default:
                    throw (*it)->getName() + " performed some undefined action.";
                    break;
            }
        }
    }
}

int Ecosystem::getTime() {
    return this->time;
}

void Ecosystem::addLifeFormToList(Life* life) {
    this->lifeForms.push_back(life);
}

void Ecosystem::removeLifeFormFromList(Life* life) {
    this->lifeForms.remove(life);
}