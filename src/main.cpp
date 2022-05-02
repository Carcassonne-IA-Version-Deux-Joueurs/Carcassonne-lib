// LIBRAIRIES
#include <iostream>
#include <list>
#include <map>
#include <tuple>
#include <vector>

#include "BaseDeDonnees.hpp"
#include "Bordure.hpp"
#include "Constantes.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Tuile.hpp"

using namespace std;

// FONCTIONS
void afficher_elements(vector<Element *> list_element) {
	int i = 0;
	for (Element *element : list_element) {
		if (!Plateau::verifier_si_meeple_voisin(element, element->get_type_element())) {
			cout << "Element n°" << i << ": " << element->get_type_element() << endl;
		} else {
			cout << "Element n°" << i << " (impossible à placer): " << element->get_type_element() << endl;
		}
		i++;
	}
}

void afficher_plateau(Plateau *plateau) {
	for (int i = 0; i < 144; i++) {
		for (int j = 0; j < 144; j++) {
			if (plateau->get_tuile_grille(i, j) != nullptr) {
				Tuile *tuile = plateau->get_tuile_grille(i, j);

				cout << "coords (" << i << "," << j << ") " << tuile->get_id() << endl;
				if (tuile->get_id() != -1) {
					cout << "Elements de la tuile: " << endl;
					for (auto element : tuile->getElements()) {
						cout << " " << element->get_type_element();

						Meeple *meeple = element->get_meeple();
						if (meeple != nullptr) {
							cout << " (meeple " << meeple->get_joueur()->get_couleur() << ")";
						}
					}
					cout << endl;
				}
			}
		}
	}
}

void afficher_liste_tuiles_emplacements_libres(vector<array<int, 3>> liste_tuiles_emplacements_libres) {
	for (long unsigned int i = 0; i < liste_tuiles_emplacements_libres.size(); i++) {
		cout << "Emplacement n°" << i << " :\n"
			 << "Abscisse :\t" << liste_tuiles_emplacements_libres.at(i).at(0) << "\tOrdonnée :\t" << liste_tuiles_emplacements_libres.at(i).at(1) << "\tOrientation :\t" << (liste_tuiles_emplacements_libres.at(i).at(2) * 90) << "°" << endl;
	}
}

// TEST UNITAIRE
#ifdef TEST_UNIT

Plateau *init_plateau() {
	Plateau *plateau = BaseDeDonnees::generer_plateau_vanilla();
	plateau->init_plateau();
	return plateau;
}
void afficher_tuile(Tuile *tuile) {
	Logging::log(Logging::DEBUG, "Affichage de la tuile de type n° %d", tuile->getId());
	Logging::log(Logging::DEBUG, "0: vide, 1: route, 2: ville, 3: ville blason, 4: abbaye, 5: plaine");

	Logging::log(Logging::DEBUG, "Nord : ");
	Bordure *bordureNord = tuile->getBordure(0);
	for (int i = 0; i < 3; i++) {
		Bordure *bordure_fils = bordureNord->get_bordure_fils(i);
		Logging::log(Logging::DEBUG, "Element: %d", bordure_fils->get_type_element());
		Logging::log(Logging::DEBUG, "Voisins de la bordure: ");
		for (int j = 0; j < bordure_fils->get_nbr_voisins(); j++) {
			Noeud *noeud = bordure_fils->get_voisin(j);
			if (noeud != nullptr) {
				Logging::log(Logging::DEBUG, " %d,", noeud->get_type_element());
			} else {
				Logging::log(Logging::DEBUG, " 0,");
			}
		}
	}

	Logging::log(Logging::DEBUG, "Est : ");
	Bordure *bordureEst = tuile->getBordure(1);
	for (int i = 0; i < 3; i++) {
		Bordure *bordure_fils = bordureEst->get_bordure_fils(i);
		Logging::log(Logging::DEBUG, "Element: %d", bordure_fils->get_type_element());
		Logging::log(Logging::DEBUG, "Voisins de la bordure: ");
		for (int j = 0; j < bordure_fils->get_nbr_voisins(); j++) {
			Noeud *noeud = bordure_fils->get_voisin(j);
			if (noeud != nullptr) {
				Logging::log(Logging::DEBUG, " %d,", noeud->get_type_element());
			} else {
				Logging::log(Logging::DEBUG, " 0,");
			}
		}
	}

	Logging::log(Logging::DEBUG, "Sud : ");
	Bordure *bordureSud = tuile->getBordure(2);
	for (int i = 0; i < 3; i++) {
		Bordure *bordure_fils = bordureSud->get_bordure_fils(i);
		Logging::log(Logging::DEBUG, "Element: %d", bordure_fils->get_type_element());
		Logging::log(Logging::DEBUG, "Voisins de la bordure: ");
		for (int j = 0; j < bordure_fils->get_nbr_voisins(); j++) {
			Noeud *noeud = bordure_fils->get_voisin(j);
			if (noeud != nullptr) {
				Logging::log(Logging::DEBUG, " %d,", noeud->get_type_element());
			} else {
				Logging::log(Logging::DEBUG, " 0,");
			}
		}
	}

	Logging::log(Logging::DEBUG, "Ouest : ");
	Bordure *bordureOuest = tuile->getBordure(3);
	for (int i = 0; i < 3; i++) {
		Bordure *bordure_fils = bordureOuest->get_bordure_fils(i);
		Logging::log(Logging::DEBUG, "Element: %d", bordure_fils->get_type_element());
		Logging::log(Logging::DEBUG, "Voisins de la bordure: ");
		for (int j = 0; j < bordure_fils->get_nbr_voisins(); j++) {
			Noeud *noeud = bordure_fils->get_voisin(j);
			if (noeud != nullptr) {
				Logging::log(Logging::DEBUG, " %d,", noeud->get_type_element());
			} else {
				Logging::log(Logging::DEBUG, " 0,");
			}
		}
	}

	Logging::log(Logging::DEBUG, "affichage des éléments");
	for (auto element : tuile->getElements()) {
		Logging::log(Logging::DEBUG, "> %d", element->get_type_element());
	}
}

void test_init_plateau() {
	Logging::log(Logging::DEBUG, "Test unitaire de la fonction init_plateau()");
	Plateau *plateau = init_plateau();
	Logging::log(Logging::DEBUG, "Tuile de base %d", plateau->get_tuile_grille(NBR_TUILES - 1, NBR_TUILES - 1));
}

void test_init_pioche() {
	Logging::log(Logging::DEBUG, "Test de l'initialisation de la pioche");
	Plateau *plateau = init_plateau();
	Logging::log(Logging::DEBUG, "Nombre de tuiles dans la pioche : %d ", plateau->get_pioche().size());
	for (int i = 0; i < (int)plateau->get_pioche().size(); i++) {
		Logging::log(Logging::DEBUG, "Test de la tuile %d = %d", i, plateau->get_pioche()[i]);
	}
}

void test_piocher_tuile() {
	Logging::log(Logging::DEBUG, "Test unitaire de la fonction piocher_tuile()");
	Plateau *plateau = init_plateau();
	Logging::log(Logging::DEBUG, "Nombre de tuiles dans la pioche : %d ", plateau->get_pioche().size());
	plateau->piocher_tuile_aleat();
	plateau->piocher_tuile_aleat();
	Logging::log(Logging::DEBUG, "Nombre de tuiles dans la pioche après avoir pioché 2 fois: %d ", plateau->get_pioche().size());
}

void test_afficher_tuile() {
	Logging::log(Logging::DEBUG, "Test unitaire de la afficher une tuile");
	Plateau *plateau = init_plateau();
	afficher_tuile(plateau->get_tuile_grille(NBR_TUILES - 1, NBR_TUILES - 1));
}

void test_rotation_tuile() {
	Logging::log(Logging::DEBUG, "Test unitaire de la rotation d'une tuile");
	Plateau *plateau = init_plateau();
	Tuile *tuile = plateau->get_tuile_grille(NBR_TUILES - 1, NBR_TUILES - 1);
	Logging::log(Logging::DEBUG, "Affichage de la tuile avant rotation");
	afficher_tuile(tuile);
	tuile->rotationHoraire();
	Logging::log(Logging::DEBUG, "Affichage de la tuile après rotation");
	afficher_tuile(tuile);
}

void test_calcul_emplacement_libre() {
	Logging::log(Logging::DEBUG, "Test unitaire de la fonction calcul_emplacement_libre()");
	Plateau *plateau = init_plateau();
	Logging::log(Logging::DEBUG, "Nbr de tuiles candidates %d", plateau->get_tuiles_candidates().size());
	Tuile *tuile = plateau->piocher_tuile_aleat();
	afficher_tuile(tuile);
	plateau->calcul_emplacements_libres(tuile);
	vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
}

void test_ajout_tuile_au_hasard() {
	Logging::log(Logging::DEBUG, "Test unitaire de la fonction ajout d'une tuile");
	Plateau *plateau = init_plateau();

	for (int i = 0; i < 10; i++) {
		Tuile *tuile_pioche = plateau->piocher_tuile_aleat();
		afficher_tuile(tuile_pioche);
		plateau->calcul_emplacements_libres(tuile_pioche);
		vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
		afficher_plateau(plateau);
		Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
		afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
		int index;
		cin >> index;
		plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[index]);
		Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", index);
		liste_tuiles_emplacements_libres.clear();
	}
}

void test_ajout_meeple() {
	Logging::log(Logging::DEBUG, "Test unitaire de l'ajout de meeples");
	Plateau *plateau = init_plateau();
	Joueur *joueur = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
	plateau->ajouter_joueur(joueur, new Pion(7)); // ajouter joueur

	Tuile *tuile_pioche = plateau->piocher_tuile(1);
	afficher_tuile(tuile_pioche);
	plateau->calcul_emplacements_libres(tuile_pioche);
	vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);
	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	int index;
	cin >> index;
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[index]);
	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", index);

	cout << "Poser pions ?" << endl;
	string poser_pion;
	cin >> poser_pion;
	Logging::log(Logging::DEBUG, "Poser pion : %s", poser_pion.c_str());
	if (!poser_pion.compare("yes")) {
		afficher_tuile(tuile_pioche);
		afficher_plateau(plateau);

		vector<Element *> list_element = tuile_pioche->getElements();
		afficher_elements(list_element);
		cout << "Choisir emplacement" << endl;
		int index;
		cin >> index;
		// todo creer coord std::pair pour poser meeple
		//plateau->poser_meeple(joueur, list_element[index], tuile_pioche); // Permet au joueur de placer un pion sur la tuile
	}

	afficher_plateau(plateau);
	// afficher tous les meeples du plateau

	liste_tuiles_emplacements_libres.clear();
}

void test_chevalier() {
	Logging::log(Logging::DEBUG, "Test unitaire de chevalier");
	Plateau *plateau = init_plateau();

	Joueur *joueur = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
	plateau->ajouter_joueur(joueur, new Pion(7)); // ajouter joueur

	Tuile *tuile_pioche = plateau->piocher_tuile(37);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);

	std::pair<int, int> coord = { liste_tuiles_emplacements_libres[0][0], liste_tuiles_emplacements_libres[0][1] };

	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[0]);
	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", 0);

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	vector<Element *> list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	plateau->poser_meeple(joueur, list_element[0], coord); // Permet au joueur de placer un pion sur la tuile

	afficher_plateau(plateau);
	// afficher tous les meeples du plateau

	plateau->evaluer_meeple(STATUS_EN_COURS);

	// tirage d'une autre tuile

	liste_tuiles_emplacements_libres.clear();

	tuile_pioche = plateau->piocher_tuile(0);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[7]);
	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", tuile_pioche->getId());

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	list_element.clear();
	list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	afficher_plateau(plateau);
	plateau->evaluer_meeple(STATUS_EN_COURS);
	liste_tuiles_emplacements_libres.clear();
}

void test_brigand() {
	Logging::log(Logging::DEBUG, "Test unitaire de chevalier");
	Plateau *plateau = init_plateau();

	Joueur *joueur = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
	plateau->ajouter_joueur(joueur, new Pion(7)); // ajouter joueur

	Tuile *tuile_pioche = plateau->piocher_tuile(68);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[0]);
	std::pair<int, int> coord = { liste_tuiles_emplacements_libres[0][0], liste_tuiles_emplacements_libres[0][1] };

	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", 0);

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	vector<Element *> list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	plateau->poser_meeple(joueur, list_element[5], coord); // Permet au joueur de placer un pion sur la tuile

	afficher_plateau(plateau);
	// afficher tous les meeples du plateau

	plateau->evaluer_meeple(STATUS_EN_COURS);

	// tirage d'une autre tuile

	liste_tuiles_emplacements_libres.clear();

	tuile_pioche = plateau->piocher_tuile(68);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[1]);
	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", tuile_pioche->getId());

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	list_element.clear();
	list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	afficher_plateau(plateau);
	plateau->evaluer_meeple(STATUS_EN_COURS);
	liste_tuiles_emplacements_libres.clear();
}

void test_moine() {
	Logging::log(Logging::DEBUG, "Test unitaire de chevalier");
	Plateau *plateau = init_plateau();

	Joueur *joueur = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
	plateau->ajouter_joueur(joueur, new Pion(7)); // ajouter joueur

	Tuile *tuile_pioche = plateau->piocher_tuile(58);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[0]);
	std::pair<int, int> coord = { liste_tuiles_emplacements_libres[0][0], liste_tuiles_emplacements_libres[0][1] };

	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", 0);

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	vector<Element *> list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	plateau->poser_meeple(joueur, list_element[1], coord); // Permet au joueur de placer un pion sur la tuile

	afficher_plateau(plateau);
	// afficher tous les meeples du plateau

	plateau->evaluer_meeple(STATUS_EN_COURS);

	// tirage d'une autre tuile

	liste_tuiles_emplacements_libres.clear();

	tuile_pioche = plateau->piocher_tuile(68);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[1]);
	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", tuile_pioche->getId());

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	list_element.clear();
	list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	afficher_plateau(plateau);
	plateau->evaluer_meeple(STATUS_EN_COURS);
	liste_tuiles_emplacements_libres.clear();
}

void test_double_meeple() {
	Logging::log(Logging::DEBUG, "Test double meeple");
	Plateau *plateau = init_plateau();

	Joueur *joueur = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
	plateau->ajouter_joueur(joueur, new Pion(7)); // ajouter joueur

	Tuile *tuile_pioche = plateau->piocher_tuile(68);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[0]);
	std::pair<int, int> coord = { liste_tuiles_emplacements_libres[0][0], liste_tuiles_emplacements_libres[0][1] };

	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", 0);

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	vector<Element *> list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	plateau->poser_meeple(joueur, list_element[5], coord); // Permet au joueur de placer un pion sur la tuile

	afficher_plateau(plateau);
	// afficher tous les meeples du plateau

	plateau->evaluer_meeple(STATUS_EN_COURS);

	// tirage d'une autre tuile

	liste_tuiles_emplacements_libres.clear();

	tuile_pioche = plateau->piocher_tuile(68);
	afficher_tuile(tuile_pioche);

	plateau->calcul_emplacements_libres(tuile_pioche);
	liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
	afficher_plateau(plateau);

	Logging::log(Logging::DEBUG, "Nombre d'emplacements libres : %d", liste_tuiles_emplacements_libres.size());
	afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
	plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[1]);
	Logging::log(Logging::DEBUG, "Tuile %d placé sur la plateau de jeu", tuile_pioche->getId());

	afficher_tuile(tuile_pioche);
	afficher_plateau(plateau);

	list_element.clear();
	list_element = tuile_pioche->getElements();
	afficher_elements(list_element);

	plateau->evaluer_meeple(STATUS_EN_COURS);
	liste_tuiles_emplacements_libres.clear();
}

// MAIN
int main() {
	// Test unitaire
	Logging::log(Logging::DEBUG, "Test unitaire");
	// test_init_plateau();
	// test_init_pioche();
	// test_piocher_tuile();
	// test_afficher_tuile();
	// test_rotation_tuile();
	// test_calcul_emplacement_libre();
	// test_ajout_tuile_au_hasard();
	// test_ajout_meeple();
	// test_chevalier();
	// test_brigand();
	// test_moine();
	// test_double_meeple();
	return 0;
}
#else

// MAIN
int main() {
	/* Initialisation du plateau */
	Plateau *plateau = BaseDeDonnees::generer_plateau_vanilla(); // Génération du plateau depuis la base de données
	plateau->init_plateau(); // Initialisation du plateau en plaçcant la tuile de base

	/* Initialisation des joueurs */
	Joueur *joueur1 = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
	Joueur *joueur2 = new Joueur(Joueur::ROBOT, Joueur::ROUGE);

	plateau->ajouter_joueur(joueur1, new Pion());
	plateau->ajouter_joueur(joueur2, new Pion());

	int token = 0; // Token pour savoir qui joue

	Joueur *joueur; // Joueur qui joue

	/* Boucle principale */
	while (plateau->get_pioche().size() > 0) {
		/* Détermine le joueur qui joue */
		if (token == 0) {
			joueur = joueur1;
		} else {
			joueur = joueur2;
		}

		/* Afficher le plateau */
		afficher_plateau(plateau);

		/* Piocher une tuile */
		Tuile *tuile_pioche = plateau->piocher_tuile_aleat(); // Pioche une tuile au hasard et l'enlève de la pioche
		cout << "Tuile piochée n°" << tuile_pioche->get_id() << endl;

		/* Chercher les emplacements libres et les afficher */
		plateau->calcul_emplacements_libres(tuile_pioche); // Détermine tous les emplacements possibles sur le plateau
		vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
		cout << "Choisir l'index d'un emplacement de 0 à " << liste_tuiles_emplacements_libres.size() << endl;
		afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);

		/* choisir un emplacement libre et poser la tuile*/
		int indice_emplacement_libre;
		cin >> indice_emplacement_libre;
		plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[indice_emplacement_libre]);

		std::pair<int, int> coordonnee_tuile_pioche = { liste_tuiles_emplacements_libres[indice_emplacement_libre][0], liste_tuiles_emplacements_libres[indice_emplacement_libre][1] };

		/* Placer un meeple sur la tuile pioché */
		if (plateau->stack_meeple_vide(joueur)) // on regarde si le joueur à bien assez de tuile
		{
			cout << "Joueur" << token + 1 << "veut-il poser pions ?(oui/non)" << endl; // le joueur n'est pas obligé de poser un meeple
			string poser_pion;
			cin >> poser_pion;

			if (!poser_pion.compare("oui")) {
				cout << "Choisir emplacement" << endl;

				vector<Element *> list_element = tuile_pioche->getElements();
				afficher_elements(list_element);
				int indice_element;
				cin >> indice_element;
				//plateau->poser_meeple(joueur, list_element[indice_element], coordonnee_tuile_pioche); // Permet au joueur de placer un pion sur la tuile
			}
		}

		/* Compter les points de tous les joueurs */
		plateau->evaluer_meeple(STATUS_EN_COURS);

		/* Joueur suivant */
		token = 1 - token;
	}

	/* Compter les derniers points de fin de partie */
	plateau->evaluer_meeple(STATUS_FINAL);
	return 0;
}
#endif // TEST_UNIT
