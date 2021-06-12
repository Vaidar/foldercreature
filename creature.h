#ifndef CREATURE
#define CREATURE

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <list>

using std::string;

class Creature {
    private:
        string name;
        string currentDir;
        string fullPath;
        std::fstream self;
        std::list<string> nearbyFiles;
        std::list<string> nearbyFolders;

    public:
        Creature(string name, string path);
        string getName();
        string getPath();
        //std::fstream getSelf(); hur?
        void move(string destination);
        void eat(string file);
        void kill();

    private:
        void getNearbyFilesAndFolders();
};

#endif