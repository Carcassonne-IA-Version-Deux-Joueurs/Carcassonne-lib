// LIBRAIRIES
#include "Chevalier.hpp"

// FONCTIONS
Chevalier::Chevalier(Joueur * joueur, Noeud * noeud)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
}

Chevalier::~Chevalier()
{}

int Chevalier::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int * score)
{
    return false;
}