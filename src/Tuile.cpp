// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
/**
 * @title: Constructeur de la Tuile
 *
 * @param: id est l'identifiant de la tuile depuis la base de données
 * @param: bordure est la bordure de la tuile 
 * @param: element est l'ensemble des éléments que compose la tuile
 * */
Tuile::Tuile(int id, std::array<Bordure *, 4> bordure, std::vector<Element *> element)
{
    this->id = id;
    this->bordure = bordure;
    this->element = element;
}


Tuile::Tuile(const Tuile & tuile)
{
    this->id = tuile.id; 
    this->bordure = tuile.bordure;
    this->element = tuile.element;
}

Tuile::~Tuile()
{
    for(Element * element : this->element)
    {
        delete element;
    }
    for(int i = 0; i < 4; i++) 
    {
        if(this->bordure[i] != nullptr)
        {
            // Logging::log(Logging::TRACE, "delete bordure %d", bordure[i]);
            delete this->bordure[i];
        }
    }
}

/**
 * @title: Récupère l'id de la tuile
 * */
int Tuile::get_id()
{
    return this->id;
}

/**
 * @title: Fait une rotation logique horaire de la tuile
 * */
void Tuile::rotationHoraire()
{
    Bordure *tmp = this->bordure[0];
    
    int k = 3;
    
    for(int i = 0; i < (NBR_ORIENTATIONS_TUILES - 1); i++)
    {
        this->bordure[(k + 1) % 4] = this->bordure[(k) % 4];
        k--;
    }

    this->bordure[1] = tmp;
}

/**
 * @title: Récupère la bordure fils
 * 
 * @return: bordure fils
 * */
Bordure * Tuile::getBordure(int cote) 
{
    return this->bordure[cote];
}

/**
 * @title: Récupère les éléments de la tuile
 * 
 * @return: les éléments
 * */
const std::vector<Element *> Tuile::getElements() {
    return this->element;
}