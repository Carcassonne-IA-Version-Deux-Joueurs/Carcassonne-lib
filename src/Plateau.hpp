// DIRECTIVES
#ifndef PLATEAU_HPP
#define PLATEAU_HPP

// LIBRAIRIES
#include <list>
#include <array>
#include <map>
#include <vector>
#include <string>

#include "Bordure.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Constantes.hpp"
#include "Logging.hpp"

/**
 * Classe Plateau
 *
 * Prends en charge la gestion logique d'un plateau de jeu.
 * */
class Plateau
{
    private:
        // VARIABLES
        std::list<Carte *> pioche; // la pioche
        std::list<Joueur *> list_joueur; // liste des joueurs
        std::map<Carte *, std::list<Bordure *>> map_emplacement_possible; // stock les emplacements libre
        Carte * carte_depart; // case de depart (graphe connexe)
        std::map<Joueur* , Pion *> mapJoueursPions; // associe une pile de pions à un Joueur

        // METHODES
        Joueur * rechercher_Joueur_plus_de_Pions(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple);
        void desindexer_Meeple_dans_la_map(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple);

    public:
        // CONSTRUCTEUR
        Plateau();

        // DESTRUCTEUR
        ~Plateau();

        // METHODES
        void charger_donnee(std::string path);
        void init_plateau();
        void ajouter_joueur(Joueur * joueur, Pion * pion);

        Joueur * get_joueur();
        std::list<Carte*> get_pioche();
        std::list<Joueur * > get_joueur_liste();
        std::vector<Carte *> get_list_carte_emplacement_libre();
        std::vector<std::list<Bordure* >> get_orientation_possible(Carte * carte);

        Carte * piocher_carte();
        void calcul_emplacement_libre(Carte * carte);
        void poser_carte(Carte * emplacement, Carte * carte, std::list<Bordure *> bordure);
        void compter_points(Joueur * joueur);
        Joueur * joueur_suivant();

        void evaluer_meeple(int status_du_jeu); // évaluation des scores
        bool stack_meeple_vide(Joueur * joueur);
        void poser_meeple(Joueur * joueur, Element * element, Carte * carte);
};

#endif
