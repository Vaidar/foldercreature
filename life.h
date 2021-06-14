#ifndef LIFE
#define LIFE

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

class Life {
    protected:
        std::string name;
        std::filesystem::path currentDir;
        std::filesystem::path fullPath;
        std::fstream self;

    public:
        Life(std::string name, std::filesystem::path path);
        std::string getName();
        std::string getPath();
        void doAction();
        std::string getNewPath(std::string origin, std::string destination);

        /**
         * Kills the creature. Closes the fstream and removes the .creature file. 
         */
        void kill();
};

#endif