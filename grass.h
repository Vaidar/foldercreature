#ifndef GRASS
#define GRASS

#include "life.h"

class Grass: public Life {
    public:
        Grass(std::string name, std::string path);
};

#endif