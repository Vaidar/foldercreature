#ifndef GRASS
#define GRASS

#include "life.h"

class Grass: public Life {
    private:
        int grassLimit;

    public:
        Grass(std::string name, std::string path, int birthTime);

    private:
        virtual int doSpecificActions() override;
        bool reproduce();
};

#endif