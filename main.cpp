//Ce que mon code fait : 3 grilles trouvées sur internet, l'utilisateur en choisit une, la grille va s'afficher sur la console//

#include <iostream>
using namespace std;

// Trois grilles prédéfinies :
int grille1[9][9] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};

int grille2[9][9] = {
    {0,0,4, 0,0,0, 2,0,0},
    {0,8,0, 0,0,3, 0,0,9},
    {0,0,0, 0,8,0, 4,0,0},

    {0,0,0, 2,0,0, 0,4,0},
    {0,0,6, 0,0,0, 9,0,0},
    {0,1,0, 0,0,9, 0,0,0},

    {0,0,1, 0,2,0, 0,0,0},
    {7,0,0, 3,0,0, 0,6,0},
    {0,0,5, 0,0,0, 1,0,0}
};

int grille3[9][9] = {
    {1,0,0, 0,0,7, 0,9,0},
    {0,3,0, 0,2,0, 0,0,8},
    {0,0,9, 6,0,0, 5,0,0},

    {0,0,5, 3,0,0, 9,0,0},
    {0,1,0, 0,8,0, 0,0,2},
    {6,0,0, 0,0,4, 0,0,0},

    {0,0,0, 0,0,0, 0,0,0},
    {0,0,0, 4,1,0, 0,0,0},
    {0,0,0, 0,0,0, 0,0,0}
};

// Afficher une grille dans la console :
void afficherGrille(int g[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "=== Choisissez une grille de Sudoku ===" << endl;
    cout << "1 - Grille 1" << endl;
    cout << "2 - Grille 2" << endl;
    cout << "3 - Grille 3" << endl;

    int choix;
    cin >> choix;

    cout << "\nVoici la grille choisie :\n" << endl;

    if (choix == 1) afficherGrille(grille1);
    else if (choix == 2) afficherGrille(grille2);
    else if (choix == 3) afficherGrille(grille3);
    else cout << "Choix invalide." << endl;

    return 0;
}
