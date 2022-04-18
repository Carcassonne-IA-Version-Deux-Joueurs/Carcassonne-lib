// DIRECTIVES
#ifndef TUILE_HPP
#define TUILE_HPP

// LIBRAIRIES
#include <array>
#include <list>
#include <vector>

#include "Bordure.hpp"
#include "Element.hpp"

// CLASSE
class Tuile
{
    private:
        // VARIABLES
        std::array<Bordure *, 4> bordure;
        std::list<Element *> element;

    public:
        // CONSTRUCTEURS
        Tuile(std::array<Bordure *, 4> bordure, std::list<Element *> element);

        // DESTRUCTEUR
        ~Tuile();

        // METHODES
        void rotationHoraire();
        bool borduresCompatibles(Tuile *tuileCompare, int cote);
};

#endif