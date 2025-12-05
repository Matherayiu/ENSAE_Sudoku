//Ce que fait notre code : il affiche des grilles à l'utilisateur, il connait déjà les réponses aux 4 sudokus, l'utilisateur entre un chiffre
// un par un et le code vérifie si c'est le bon chiffre. 
// Pour rentrer un chiffre, le code demande le numéro de la ligne et le numéro de la colonne pour positionner la valeur puis on note la 
// valeur : exemple j'écris : 1 3 8 : ligne 1 colonne 3 valeur 8. 

#include <iostream>
using namespace std;

class GrilleSudoku {
    //Add solution générée ? 
public:
    string Name; string Niveau; //add content? 
    GrilleSudoku() {
        string aName=Name;
        string aNiveau=Niveau;
    }
};

int grille1[9][9] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

int grille2[9][9] = {
    {0,0,4,0,0,0,2,0,0},
    {0,8,0,0,0,3,0,0,9},
    {0,0,0,0,8,0,4,0,0},
    {0,0,0,2,0,0,0,4,0},
    {0,0,6,0,0,0,9,0,0},
    {0,1,0,0,0,9,0,0,0},
    {0,0,1,0,2,0,0,0,0},
    {7,0,0,3,0,0,0,6,0},
    {0,0,5,0,0,0,1,0,0}
};

int grille3[9][9] = {
    {1,0,0,0,0,7,0,9,0},
    {0,3,0,0,2,0,0,0,8},
    {0,0,9,6,0,0,5,0,0},
    {0,0,5,3,0,0,9,0,0},
    {0,1,0,0,8,0,0,0,2},
    {6,0,0,0,0,4,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,4,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};

int grille4[9][9] = {
    {1,0,0,0,0,7,0,9,0},
    {0,3,0,0,2,0,0,0,8},
    {0,0,9,6,0,0,5,0,0},
    {0,0,5,3,0,0,9,0,0},
    {0,1,0,0,8,0,0,0,2},
    {6,0,0,0,0,4,0,0,0},
    {3,0,0,0,0,0,0,1,0},
    {0,4,0,4,1,0,0,0,7},
    {0,0,7,0,0,0,3,0,0}
};

int solution1[9][9] = {
    {5,3,4,6,7,8,9,1,2},
    {6,7,2,1,9,5,3,4,8},
    {1,9,8,3,4,2,5,6,7},
    {8,5,9,7,6,1,4,2,3},
    {4,2,6,8,5,3,7,9,1},
    {7,1,3,9,2,4,8,5,6},
    {9,6,1,5,3,7,2,8,4},
    {2,8,7,4,1,9,6,3,5},
    {3,4,5,2,8,6,1,7,9}
};

int solution2[9][9] = {
    {9,5,4,6,7,1,2,3,8},
    {1,8,7,5,4,3,6,2,9},
    {6,2,3,9,8,7,4,5,1},
    {5,7,9,2,1,6,8,4,3},
    {4,3,6,8,5,2,9,1,7},
    {2,1,8,7,3,9,5,6,4},
    {8,4,1,3,2,5,7,9,6},
    {7,9,2,4,6,8,1,6,5},
    {3,6,5,1,9,4,1,8,2}
};

int solution3[9][9] = {
    {1,6,2,8,5,7,4,9,3},
    {4,3,5,1,2,9,6,7,8},
    {7,8,9,6,3,4,5,2,1},
    {2,4,5,3,7,6,9,1,8},
    {3,1,6,9,8,5,7,4,2},
    {6,9,7,2,1,4,8,3,5},
    {9,2,1,5,6,8,3,8,7},
    {5,7,8,4,1,3,2,6,9},
    {8,5,3,7,9,2,1,5,6}
};

int solution4[9][9] = {
    {1,5,2,3,4,7,6,9,8},
    {7,3,4,1,2,6,9,5,8},
    {8,6,9,6,5,2,5,7,1},
    {4,7,5,3,6,1,9,2,3},
    {9,1,6,7,8,5,4,8,2},
    {6,2,8,9,3,4,7,6,5},
    {3,9,1,5,7,8,2,1,4},
    {2,4,3,4,1,9,8,3,7},
    {5,8,7,2,9,3,3,4,6}
};

void afficherGrille(int g[9][9]) {
    cout << "  ";
    for (int i = 0; i < 9; i++) {
        if (i==2 || i==5){
            cout << " " << i+1<<"  ";
        }
        else {
            cout << " " << i+1;
        }
    }
    cout << endl; cout << " -----------------------" << endl;
    for (int i = 0; i < 9; i++) {
        cout << i+1 << "| ";
        for (int j = 0; j < 9; j++) {
            if (g[i][j] == 0)
                cout << ". ";
            else
                cout << g[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0) cout << " -----------------------" << endl;
    }
}

bool verifier(int sol[9][9], int ligne, int colonne, int valeur) {
    return sol[ligne][colonne] == valeur;
}

int main() {
    cout << "=== Choisissez une grille de Sudoku en entrant le numéro correspondant ===" << endl;
    cout << "1 - Grille 1" << endl;
    cout << "2 - Grille 2" << endl;
    cout << "3 - Grille 3" << endl;
    cout << "4 - Grille la plus difficile du monde" << endl;

    int choix;
    cin >> choix;

    int (*grille)[9];
    int (*solution)[9];

    if (choix == 1) { grille = grille1; solution = solution1; }
    else if (choix == 2) { grille = grille2; solution = solution2; }
    else if (choix == 3) { grille = grille3; solution = solution3; }
    else if (choix == 4) { grille = grille4; solution = solution4; }
    else { cout << "Choix invalide. Fin du script" << endl; return 0; }

    cout << "\nVoici la grille choisie :\n";
    afficherGrille(grille);

    // --- Saisie utilisateur case par case ---
    while (true) {
        int ligne, colonne, valeur;
        cout << "Entrez ligne(1-9) colonne(1-9) valeur(1-9) ou 0 pour quitter. Veuillez taper Entrée entre chaque numéro : ";
        cin >> ligne;
        if (ligne == 0) break;
        cin >> colonne >> valeur;
        ligne--; colonne--; // passage à l'index 0-8

        if (verifier(solution, ligne, colonne, valeur)) {
            cout << "Correct !" << endl;
            grille[ligne][colonne] = valeur;
        } else {
            cout << "Incorrect !" << endl;
        }

        afficherGrille(grille);
    }

    cout << "Merci d'avoir joué !" << endl;
    return 0;
}
