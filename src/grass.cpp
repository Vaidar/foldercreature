#include "../include/grass.h"

Grass::Grass(std::string name, std::string path) : Life(name, path) {
    std::string temp = path;
    this->fullPath = temp.append("/").append(this->name).append(".grass");

    this->self.open(this->fullPath, std::fstream::out);
    if (!this->self.is_open()) {
        std::cout << "Failed to create file. :(" << std::endl;
    }

    this->self << this->name << std::endl;
    this->self << this->currentDir << std::endl;
}