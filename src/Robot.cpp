#include "Robot.hpp"    
#include <asm-generic/errno.h>

Robot::Robot(Type_robot type_robot)
{
    this->type_robot = type_robot;
    Joueur::score = 0;
    srand(time(0)); // robot aléatoire
}

void Robot::script_robot_aleat(Plateau * plateau, Tuile * tuile)
{     
    
    Logging::log(Logging::DEBUG, "tuile %d", tuile);
           
    plateau->add_child();            // plateau ajout un enfant de lui meme
    plateau->set_at_back_child();    // on se met au niveau de l'enfant
    
    plateau->calcul_emplacements_libres(tuile);
    plateau->get_liste_tuiles_emplacements_libres().clear();

    int size_liste = plateau->get_liste_tuiles_emplacements_libres().size();

    this->indice_emplacement_libre = rand() % size_liste;
        
    Logging::log(Logging::DEBUG, "Robot a choisi emplacement %d/%d", indice_emplacement_libre, (int) plateau->get_liste_tuiles_emplacements_libres().size());

    std::array<int,3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[indice_emplacement_libre];
        
    plateau->poser_tuile(tuile, emplacement);

    if(plateau->get_nbr_meeple(this) > 0)
    {
        this->si_poser_meeple = rand() % 2;
        if(this->si_poser_meeple == true) 
        {
            Logging::log(Logging::DEBUG, "Robot veut placer un Meeple");
            plateau->calculer_element_libres(tuile);
            int size_liste_element = plateau->get_element_libre().size();
            if(size_liste_element > 0)
            {
                this->indice_element_libre = rand() % size_liste_element;
                Logging::log(Logging::DEBUG, "Robot veut placer sont Meeple à %d", this->indice_element_libre);
            }
            else 
            {
                Logging::log(Logging::DEBUG, "Robot ne peux pas placer de Meeple");
                this->si_poser_meeple = false;
            }
        } 
        else  
        {
            this->si_poser_meeple = false; 
        }
    }
    else
    {
        this->si_poser_meeple = false;
    }
    
    plateau->remove_back_child(); // supprime le dernier et revient à l'état d'avant (root)
}

void Robot::script_robot_minimax(Plateau *  plateau, Tuile * tuile)
{
    // TODO
}

void Robot::update_ia(Plateau * plateau, Tuile * tuile_pioche)
{
    Logging::log(Logging::TRACE, "mise à jour de l'IA");    
    Tuile * tuile_pioche_tmp =  tuile_pioche; //new Tuile(*tuile_pioche);

    if(tuile_pioche_tmp == nullptr)
    {
        Logging::log(Logging::DEBUG, "tuile pioche en paramettre de l'IA est null");
        return;
    }

    switch(this->type_robot)
    {
        case(Robot::ALEAT):
             script_robot_aleat(plateau, tuile_pioche);
             break;
        
        case(Robot::MINIMAX):
             script_robot_minimax(plateau, tuile_pioche_tmp);
             break;
        
        default:
             Logging::log(Logging::DEBUG, "Type de l'IA non reconnu, initialisation des données par défaut");
             indice_emplacement_libre = 0;
             si_poser_meeple = false;
             indice_element_libre = 0;
    } 

    //delete tuile_pioche_tmp;
}

int Robot::choix_de_emplacement_libre()
{
    return this->indice_emplacement_libre;
}

bool Robot::choix_si_poser_meeple()
{
    return this->si_poser_meeple;
}

int Robot::choix_de_element_libre()
{
    if(this->choix_si_poser_meeple() == false)
    {
        Logging::log(Logging::DEBUG, "Demande le choix de l'élément alors que le robot ne veut pas poser de meeple, retourne le choix 0");
        return 0;
    }
    return this->indice_element_libre;
}
