#include "Brigand.hpp"

Brigand::Brigand(Joueur * joueur, Noeud * noeud) {
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
}

int Brigand::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int * score) {

    return 0;
}
