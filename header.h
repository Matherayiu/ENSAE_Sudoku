#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

#define RESET "\033[0m"
#define BLEU "\033[34m"  
#define VERT "\033[32m"  

extern bool userMark[9][9];  
extern bool solverMark[9][9]; 

void afficherGrille(int g[9][9], int originale[9][9], int solution[9][9]);

class Sudoku {
public:
        
	Sudoku(int g[9][9], int s[9][9]) {
		grille = g; solution = s;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				originale[i][j] = g[i][j];
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				userMark[i][j] = false;
				solverMark[i][j] = false;
			}
	}

	
	void afficher() {
    afficherGrille(grille, originale, solution);
}

	bool checkAndSet(int l, int c, int n) {
		if (l < 0 || l > 8 || c < 0 || c > 8) return false;
		if (originale[l][c] != 0) return false; 
		if (solution[l][c] == n) { grille[l][c] = n; 
			userMark[l][c] = true; 
			solverMark[l][c] = false; 
			return true; 
		}
		return false;
	}

	bool provideHint(int l, int c) {
		if (l < 0 || l > 8 || c < 0 || c > 8) return false;
		if (originale[l][c] != 0) return false;
		grille[l][c] = solution[l][c];
		solverMark[l][c] = true;
		userMark[l][c] = false;
		return true;
	}

    bool estComplete() const {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (grille[i][j] != solution[i][j])
                    return false;
        return true;
    }
	
	bool isFixed(int l, int c) const {
		return originale[l][c] != 0;
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
