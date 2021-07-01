#ifndef CREATURE
#define CREATURE

#include "life.h"

/**
 * The parent class to all animal-like life forms.
 * 
 * Contains protected methods that all animal-like life forms
 * needs, for example the methods move() and eat(). The move
 * method is implemented by this class but can be overwritten
 * if needed.
 */
class Creature: public Life {
    public:
        Creature(std::string name, LifeFormType type, std::string path);
        virtual int doAction() override;

    protected:
        /**
         * Moves the creature one directory further up or down the tree.
         * The parameter destination is the name of the directory to move the creature to.
         * If the creature should move a step up the tree the destination should be "..".
         */
        virtual void move();
        
        virtual void eat();
        void devourFile(std::string file);

        /**
         * Randomly selects neighbouring directory to move the creature to inside its cage.
         * 
         * @return Either the name of the directory to move the creature to, ".." representing
         *         moving the creature one directory up or an empty std::string if no option was found.
         */
        std::string chooseNewDestination();
};

#endif