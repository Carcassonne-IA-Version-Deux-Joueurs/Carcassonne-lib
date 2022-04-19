// LIBRAIRIES
#include <iostream>
#include <list>
#include <tuple>
#include <map>
#include <vector>

#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Bordure.hpp"
#include "Tuile.hpp"
#include "Constantes.hpp"
#include "BaseDeDonnees.hpp"

using namespace std;

// FONCTIONS
void afficher_elements(vector<Element *> list_element)
{

}

void afficher_liste_tuiles_emplacements_libres(vector<array<int, 3>> liste_tuiles_emplacements_libres)
{
    for(long unsigned int i = 0; i < liste_tuiles_emplacements_libres.size(); i++)
    {
        cout << "Emplacement n°" << i << " :\n" <<
        "Abscisse :\t" << liste_tuiles_emplacements_libres.at(i).at(0) <<
        "\tOrdonnée :\t" << liste_tuiles_emplacements_libres.at(i).at(1) <<
        "\tOrientation :\t" << (liste_tuiles_emplacements_libres.at(i).at(2) * 90) << "°" <<
        endl;
    }
}

// MAIN
int main()
{
    // * Initialisation du plateau
    Plateau *plateau = BaseDeDonnees::generer_plateau_vanilla();    // Instancie le plateau
    plateau->init_plateau();                                        // Init le plateau en posant la première tuile sur le plateau->(Tuile de base)

    // * Ajout des joueurs
    int nombre_de_joueurs = 2;
    vector<Joueur *> joueurs;

    joueurs.push_back(new Joueur(Joueur::HUMAIN));
    joueurs.push_back(new Joueur(Joueur::ROBOT));

    for(int i = 0; i < nombre_de_joueurs; i++)
    {
        plateau->ajouter_joueur(joueurs[i], new Pion(7));
    }

    // * Initialisation du nombre de tours
    int tour = 0;

    // Main loop
    if(plateau->get_pioche().size() > 0)
    {
        // Détermine le joueur qui doit jouer
        Joueur *joueur = joueurs[tour];
        tour = (tour + 1) % nombre_de_joueurs;

        // * Piocher une tuile
        Tuile *tuile_pioche =  plateau->piocher_tuile(); // Pioche une tuile au hasard (recupère l'addresse de la tuile) et l'enlève de la pioche
        cout << "Tuile piochée : " << tuile_pioche->getId() << endl;

        // * Chercher les emplacements libres
        plateau->calcul_emplacements_libres(tuile_pioche); // Détermine tous les emplacements possibles sur le plateau
        vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();

        // * Afficher les emplacements libres
        cout << "Choisir l'index d'un emplacement de 0 à " << liste_tuiles_emplacements_libres.size() << endl;
        afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);

        // * Choisir une case et orientation parmi celles proposées
        int index;
        cin >> index;

        // * Poser la tuile sur l'emplacement
        plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[index]);

        // * Poser un pion ?
        if(plateau->stack_meeple_vide(joueur))
        {
            cout << "Poser pions ?" << endl;
            string poser_pion;
            cin >> poser_pion;

            if(poser_pion.compare("yes"))
            {
                cout << "Choisir emplacement" << endl;
                //vector<Element *> list_element = tuile_pioche->get_element(tuile_pioche);
                //afficher_elements(list_element);
                int index;
                cin >> index;
                //plateau->poser_meeple(joueur, list_element[index], tuile_pioche); // Permet au joueur de placer un pion sur la tuile
            }
        }

        // * compter les points
        plateau->evaluer_meeple(STATUS_EN_COURS); // Compte les points totalisés par les meaples mis en jeu si il y a lieu
    }

    // Compte les derniers points de fin de partie
    list<Joueur *> list_joueur = plateau->get_joueur_liste();
    list<Joueur *>::iterator it;

    plateau->evaluer_meeple(STATUS_FINAL);
    
    for(it = list_joueur.begin(); it != list_joueur.end(); ++it)
    {
        cout << "Joueur " << (*it)->get_type_joueur() << " a obtenu " << (*it)->get_score();
    }

    return 0;
}