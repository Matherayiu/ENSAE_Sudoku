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

int S1_correct[9][9] = {
    {2,7,3,8,4,6,1,5,9},
    {8,3,9,2,1,5,4,7,6},
    {5,6,4,9,8,7,1,2,3},
    {1,9,2,5,6,8,3,7,4},
    {7,2,1,4,9,3,5,6,8},
    {4,8,6,7,3,1,2,9,5},
    {7,1,8,3,5,4,6,9,2},
    {9,5,3,6,2,8,7,4,1},
    {6,3,2,1,4,9,8,5,7}
};

int S2_correct[9][9] = {
    {9,5,8,2,1,7,4,3,6},
    {4,1,3,6,8,5,9,7,2},
    {2,7,6,8,4,9,5,1,3},
    {6,8,2,3,7,1,9,4,5},
    {7,4,1,9,5,6,3,2,8},
    {1,2,9,4,3,8,6,7,5},
    {9,3,7,6,4,3,2,1,5},
    {3,6,4,1,8,2,7,9,4},
    {8,9,5,7,5,4,8,6,1}
};

int S3_correct[9][9] = {
    {9,1,7,4,2,6,3,8,5},
    {3,8,6,5,1,7,2,9,4},
    {4,5,2,3,8,9,1,6,7},
    {7,3,8,6,4,1,5,2,9},
    {6,2,9,7,5,8,4,3,1},
    {1,4,5,8,9,3,7,5,6},
    {8,6,4,9,3,2,6,7,1},
    {5,7,3,2,6,4,8,1,9},
    {2,9,1,1,7,5,9,5,8}
};

int S4_correct[9][9] = {
    {7,6,8,9,3,4,1,5,2},
    {8,3,9,6,5,2,4,7,1},
    {4,5,2,1,6,8,9,2,3},
    {9,7,5,3,1,6,2,8,4},
    {6,9,3,5,4,8,7,1,9},
    {1,8,4,9,2,5,3,4,7},
    {5,1,7,2,9,3,8,5,6},
    {3,2,1,4,7,4,5,9,8},
    {2,4,6,8,5,7,1,3,4}
};

int main() {
    int choix;

    int (*grille)[9] = nullptr;
    int (*solution)[9] = nullptr;

    cout << "Choisissez une grille : 1, 2, 3 ou 4 : ";
    cin >> choix;

    if (choix == 1) { grille = G1; solution = S1_correct; }
    else if (choix == 2) { grille = G2; solution = S2_correct; }
    else if (choix == 3) { grille = G3; solution = S3_correct; }
    else if (choix == 4) { grille = G4; solution = S4_correct; }
    else {
        cout << "Choix invalide. Fin du script\n";
        return 0;
    }

    cout << "Grille sélectionnée :\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << grille[i][j] << " ";
        cout << endl;
    }

    cout << "\nEntrez la position (ligne puis colonne) et le chiffre : ";
    int ligne, colonne, chiffre;
    cin >> ligne >> colonne >> chiffre;

    ligne--; colonne--;

    if (solution[ligne][colonne] == chiffre)
        cout << "Correct !" << endl;
    else
        cout << "Incorrect." << endl;

    return 0;
}
