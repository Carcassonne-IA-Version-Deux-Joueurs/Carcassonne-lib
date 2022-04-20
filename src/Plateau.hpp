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
#include "Tuile.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Constantes.hpp"
#include "Logging.hpp"

// CLASSE
/**
 * Classe Plateau
 *
 * Prends en charge la gestion logique d'un plateau de jeu.
 * */
class Plateau
{
    private:
        // VARIABLES
        Tuile *grille[NBR_TUILES * 2][NBR_TUILES * 2]; // grille représentant le plateau
        std::vector<Tuile *> pioche; // la pioche
        std::list<Joueur *> list_joueur; // liste des joueurs
        std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres; // liste des emplacements libres {abscisse, ordonnée, orientation}
        std::map<Joueur *, Pion *> mapJoueursPions; // associe une pile de pions à un Joueur
        std::map<Tuile *, std::pair<int,int>> tuiles_candidates; // liste des tuiles candidates

        // METHODES
        std::list<Joueur *> rechercher_Joueur_plus_de_Pions(std::map<Joueur *, std::list<Meeple *>>mapJoueurListeMeeple);
        void desindexer_Meeple_dans_la_map(std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple);

    public:
        // CONSTRUCTEUR
        Plateau();

        // DESTRUCTEUR
        ~Plateau();

        // METHODES
        void init_plateau();
        void ajouter_joueur(Joueur * joueur, Pion * pion);
        void ajouter_tuile_pioche(Tuile * tuile);
        Joueur *get_joueur();
        std::vector<Tuile *> get_pioche();
        std::list<Joueur *> get_joueur_liste();
        std::vector<std::array<int, 3>> get_liste_tuiles_emplacements_libres();
        std::map<Tuile *,std::pair<int,int>> get_tuiles_candidates();
        
        Tuile *get_tuile_grille(int x, int y);

        Tuile *piocher_tuile();
        void calcul_emplacements_libres(Tuile *tuile);
        void poser_tuile(Tuile *tuile, std::array<int, 3> emplacement);
        void compter_points(Joueur *joueur);
        Joueur *joueur_suivant();

        void evaluer_meeple(int status_du_jeu); // évaluation des scores
        bool stack_meeple_vide(Joueur *joueur);
        void poser_meeple(Joueur *joueur, Element *element, Tuile *tuile);

        void afficher_plateau();
};

#endif
