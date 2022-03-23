#include "BaseDeDonnees.hpp"

Plateau * BaseDeDonnees::generer_plateau_vanilla()
{
    Plateau * plateau = new Plateau();
    // Tuile 1 (x4)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element3);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element4);

            bordure[2]->get_bordure_fils(1)->set_voisin(element4);

            bordure[3]->get_bordure_fils(0)->set_voisin(element4);
            bordure[3]->get_bordure_fils(1)->set_voisin(element2);
            bordure[3]->get_bordure_fils(2)->set_voisin(element3);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[3]->get_bordure_fils(0));

            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(1));
            element4->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // AJOUT de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 2 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element3);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element4);

            bordure[2]->get_bordure_fils(0)->set_voisin(element4);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element3);

            bordure[3]->get_bordure_fils(1)->set_voisin(element4);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[2]->get_bordure_fils(2));
            element3->set_voisin(bordure[3]->get_bordure_fils(1));

            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte);
	}
    }
    }

    // Tuile 3 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element3);

            bordure[2]->get_bordure_fils(0)->set_voisin(element3);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element4);

            bordure[3]->get_bordure_fils(0)->set_voisin(element4);
            bordure[3]->get_bordure_fils(1)->set_voisin(element2);
            bordure[3]->get_bordure_fils(2)->set_voisin(element3);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(1));
            element3->set_voisin(bordure[2]->get_bordure_fils(0));
            element3->set_voisin(bordure[3]->get_bordure_fils(2));

            element4->set_voisin(bordure[2]->get_bordure_fils(2));
            element4->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 4 (x5)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_5 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element2);

            bordure[2]->get_bordure_fils(1)->set_voisin(element2);

            bordure[3]->get_bordure_fils(1)->set_voisin(element2);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 5 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::VILLE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::PLAINE);
            Element * element3 = new Element(Noeud::VILLE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element2);

            bordure[2]->get_bordure_fils(1)->set_voisin(element3);

            bordure[3]->get_bordure_fils(1)->set_voisin(element2);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            element2->set_lien(element3);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 6 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::VILLE);
            Element * element3 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element2);

            bordure[2]->get_bordure_fils(1)->set_voisin(element3);

            bordure[3]->get_bordure_fils(1)->set_voisin(element3);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));
            element3->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element3->set_lien(element1);
            element3->set_lien(element2);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 7 (x8)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_8 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element1);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element3);

            bordure[2]->get_bordure_fils(1)->set_voisin(element3);

            bordure[3]->get_bordure_fils(0)->set_voisin(element3);
            bordure[3]->get_bordure_fils(1)->set_voisin(element2);
            bordure[3]->get_bordure_fils(2)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(0));
            element1->set_voisin(bordure[3]->get_bordure_fils(2));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(2));
            element3->set_voisin(bordure[2]->get_bordure_fils(1));
            element3->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionelles
            // Aucun

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 8 (x9)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_9 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);

            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element1);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element3);

            bordure[2]->get_bordure_fils(0)->set_voisin(element3);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(0));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(2));
            element3->set_voisin(bordure[2]->get_bordure_fils(0));

            // Ajout des liens additionelles
            // Aucun

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 9 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element2);

            bordure[3]->get_bordure_fils(1)->set_voisin(element2);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 10 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);
            Element * element2 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element2);

            bordure[3]->get_bordure_fils(1)->set_voisin(element2);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 11 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element3);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element4);

            bordure[2]->get_bordure_fils(0)->set_voisin(element4);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element3);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[3
            ]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[2]->get_bordure_fils(2));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);


            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 12 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element3);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element4);

            bordure[2]->get_bordure_fils(0)->set_voisin(element4);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element3);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[3
            ]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[2]->get_bordure_fils(2));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 13 (x1)
    {
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::VILLE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::PLAINE);
            Element * element3 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element2);

            bordure[2]->get_bordure_fils(1)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element3);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            element3->set_lien(element1);


        // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }

    // Tuile 14 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);
            Element * element2 = new Element(Noeud::PLAINE);
            Element * element3 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element2);

            bordure[2]->get_bordure_fils(1)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element3);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            element3->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 15 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element2);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 16 (x1)
    {
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);
            Element * element2 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element2);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

        // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }

    // Tuile 17 (x1)
    {
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[2]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
                // Aucun

        // Ajout element dans la liste
            elementTuile.push_back(element1);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }

    // Tuile 18 (x1)
    {
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(0)->set_voisin(element3);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element4);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(0));

            element4->set_voisin(bordure[2]->get_bordure_fils(2));

            // Ajout des liens additionelles
            element3->set_lien(element1);
            element4->set_lien(element1);

        // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }

    // Tuile 19 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

                bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
                    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
                bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(0)->set_voisin(element3);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element4);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(0));

            element4->set_voisin(bordure[2]->get_bordure_fils(2));

            // Ajout des liens additionelles
            element3->set_lien(element1);
            element4->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 20 (x4)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE);
            Element * element2 = new Element(Noeud::ABBAYE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            // Aucun

            // Ajout des Tuiles dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 21 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::ABBAYE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(0)->set_voisin(element1);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(0));
            element1->set_voisin(bordure[2]->get_bordure_fils(2));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            // Ajout des liens additionelles
            // Aucun

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 22 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::ROUTE);
            Element * element4 = new Element(Noeud::ROUTE);
            Element * element5 = new Element(Noeud::PLAINE);
            Element * element6 = new Element(Noeud::PLAINE);
            Element * element7 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element5);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element6);

            bordure[2]->get_bordure_fils(0)->set_voisin(element6);
            bordure[2]->get_bordure_fils(1)->set_voisin(element3);
            bordure[2]->get_bordure_fils(2)->set_voisin(element7);

            bordure[3]->get_bordure_fils(0)->set_voisin(element7);
            bordure[3]->get_bordure_fils(1)->set_voisin(element4);
            bordure[3]->get_bordure_fils(2)->set_voisin(element5);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            element4->set_voisin(bordure[3]->get_bordure_fils(1));

            element5->set_voisin(bordure[1]->get_bordure_fils(0));
            element5->set_voisin(bordure[3]->get_bordure_fils(2));

            element6->set_voisin(bordure[1]->get_bordure_fils(2));
            element6->set_voisin(bordure[2]->get_bordure_fils(0));

            element7->set_voisin(bordure[2]->get_bordure_fils(2));
            element7->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionelles
            element5->set_lien(element1);

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);
            elementTuile.push_back(element5);
            elementTuile.push_back(element6);
            elementTuile.push_back(element7);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 23 (x4)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::ROUTE);
            Element * element5 = new Element(Noeud::PLAINE);
            Element * element6 = new Element(Noeud::ROUTE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(0)->set_voisin(element1);
            bordure[1]->get_bordure_fils(1)->set_voisin(element2);
            bordure[1]->get_bordure_fils(2)->set_voisin(element3);

            bordure[2]->get_bordure_fils(0)->set_voisin(element3);
            bordure[2]->get_bordure_fils(1)->set_voisin(element4);
            bordure[2]->get_bordure_fils(2)->set_voisin(element5);

            bordure[3]->get_bordure_fils(0)->set_voisin(element5);
            bordure[3]->get_bordure_fils(1)->set_voisin(element6);
            bordure[3]->get_bordure_fils(2)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(0));
            element1->set_voisin(bordure[3]->get_bordure_fils(2));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(2));
            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            element4->set_voisin(bordure[2]->get_bordure_fils(1));

            element5->set_voisin(bordure[2]->get_bordure_fils(2));
            element5->set_voisin(bordure[3]->get_bordure_fils(0));

            element6->set_voisin(bordure[1]->get_bordure_fils(1));

            // Ajout des liens additionelles
            // Aucun

            // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);
            elementTuile.push_back(element5);
            elementTuile.push_back(element6);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    }

    // Tuile 24 (x1)
    {
        for(int i = 0; i < 4; i++){

            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[0]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::ROUTE);
            Element * element2 = new Element(Noeud::PLAINE);
            Element * element3 = new Element(Noeud::ROUTE);
            Element * element4 = new Element(Noeud::PLAINE);
            Element * element5 = new Element(Noeud::ROUTE);
            Element * element6 = new Element(Noeud::PLAINE);
            Element * element7 = new Element(Noeud::ROUTE);
            Element * element8 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(0)->set_voisin(element8);
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);
            bordure[0]->get_bordure_fils(2)->set_voisin(element2);

            bordure[1]->get_bordure_fils(0)->set_voisin(element2);
            bordure[1]->get_bordure_fils(1)->set_voisin(element3);
            bordure[1]->get_bordure_fils(2)->set_voisin(element4);

            bordure[2]->get_bordure_fils(0)->set_voisin(element4);
            bordure[2]->get_bordure_fils(1)->set_voisin(element5);
            bordure[2]->get_bordure_fils(2)->set_voisin(element6);

            bordure[3]->get_bordure_fils(0)->set_voisin(element6);
            bordure[3]->get_bordure_fils(1)->set_voisin(element7);
            bordure[3]->get_bordure_fils(2)->set_voisin(element8);

            // element:
            element1->set_voisin(bordure[1]->get_bordure_fils(1));

            element2->set_voisin(bordure[0]->get_bordure_fils(2));
            element2->set_voisin(bordure[1]->get_bordure_fils(0));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(0));

            element5->set_voisin(bordure[2]->get_bordure_fils(1));

            element6->set_voisin(bordure[2]->get_bordure_fils(2));
            element6->set_voisin(bordure[3]->get_bordure_fils(0));

            element7->set_voisin(bordure[3]->get_bordure_fils(1));

            element8->set_voisin(bordure[3]->get_bordure_fils(2));
            element8->set_voisin(bordure[0]->get_bordure_fils(0));

            // Ajout des liens additionelles
                // Aucun

        // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);
            elementTuile.push_back(element5);
            elementTuile.push_back(element6);
            elementTuile.push_back(element7);
            elementTuile.push_back(element8);

            // Creation de la carte
            Tuile * carte = new Tuile(bordure, elementTuile);

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
        }
    }
    return plateau;
}
