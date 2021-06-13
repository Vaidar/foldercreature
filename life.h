#ifndef LIFE
#define LIFE

#include <iostream>
#include <string>
#include <filesystem>

class Life {
    protected:
        std::string name;
        std::filesystem::path fullPath;

    public:
        Life(std::string name, std::filesystem::path path);
        void doAction();
        std::string getNewPath(std::string origin, std::string destination);
};

#endif