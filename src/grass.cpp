#include "../include/grass.h"

Grass::Grass(std::string name, std::string path) : Life(name, LifeFormType::Grass, path) {
    this->self << this->name << std::endl;
    this->self << this->currentDir << std::endl;
}

void Grass::doAction() {
    std::cout << "Grass override!" << std::endl;
}