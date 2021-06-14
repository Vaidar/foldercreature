#ifndef CREATURE
#define CREATURE

#include "life.h"
#include <list>

class Creature: public Life {
    private:
        std::list<std::string> nearbyFiles;
        std::list<std::string> nearbyFolders;

    public:
        Creature(std::string name, std::string path);
        
        /**
         * Moves the creature one directory further up or down the tree.
         * The parameter destination is the name of the directory to move the creature to.
         * If the creature should move a step up the tree the destination should be "..".
         */
        void move();
        void eat(std::string file);

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
         *         moving the creature one directory up or an empty std::string if no option was found.
         */
        std::string chooseNewDestination();
};

#endif