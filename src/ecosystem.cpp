#include "../include/ecosystem.h"
#include "../include/grass.h"
#include "../include/grasseater.h"

Ecosystem::Ecosystem(std::filesystem::path topDir) {
    this->topDir = topDir;
    this->time = 0;
}

void Ecosystem::tick() {
    if (this->lifeForms.size() > 0) {
        for (std::list<Life*>::iterator it = this->lifeForms.begin(); it != this->lifeForms.end(); ++it){
            int value = (*it)->doAction(this->time);

            // Depending on what doAction returned, do things.
            switch (value) {
                case 0:
                    break;
                case 1:
                    createNewLifeForm(*it);
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

    this->time++;
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

void Ecosystem::createNewLifeForm(Life* parent) {
    std::string childName = std::to_string(rand());
    //childName.append(std::to_string(rand()));

    Life* child;

    switch (parent->getType()) {
        case Life::LifeFormType::Grass:
            child = new Grass(childName, parent->getPath(), this->time);
            break;
        case Life::LifeFormType::GrassEater:
            child = new GrassEater(childName, parent->getPath(), this->time);
            break;
        default:
            throw parent->getName() + " tried to create unknown lifeform type.";
            return;
    }

    addLifeFormToList(child);
}