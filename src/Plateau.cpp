// LIBRAIRIES
#include "Plateau.hpp"

// FONCTIONS
Plateau::Plateau()
{
    Logging::log(Logging::TRACE, "Création du plateau");
}

Plateau::~Plateau()
{}

void Plateau::init_plateau()
{
    Logging::log(Logging::TRACE, "Chargement de la base de données");

    for(int i = 0; i < (NBR_TUILES * 2); i++)
    {
        for(int j = 0; j < (NBR_TUILES * 2); j++)
        {
            this->grille[i][j] = nullptr;
        }
    }
   
    Logging::log(Logging::DEBUG, "Ajout de la Tuile de base au plateau %d ", pioche[0]);
    
    //this->grille[NBR_TUILES-1][NBR_TUILES-1] = pioche[0];
    std::array<int, 3> coord = {NBR_TUILES-1, NBR_TUILES-1, 0};
    this->poser_tuile(pioche[0], coord);
    pioche.erase(pioche.begin());
}

void Plateau::ajouter_joueur(Joueur * joueur, Pion * pion)
{
    this->mapJoueursPions.insert(std::pair<Joueur *, Pion *>(joueur, pion));
}

Joueur * Plateau::get_joueur()
{
    return nullptr;
}

std::vector<Tuile *> Plateau::get_pioche()
{
    return this->pioche;
}

Tuile *Plateau::piocher_tuile()
{
    srand(time(NULL));
	int random = rand() % this->pioche.size();
    Logging::log(Logging::TRACE, "Pioche la tuile %d", random);

	Tuile *tuile = this->pioche[random];
	pioche.erase(pioche.begin() + random);

    return tuile;
}

Tuile *Plateau::get_tuile_grille(int x, int y)
{
    return this->grille[x][y];
}

void Plateau::calcul_emplacements_libres(Tuile *tuile)
{
    Logging::log(Logging::TRACE, "Tuile = %d", tuile->getId());
    // On parcourt la liste des emplacements candidates
    for(auto tuile_candidate : this->tuiles_candidates) 
    {
        std::pair<int, int> emplacement = tuile_candidate.second;
        Logging::log(Logging::DEBUG, "Tuile candidates : <%d,%d> %d", emplacement.first, emplacement.second, tuile_candidate.first->getId());
        std::array<std::pair<int,int>, 4> tuile_coords_voisines = {
            std::make_pair(emplacement.first, emplacement.second + 1),
            std::make_pair(emplacement.first + 1, emplacement.second),
            std::make_pair(emplacement.first, emplacement.second - 1),
            std::make_pair(emplacement.first - 1, emplacement.second)
        };
        
        int bordure_voisines = 2;
        int bordure_tuiles = 0;


        for(int i = 0; i < 4; i++)  // on tourne la carte 
        {
            bool est_compatible = true; // permet de savoir si c'est compatible 
            
            for(auto tuile_coord_voisine : tuile_coords_voisines)
            {
            
                Tuile * tuile_voisine = this->grille[tuile_coord_voisine.first][tuile_coord_voisine.second];
                if(tuile_voisine != nullptr)
                {
                    if(tuile_voisine->getId() != -1)
                    {

                        //Logging::log(Logging::DEBUG, "Tuile voisine %d", tuile_voisine->getId());
                        //Logging::log(Logging::DEBUG, "Comparaison des bordures voisines <%d==%d> ", bordure_voisines, bordure_tuiles);
                         
                        Bordure * bordure_voisine = tuile_voisine->getBordure(bordure_voisines);
                        Bordure * bordure_tuile = tuile->getBordure(bordure_tuiles);
                        if(bordure_voisine == nullptr) {
                            Logging::log(Logging::DEBUG, "bordure voisine null");
                        }
                        if(bordure_tuile == nullptr) {
                            Logging::log(Logging::DEBUG, "bordure tuile null");
                        }
                        for(int k = 0; k < 3; k++) 
                        {
                            //Logging::log(Logging::DEBUG, "Tuile voisine bordure %d", bordure_voisine->get_bordure_fils(k)->get_type_element());
                            //Logging::log(Logging::DEBUG, "Tuile bordure Tuile pioche %d", bordure_tuile->get_bordure_fils(k)->get_type_element());
                            if(bordure_voisine->get_bordure_fils(k)->get_type_element() != bordure_tuile->get_bordure_fils(k)->get_type_element())
                            {
                                est_compatible = false;
                            }
                        }
                    } else {
                        /*
                        Bordure * bordure_tuile = tuile->getBordure(bordure_tuiles);
                        for(int k = 0; k < 3; k++) 
                        {
                            Logging::log(Logging::DEBUG, "Tuile bordure %d", bordure_tuile->get_bordure_fils(k)->get_type_element());
                        }
                        */
                    }
                    bordure_voisines = (1 + bordure_voisines) % 4;
                    bordure_tuiles = (1 + bordure_tuiles) % 4;
                }
            }
            if(est_compatible)
            {
                std::array<int, 3> emplacement_libre = {emplacement.first, emplacement.second, i};
                this->liste_tuiles_emplacements_libres.push_back(emplacement_libre);
                Logging::log(Logging::DEBUG, "ajout de l'emplacement libre <%d,%d,%d>", emplacement_libre.at(0), emplacement_libre.at(1), emplacement_libre.at(2));
            }
            tuile->rotationHoraire();
            Logging::log(Logging::DEBUG, "on tourne la carte"); 
        }   
        Logging::log(Logging::DEBUG, "on change d'emplacement");
    }
}

void Plateau::poser_tuile(Tuile *tuile, std::array<int, 3> emplacement)
{
    for(int i = 0; i < emplacement.at(2); i++)
    {
        tuile->rotationHoraire();
    }
    
    if(this->grille[emplacement.at(0)][emplacement.at(1)] != nullptr) {
        Tuile * tuile_a_suppr = this->grille[emplacement.at(0)][emplacement.at(1)];
        Logging::log(Logging::DEBUG, "supprime tuile %d : <%d %d>", tuile_a_suppr, emplacement.at(0), emplacement.at(1));
        this->tuiles_candidates.erase(tuile_a_suppr);
        this->grille[emplacement.at(0)][emplacement.at(1)] = nullptr;
    }

    this->grille[emplacement.at(0)][emplacement.at(1)] = tuile;

    std::array<std::pair<int,int>, 4> tuile_voisines = {
        std::make_pair(emplacement.at(0), emplacement.at(1) + 1),
        std::make_pair(emplacement.at(0) + 1, emplacement.at(1)),
        std::make_pair(emplacement.at(0), emplacement.at(1) - 1),
        std::make_pair(emplacement.at(0) - 1, emplacement.at(1))
    };

    for(auto tuile_voisine : tuile_voisines)
    {
        if(this->grille[tuile_voisine.first][tuile_voisine.second] == nullptr)
        {
            std::array<Bordure *, 4> bordure_tmp;
            std::list<Element *> element_tmp;
            Tuile * tuile_candidate = new Tuile(-1, bordure_tmp, element_tmp);
            this->grille[tuile_voisine.first][tuile_voisine.second] = tuile_candidate;
            this->tuiles_candidates[tuile_candidate] = std::make_pair(tuile_voisine.first,tuile_voisine.second);
        }
    }
}

Joueur *Plateau::joueur_suivant()
{
    return nullptr;
}

/**
 * Recherche le Joueur qui à obtenue le plus de pions.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple
 * */
std::list<Joueur *> Plateau::rechercher_Joueur_plus_de_Pions(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{
    std::list<Joueur *> list_joueur;
    int max = 0;
    for(auto const & joueur : mapJoueurListeMeeple)
    {
        int tmp = joueur.second.size();
        if(max < tmp) {
            max = tmp;
        }
    }

    for(auto const & joueur : this->mapJoueursPions)
    {
        int tmp = joueur.second->get_stack_meeple().size();
        if(tmp == max)
        {
            list_joueur.push_back(joueur.first);
        }
    }

    if(list_joueur.empty())
    {
        //Logging::DEBUG("Attention il y pas de joueur qui reçoit les points lors de l'évaluation");
    }
    return list_joueur;
}

/**
 * Désindexe les Meeples du plateau.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple */
void Plateau::desindexer_Meeple_dans_la_map(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{
    for(auto const & itMap : mapJoueurListeMeeple)
    {
        Joueur * joueur = itMap.first;
        for(auto const &meeple : itMap.second)
        {
            this->mapJoueursPions.at(joueur)->supprimer_meeple(meeple);
        }
    }
}

/**
 * Evaluation des Meeples pour chaque Joueurs
 *
 * Cette méthode permet d'à partir de chaque Meeple des Joueurs d'évaluer s'il y a possibilité d'attribuer des points aux Joueurs
 * L'évaluation s'effectue sur tous les Meeples et les points sont distribuée selon la quantité de Meeple obtenu (pour l'évalation concurrencielle, ce n'est pas le cas pour les abbayes par exemple)
 *
 * @param status_du_jeu permet de faire une évaluation soit final soit en cours du jeu
 * */
void Plateau::evaluer_meeple(int status_du_jeu)
{
    for(auto const &itMap : this->mapJoueursPions)
    {
        const std::list<Meeple *> listMeeple = itMap.second->get_stack_meeple();

        for(auto const &itMeeple : listMeeple)
        {
            int score = 0;
            std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple; // Associe un joueur et une pile de pions
            int est_tuileComparelet = itMeeple->compter_points(status_du_jeu, & mapJoueurListeMeeple, &score);

            if(est_tuileComparelet == true || status_du_jeu )
            {
                std::list<Joueur *> list_joueur_max;
                list_joueur_max = this->rechercher_Joueur_plus_de_Pions(mapJoueurListeMeeple);// problème: en cas d'égalité
                for(auto const & joueur : list_joueur_max)
                {
                    joueur->add_score(score);
                    // Logging
                }
                this->desindexer_Meeple_dans_la_map(mapJoueurListeMeeple);
            }
        }
    }
}

std::list<Joueur *> Plateau::get_joueur_liste()
{
    return this->list_joueur;
}

std::vector<std::array<int, 3>> Plateau::get_liste_tuiles_emplacements_libres()
{
    return this->liste_tuiles_emplacements_libres;
}

bool Plateau::stack_meeple_vide(Joueur * joueur)
{
    return this->mapJoueursPions.at(joueur)->si_pion_non_place();
}

/**
 * Permet de poser un meeple
 *
 * @return bool si le meeple peut être posé|     pioche.erase(0);
 * */
void Plateau::poser_meeple(Joueur * joueur, Element *elem, Tuile * tuile)
{
    Meeple * meeple = Pion::generate_meeple(joueur, elem, tuile);
    elem->ajouter_meeple(meeple);
    Pion * pion = this->mapJoueursPions.at(joueur);
    pion->ajouter_meeple(meeple);
}

void Plateau::ajouter_tuile_pioche(Tuile *tuile)
{
    this->pioche.push_back(tuile);
}

std::map<Tuile *, std::pair<int,int>> Plateau::get_tuiles_candidates() 
{
    return this->tuiles_candidates;
}

void Plateau::afficher_plateau() {
    for(int i = 0; i < 144; i++) 
    {
        for(int j = 0; j < 144; j++) 
        {
            if(grille[i][j] != nullptr)
            {
                std::cout << "coords (" << 71 - i << "," << 71 - j << ")" << grille[i][j]->getId() << std::endl;
            }
        }
    }
}
