#ifndef ECOSYSTEM
#define ECOSYSTEM

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

// Ja tänker att denna klassen har regler för ekosystemet, typ högsta directoryt
// å andra parametrar som påverkar hela systemet. Klassen life ska ha grundstenarna
// för själva livet. Superklass till allt liv.
class EcoSystem {
    private:
        // topDir represents the top of the cage, nothing outside this dir
        static std::filesystem::path topDir;

    public:
        EcoSystem(std::filesystem::path topDir);
};

#endif