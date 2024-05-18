#include "carcassonne.hpp"

Joueur *Carcassonne::get_joueur(int joueur_id) {
	if (joueur_id == 1) {
		return this->joueur1;
	}
	if (joueur_id == 2) {
		return this->joueur2;
	}
	return nullptr;
}

Joueur *generer_joueur(String type_joueur, String difficult_joueur) {
	if (type_joueur == "HUMAIN") {
		return new Humain();
	}
	if (type_joueur == "ROBOT") {
		if (difficult_joueur == "FACILE") {
			return new Robot(Robot::ALEAT);
		}
		if (difficult_joueur == "NORMAL") {
			return new Robot(Robot::MINIMAX);
		}
	}
	return new Humain(); // retourne humain par défaut
}
/* API de Carcassonne */

// Initialise le jeu (génération d'un plateau)
void Carcassonne::init_jeu(Dictionary Game_Data) {
	Plateau plateau;
	plateau.init_root(BaseDeDonnees::generer_plateau_vanilla());
	plateau.init_plateau();

	Joueur *joueur1 = generer_joueur(Game_Data["type_joueur_1"], Game_Data["difficult_joueur_1"]);
	Joueur *joueur2 = generer_joueur(Game_Data["type_joueur_2"], Game_Data["difficult_joueur_2"]);

	plateau.ajouter_joueur(joueur1, new Pion());
	plateau.ajouter_joueur(joueur2, new Pion());

	this->joueur1 = joueur1;
	this->joueur2 = joueur2;
}

// Pioche une tuile
void Carcassonne::piocher_tuile() {
	this->tuile_pioche = plateau.piocher_tuile_aleat();
}

// Récupere l'identifiant d'une tuile
int Carcassonne::tuile_pioche_id() {
	return this->tuile_pioche->get_id() + 1;
}

// Récupere l'identifiant d'une tuile d'une coordonées x y
int Carcassonne::get_coord_id(int x, int y) {
	Tuile *tuile = this->plateau.get_tuile_grille(x, y);
	if (tuile != nullptr) {
		return tuile->get_id();
	}
	return -2;
}

// Calcul les emplacements libre d'une tuile
void Carcassonne::calcul_emplacement_libre() {
	this->plateau.clear_emplacement_libres();
	this->plateau.calcul_emplacements_libres(this->tuile_pioche);
}

// Calcul les élements libre d'une tuile
void Carcassonne::calcul_element_libre() {
	this->plateau.clear_element_libres();
	this->plateau.calculer_element_libres(this->tuile_pioche);
}

// Récupère les coordonnées des emplacements libre
Dictionary Carcassonne::get_coord_emplacement_libre() {
	std::vector<std::array<int, 3> > liste_tuiles_emplacements_libres = plateau.get_liste_tuiles_emplacements_libres();
	Dictionary tuiles_libres;

	for (auto emplacement : liste_tuiles_emplacements_libres) {
		Vector2 coord = Vector2(Vector2(emplacement.at(0), emplacement.at(1)));
		if (!tuiles_libres.has(coord)) {
			Array array_orientation;
			array_orientation.append(emplacement.at(2));
			tuiles_libres[coord] = array_orientation;
		} else {
			((Array)tuiles_libres[coord]).append(emplacement.at(2));
		}
	}
	return tuiles_libres;
}

// Pose la tuile pioché sur la grille
void Carcassonne::poser_tuile_pioche(int x, int y, int orientation) {
	this->emplacement_tuile_pioche.at(0) = x;
	this->emplacement_tuile_pioche.at(1) = y;
	this->emplacement_tuile_pioche.at(2) = orientation;
	this->plateau.poser_tuile(tuile_pioche, this->emplacement_tuile_pioche);
}

// Récupère les coordonnées des éléments de la tuile piochée
Array Carcassonne::get_coord_element_tuile_pioche() {
	Array element_tuile;
	for (auto element : this->plateau.get_element_libre()) {
		Vector2 coord = Vector2(element->get_coords().first, element->get_coords().second);
		element_tuile.append(coord);
	}
	return element_tuile;
}

// Evalue les points des meeples en cours de jeu
void Carcassonne::evaluation_points_meeple() {
	this->plateau.evaluer_meeple(STATUS_EN_COURS);
}

// Evalue les points des meeples en fin de jeu
void Carcassonne::evaluation_points_meeple_final() {
	this->plateau.evaluer_meeple(STATUS_FINAL);
}

// Récupère le nombre de pions restant pour un joueur
int Carcassonne::get_nbr_pion_joueur(int joueur_id) {
	Joueur *joueur = get_joueur(joueur_id);
	return this->plateau.get_nbr_meeple(joueur);
}

int Carcassonne::get_points_espere_element(int element_id, int joueur_id) {
	Joueur *joueur = get_joueur(joueur_id);
	int score = 0;
	score = Pion::estimer_element_points(joueur, this->plateau.get_element_libre()[element_id], STATUS_EN_COURS, this->plateau.get_grille(), std::make_pair(this->emplacement_tuile_pioche.at(0), this->emplacement_tuile_pioche.at(1)));
	return score;
	Pion *get_pion_joueur(Joueur * joueur);
}

// Pose un meeple sur un élément
void Carcassonne::poser_meeple(int joueur_id, int indice_element, int indice) {
	Joueur *joueur = get_joueur(joueur_id);
	Meeple *meeple = Pion::generate_meeple(joueur, this->plateau.get_element_libre()[indice_element], this->plateau.get_grille(), std::make_pair(emplacement_tuile_pioche.at(0), emplacement_tuile_pioche.at(1)));
	this->plateau.poser_meeple(joueur, this->plateau.get_element_libre()[indice_element], meeple, indice);
}

// Donne la liste booleene du tableau de meeple selon la présence de meeple à l'indice
Array Carcassonne::get_meeple_pose_array(int joueur_id) {
	Array list_meeple_pose;
	Joueur *joueur = get_joueur(joueur_id);
	Pion *pion = this->plateau.get_pion_joueur(joueur);
	int itr = 0;
	for (auto meeple : pion->get_stack_meeple()) {
		if (meeple != nullptr) {
			list_meeple_pose.insert(itr, true);
		} else {
			list_meeple_pose.insert(itr, false);
		}

		itr++;
	}
	return list_meeple_pose;
}

// Récupère le premier meeple rencontré dans la liste
int Carcassonne::get_premier_meeple_indice_libre(int joueur_id) {
	Joueur *joueur = get_joueur(joueur_id);
	Pion *pion = this->plateau.get_pion_joueur(joueur);
	std::cout << pion->get_stack_meeple()[0] << std::endl;
	return pion->get_premier_indice_libre();
}

// récupère le score du joueur
int Carcassonne::get_joueur_score(int joueur_id) {
	Joueur *joueur = get_joueur(joueur_id);
	return joueur->get_score();
}

// determine si c'est la fin du jeu
bool Carcassonne::fin_du_jeu() {
	return this->plateau.pioche_est_vide();
}

Array Carcassonne::get_joueur_emplacement_choisi(int joueur_id) {
	Array position;
	Joueur *joueur = get_joueur(joueur_id);
	int indice_emplacement = joueur->choix_de_emplacement_libre();
	const std::array<int, 3> coordonnees_position = plateau.get_liste_tuiles_emplacements_libres()[indice_emplacement];
	for (int i = 0; i < 3; i++) {
		position.append(coordonnees_position[i]);
	}
	return position;
}

int Carcassonne::get_joueur_element_choisi(int joueur_id) {
	Joueur *joueur = get_joueur(joueur_id);
	return joueur->choix_de_element_libre();
}

bool Carcassonne::get_joueur_si_placer_meeple(int joueur_id) {
	Joueur *joueur = get_joueur(joueur_id);
	return joueur->choix_si_poser_meeple();
}

void Carcassonne::ia_joue(int joueur_id) {
	Joueur *joueur = get_joueur(joueur_id);
	Robot *robot = dynamic_cast<Robot *>(joueur);
	if (robot == nullptr) {
		// n'est pas un robot...
		return;
	}
	robot->update_ia(&plateau, this->tuile_pioche);
}

void Carcassonne::afficher_plateau_tui() {
	for (int i = 0; i < 144; i++) 
    {
		for (int j = 0; j < 144; j++) 
        {
            
			if (this->plateau.get_tuile_grille(i, j) != nullptr) 
            {
				Tuile *tuile = this->plateau.get_tuile_grille(i, j);

				std::cout << "coords (" << i << "," << j << ") " << tuile->get_id() << std::endl;
				if (tuile->get_id() != -1)
                {
                    if(tuile->get_id() < -1 || tuile->get_id() > 72)
                    {
                        Logging::log(Logging::CRITICAL, "tuile ayant un id non alloué, echec du programme");
                        exit(false);
                    }
					std::cout << "Elements de la tuile: " << std::endl;
					for (auto element : tuile->getElements()) 
                    {
						std::cout << " " << element->get_type_element();

						Meeple *meeple = element->get_meeple();
						if (meeple != nullptr) 
                        {
							// cout << " (meeple " << meeple->get_joueur()->get_couleur() << ")";
						}
					}
					std::cout << std::endl;
				}
			}
		}
	}
}

// Binding method pour GODOT
void Carcassonne::_bind_methods() {
	/* Initialisation du Jeu */
	ClassDB::bind_method(D_METHOD("init_jeu"), &Carcassonne::init_jeu);

	/* Calcul pendant le jeu */

	// 1. Piocher un Tuile
	ClassDB::bind_method(D_METHOD("piocher_tuile"), &Carcassonne::piocher_tuile);
	ClassDB::bind_method(D_METHOD("tuile_pioche_id"), &Carcassonne::tuile_pioche_id);

	// 2. Méthodes pour poser une Tuile
	ClassDB::bind_method(D_METHOD("calcul_emplacement_libre"), &Carcassonne::calcul_emplacement_libre);
	ClassDB::bind_method(D_METHOD("get_coord_emplacement_libre"), &Carcassonne::get_coord_emplacement_libre);
	ClassDB::bind_method(D_METHOD("poser_tuile_pioche", "x", "y", "orientation"), &Carcassonne::poser_tuile_pioche);

	// 3. Méthodes pour poser un Meeple
	ClassDB::bind_method(D_METHOD("get_coord_element_tuile_pioche"), &Carcassonne::get_coord_element_tuile_pioche);
	ClassDB::bind_method(D_METHOD("poser_meeple", "joueur_id", "indice_id", "indice_pion_meeple"), &Carcassonne::poser_meeple);
	ClassDB::bind_method(D_METHOD("get_premier_meeple_indice_libre", "joueur_id"), &Carcassonne::get_premier_meeple_indice_libre);
	ClassDB::bind_method(D_METHOD("get_nbr_pion_joueur", "joueur_id"), &Carcassonne::get_nbr_pion_joueur);

	// 4. Méthodes pour faire jouer l'IA
	ClassDB::bind_method(D_METHOD("ia_joue", "joueur_id"), &Carcassonne::ia_joue);
	ClassDB::bind_method(D_METHOD("get_joueur_emplacement_choisi", "joueur_id"), &Carcassonne::get_joueur_emplacement_choisi);
	ClassDB::bind_method(D_METHOD("get_joueur_element_choisi", "joueur_id"), &Carcassonne::get_joueur_element_choisi);
	ClassDB::bind_method(D_METHOD("get_joueur_si_placer_meeple", "joueur_id"), &Carcassonne::get_joueur_si_placer_meeple);

	// 5. Méthode pour compter/évaluer/estimer les points
	ClassDB::bind_method(D_METHOD("evaluation_points_meeple"), &Carcassonne::evaluation_points_meeple);
	ClassDB::bind_method(D_METHOD("calcul_element_libre"), &Carcassonne::calcul_element_libre);
	ClassDB::bind_method(D_METHOD("get_meeple_pose_array", "joueur_id"), &Carcassonne::get_meeple_pose_array);
	ClassDB::bind_method(D_METHOD("get_points_espere_element", "element_id", "joueur_id"), &Carcassonne::get_points_espere_element);
	ClassDB::bind_method(D_METHOD("get_joueur_score", "joueur_id"), &Carcassonne::get_joueur_score);

	/* Fin du jeu */
	ClassDB::bind_method(D_METHOD("evaluation_points_meeple_final"), &Carcassonne::evaluation_points_meeple_final);
	ClassDB::bind_method(D_METHOD("fin_du_jeu"), &Carcassonne::fin_du_jeu);

	/* Autres méthodes */
	ClassDB::bind_method(D_METHOD("get_coord_id", "x", "y"), &Carcassonne::get_coord_id);
	ClassDB::bind_method(D_METHOD("afficher_plateau_tui"),&Carcassonne::afficher_plateau_tui);
}

Carcassonne::Carcassonne() {}
