// DIRECTIVES
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// LIBRAIRIES
#include "Noeud.hpp"
#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Constantes.hpp"
#include <utility>

/**
 * Classe Element
 *
 * Hérite de la classe Noeud et permet de représenter les emplacements ou l'on pose un Pion.
 * */
class Element : public Noeud
{
    private:
        // VARIABLES
        Meeple * meeple;
        std::pair<float,float> coordonnees;

    public:
        // CONSTRUCTEURS
        Element(Noeud::type_element type_noeud, std::pair<float,float> coordonnees);

        // DESTRUCTEUR
        ~Element();

        // METHODES
        Meeple * get_meeple();
        void supprimer_meeple() override;
        void set_point(int point, int i);
        void ajouter_meeple(Meeple * meeple);
        int get_points(int status_du_jeu);
        const std::pair<float, float> get_coords();
};

#endif
