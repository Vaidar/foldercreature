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
        
        /**
         * Moves the creature one directory further up or down the tree.
         * The parameter destination is the name of the directory to move the creature to.
         * If the creature should move a step up the tree the destination should be "..".
         */
        void move();
        void eat(string file);

        /**
         * Kills the creature. Closes the fstream and removes the .creature file. 
         */
        void kill();

    private:
        /**
         * Finds all the files and folders in the current directory
         * and adds them to the creatures lists for each type.
         */
        void getNearbyFilesAndFolders();

        /**
         * Randomly selects neighbouring directory to move the creature to inside its cage.
         * 
         * @return Either the name of the directory to move the creature to, ".." representing
         *         moving the creature one directory up or an empty string if no option was found.
         */
        string chooseNewDestination();
};

#endif