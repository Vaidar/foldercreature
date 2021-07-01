#ifndef GRASSEATER
#define GRASSEATER

#include "creature.h"

class GrassEater: public Creature {
    public:
        GrassEater(std::string name, std::string path);
        virtual int doAction() override;

    protected:
        virtual void eat() override;
};

#endif