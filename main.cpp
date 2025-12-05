//Ce que notre code fait : 3 grilles trouvées sur internet, l'utilisateur en choisit une, la grille va s'afficher sur la console//

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

int grille4[9][9] = {
    {1,0,0, 0,0,7, 0,9,0},
    {0,3,0, 0,2,0, 0,0,8},
    {0,0,9, 6,0,0, 5,0,0},

    {0,0,5, 3,0,0, 9,0,0},
    {0,1,0, 0,8,0, 0,0,2},
    {6,0,0, 0,0,4, 0,0,0},

    {3,0,0, 0,0,0, 0,1,0},
    {0,4,0, 4,1,0, 0,0,7},
    {0,0,7, 0,0,0, 3,0,0}
};

void afficherGrille(int g[9][9]) {
    cout << " -----------------------" << endl;
    for (int i = 0; i < 9; i++) {

        cout << "| ";
        for (int j = 0; j < 9; j++) {
            if (g[i][j] == 0)
                cout << ". ";
            else
                cout << g[i][j] << " ";

            if ((j + 1) % 3 == 0) cout << "| ";
        }

        cout << endl;

        // ligne horizontale tous les 3 blocs
        if ((i + 1) % 3 == 0)
            cout << " -----------------------" << endl;
    }
}


int main() {
    cout << "=== Choisissez une grille de Sudoku ===" << endl;
    cout << "1 - Grille 1" << endl;
    cout << "2 - Grille 2" << endl;
    cout << "3 - Grille 3" << endl;
    cout << "4 - Grille la plus difficile du monde" << endl;

    int choix;
    cin >> choix;

    cout << "\nVoici la grille choisie :\n" << endl;

    if (choix == 1) afficherGrille(grille1);
    else if (choix == 2) afficherGrille(grille2);
    else if (choix == 3) afficherGrille(grille3);
    else if (choix == 4) afficherGrille(grille4);
    else cout << "Choix invalide." << endl;

    return 0;
}
