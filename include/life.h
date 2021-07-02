#ifndef LIFE
#define LIFE

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <list>

class Life {
    public:
        typedef enum {
            Grass,
            GrassEater
        } LifeFormType;

    protected:
        std::string name;
        LifeFormType type;
        std::filesystem::path currentDir;
        std::filesystem::path fullPath;
        std::fstream self;

        std::list<std::string> nearbyFiles;
        std::list<std::string> nearbyFolders;
        
        int birthTime;
        int timeAlive; // Increase this every tick
        int actionCoolDownTime;

    private:
        int lastActionTime;

    public:
        Life(std::string name, LifeFormType type, std::filesystem::path path, int birthTime);

        std::string getName();
        LifeFormType getType();
        std::string getPath();
        bool isCoolDownOver(int currentTime);

        /**
         * This method should be called on every lifeform every tick.
         * 
         * @param time The time (tick) when the method was called.
         * @return 0 if everything went correctly. 1 if the lifeform will reproduce.
         *         -1 if the lifeform has died.
         */
        int doAction(int time);

        /**
         * Returns the path to the destination given. Destination is either a foldername or "..".
         * 
         * @param origin The path to modify.
         * @param destination The name of the directory to get the path to or ".." if the parent
         *                    directory is wanted.
         * @return A new path
         */
        std::string getNewPath(std::filesystem::path origin, std::string destination);

        /**
         * Kills the creature. Closes the fstream and removes the file. 
         */
        void kill();
    
    protected:
        /**
         * This method is called from the doAction method.The method should be overwritten 
         * to suit every lifeforms personal needs.
         * 
         * @return 0 if everything went correctly. 1 if the lifeform will reproduce.
         *         -1 if the lifeform has died. 
         */
        virtual int doSpecificActions(); // TODO: Ge den här ett bra namn!

        /**
         * Returns the file extension for this life forms type. Example: If this
         * lifeform is of the type grass the method returns ".grass".
         * 
         * @return The file extenstion for the 
         */
        std::string getFileExtensionFromLifeFormType();

        /**
         * Checks if the the lifeforms fstream still is open. If it isn't the lifeform died.
         * Should be called at the top of the lifeforms doSpecificActions().
         * 
         * @return True if fstream closed, else true.
         */
        bool checkIfDead();

        /**
         * Finds all the files and folders in the current directory
         * and adds them to the creatures lists for each type.
         */
        void getNearbyFilesAndFolders();
};

#endif