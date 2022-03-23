// DIRECTIVES
#ifndef NOEUD_HPP
#define NOEUD_HPP

// LIBRAIRIES
#include <list>
#include <algorithm>

#include "Logging.hpp"

/**
 * Classe Noeud
 *
 * Permet de faire l'interface pour le pacours de la couche 'noeud'.
 * La couche 'noeud' est un réseau constitué d'élément de bordure indistingable lors de parcours du réseau.
 * Un noeuds peut être de plusieurs type, comme une route, une ville, une plaine ou bien une abbaye.
 * */
class Noeud
{
    public:
        // VARIABLES
        static enum type_element{ROUTE, VILLE, VILLE_BLASON, ABBAYE, PLAINE} element_enum;

    protected:
        std::list<Noeud *> noeuds_voisins;
        type_element element;
        int point_en_cours;
        int point_final;
        Noeud();

    public:
         // CONSTRUCTEURS
        // DESTRUCTEUR
        ~Noeud();

        // METHODES
        void set_lien(Noeud * noeud);   // ajoute un lien simple
        void set_voisin(Noeud * noeud); // ajoute un lien voisin
        virtual int get_points(int status_du_jeu) { return 0;};
        virtual void supprimer_meeple();

        bool has_nullptr();
        int get_nbr_voisins();
        Noeud::type_element get_type_element();
        void set_type_element(Noeud::type_element type);
        Noeud * noeud_fils(Noeud * noeud_pere, int indexe);
};

#endif
