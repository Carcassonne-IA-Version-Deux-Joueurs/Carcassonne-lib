#ifndef CARCASSONNE_H
#define CARCASSONNE_H

#include "src/Plateau.hpp"
#include "src/BaseDeDonnees.hpp"
#include "src/Humain.hpp"
#include "src/Robot.hpp"
#include "src/Joueur.hpp"

#include <array>
#include <cstddef>
#include <utility>
#include <vector>

#include "core/variant/dictionary.h"
#include "core/object/ref_counted.h"
#include "core/variant/array.h"
#include "core/object/class_db.h"
#include "core/math/vector2.h"

class Carcassonne : public RefCounted {
    /* API GODOT */
    GDCLASS(Carcassonne, RefCounted);

    /* Variables */
    Plateau plateau;
    Tuile   * tuile_pioche;
    Joueur  * joueur1;
    Joueur  * joueur2;
    std::array<int, 3> emplacement_tuile_pioche; 
    
    /* Méthode privée */
    Joueur * get_joueur(int joueur_id);   

protected:
    static void _bind_methods();

public:
    Carcassonne();
    void init_jeu(Dictionary Game_Data);
    void piocher_tuile();
    int tuile_pioche_id();
    int get_coord_id(int x, int y);
    void calcul_emplacement_libre();
    Dictionary get_coord_emplacement_libre();
    void poser_tuile_pioche(int x, int y, int orientation);
    void calcul_element_libre();
    Array get_coord_element_tuile_pioche();
    int get_nbr_pion_joueur(int joueur_id);
    void poser_meeple(int joueur_id, int indice_element, int indice);
    void evaluation_points_meeple();
    void evaluation_points_meeple_final();
    int get_points_espere_element(int element_id, int joueur_id);
    Array get_meeple_pose_array(int joueur_id);
    int get_premier_meeple_indice_libre(int joueur_id);
    int get_joueur_score(int joueur_id);
    void ia_joue(int joueur_id);
    bool get_joueur_si_placer_meeple(int joueur_id);
    int get_joueur_element_choisi(int joueur_id);
    Array get_joueur_emplacement_choisi(int joueur_id);
    void afficher_plateau_tui();
    bool fin_du_jeu();
};

#endif // CARCASSONNE_HPP
