#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

#define RESET "\033[0m"
#define BLEU "\033[34m"  
#define VERT "\033[32m"  

extern bool userMark[9][9];  //Les arrays que pour voir ce qui est ajouté par l'utilisateur ou par le solveur
extern bool solverMark[9][9]; 

void afficherGrille(int g[9][9], int originale[9][9], int solution[9][9]); //fonction en charge de l'affichage de la grille dans le terminal

class Sudoku { 
public:
        
	Sudoku(int g[9][9], int s[9][9]) { //le sudoku est associé à une grille de départ et à une solution
		grille = g; solution = s;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				originale[i][j] = g[i][j]; //Pour le programme, on garde une copie de la grille originale pour savoir quelles cases sont fixes
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				userMark[i][j] = false; //A l'origine, aucune case n'a été remplie par l'utilisateur ou le solveur -> permettra de changer la couleur de la case plus tard
				solverMark[i][j] = false;
			}
	}

	
	void afficher() {
    afficherGrille(grille, originale, solution);
}

//Booléens pour le remplissage des cases
	bool checkAndSet(int line, int column, int number) { //En charge de la vérification de la combinaison line-colonne-valuer entré par l'utilisateur ; met à jour la grille si la valeur est correcte
		if (line < 0 || line > 8 || column < 0 || column > 8) return false; //Vérifie la validité des coordonnées (pas besoin pour la valeur, car le but de la fonction est de vérifier si la valeur est correcte)
		if (originale[line][column] != 0) return false;  //Ne permet pas de modifier une case fixe
		if (solution[line][column] == number) { //Si la combinaison est correcte
			grille[line][column] = number;  //affiche la valeur dans la grille
			userMark[line][column] = true;  //avec la couleur bleue (case remplie par l'utilisateur)
			solverMark[line][column] = false; 
			return true; 
		}
		return false;
	}

	bool provideHint(int line, int column) { //Fournit une aide en remplissant la case demandée avec la bonne valeur, marquée en vert (case remplie par le solveur)
		if (line < 0 || line > 8 || column < 0 || column > 8) return false; //Comme pour checkAndSet, vérifie la validité des coordonnées
		if (originale[line][column] != 0) return false; 
		grille[line][column] = solution[line][column];
		solverMark[line][column] = true; //ici, le nombre sera affiché en vert, car ajotué par le solveur
		userMark[line][column] = false;
		return true;
	}

    bool estComplete() const { //Vérifie case par case si la grille est complète, vaudra True si c'est le cas
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (grille[i][j] != solution[i][j])
                    return false;
        return true;
    }
	
	bool isFixed(int line, int column) const { //Vaut True si c'est une case fixe (fait partie de la grille de départ)
		return originale[line][column] != 0;
	}

private:
	int (*grille)[9];
	int (*solution)[9];
	int originale[9][9];
};

extern int G1[9][9];
extern int S1[9][9];
extern int G2[9][9];
extern int S2[9][9];
extern int G3[9][9];
extern int S3[9][9];
extern int G4[9][9];
extern int S4[9][9];


extern bool userMark[9][9];  
extern bool solverMark[9][9]; 

#endif
