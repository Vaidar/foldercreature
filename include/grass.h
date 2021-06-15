#ifndef GRASS
#define GRASS

#include "../include/life.h"

class Grass: public Life {
    public:
        Grass(std::string name, std::string path);

    private:
        virtual void doAction() override;
};

#endif