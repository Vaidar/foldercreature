#ifndef LIFE
#define LIFE

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

class Life {
    protected:
        typedef enum {
            Grass,
            GrassEater
        } LifeFormType;

        std::string name;
        LifeFormType type;
        std::filesystem::path currentDir;
        std::filesystem::path fullPath;
        std::fstream self;

    public:
        Life(std::string name, LifeFormType type, std::filesystem::path path);

        std::string getName();
        std::string getPath();

        /**
         * This method is run on every life form every tick in the ecosystem.
         * The method should be overwritten to suit every life forms personal needs.
         */
        virtual void doAction();

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
         * Returns the file extension for this life forms type. Example: If this
         * lifeform is of the type grass the method returns ".grass".
         * 
         * @return The file extenstion for the 
         */
        std::string getFileExtensionFromLifeFormType();
};

#endif