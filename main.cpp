//Ce que fait notre code : il affiche des grilles à l'utilisateur, il connait déjà les réponses aux 4 sudokus, l'utilisateur entre un chiffre
// un par un et le code vérifie si c'est le bon chiffre. 
// Pour rentrer un chiffre, le code demande le numéro de la ligne et le numéro de la colonne pour positionner la valeur puis on note la 
// valeur : exemple j'écris : 1 3 8 : ligne 1 colonne 3 valeur 8. 

#include <iostream>
using namespace std; 

#define RESET "\033[0m"
#define BLEU "\033[34m"   // couleur pour le chiffre correct donné par l'utilisateur 
#define VERT "\033[32m"   // couleur pour le chiffre du solveur 

// on affiche la grille
void afficherGrille(int g[9][9], int originale[9][9], int solution[9][9]) {
    cout << "\n┌───────┬───────┬───────┐\n";
    for (int i = 0; i < 9; i++) {
        cout << "│ ";
        for (int j = 0; j < 9; j++) {
            if (g[i][j] == 0) cout << ". ";
            else {
                if (originale[i][j] == 0 && g[i][j] == solution[i][j]) {
                    cout << VERT << g[i][j] << RESET << " "; // solveur
                } else if (originale[i][j] == 0) {
                    cout << BLEU << g[i][j] << RESET << " "; // utilisateur
                } else {
                    cout << g[i][j] << " "; // chiffres de départ
                }
            }

            if ((j + 1) % 3 == 0) cout << "│ ";
        }
        cout << "\n";
        if ((i + 1) % 3 == 0 && i != 8)
            cout << "├───────┼───────┼───────┤\n";
    }
    cout << "└───────┴───────┴───────┘\n";
}


int G1[9][9] = {
    {0,0,3,0,2,0,6,0,0},
    {9,0,0,3,0,5,0,0,1},
    {0,0,1,8,0,6,4,0,0},
    {0,0,8,1,0,2,9,0,0},
    {7,0,0,0,0,0,0,0,8},
    {0,0,6,7,0,8,2,0,0},
    {0,0,2,6,0,9,5,0,0},
    {8,0,0,2,0,3,0,0,9},
    {0,0,5,0,1,0,3,0,0}
};

int S1[9][9] = {
    {4,8,3,9,2,1,6,5,7},
    {9,6,7,3,4,5,8,2,1},
    {2,5,1,8,7,6,4,9,3},
    {5,4,8,1,3,2,9,7,6},
    {7,2,9,5,6,4,1,3,8},
    {1,3,6,7,9,8,2,4,5},
    {3,7,2,6,8,9,5,1,4},
    {8,1,4,2,5,3,7,6,9},
    {6,9,5,4,1,7,3,8,2}
};


int G2[9][9] = {
    {0,2,0,6,0,8,0,0,0},
    {5,8,0,0,0,9,7,0,0},
    {0,0,0,0,4,0,0,0,0},
    {3,7,0,0,0,0,5,0,0},
    {6,0,0,0,0,0,0,0,4},
    {0,0,8,0,0,0,0,1,3},
    {0,0,0,0,2,0,0,0,0},
    {0,0,9,8,0,0,0,3,6},
    {0,0,0,3,0,6,0,9,0}
};

int S2[9][9] = {
    {1,2,3,6,7,8,9,4,5},
    {5,8,4,2,1,9,7,6,3},
    {9,6,7,5,4,3,8,2,1},
    {3,7,1,4,6,2,5,8,9},
    {6,9,2,1,8,5,3,7,4},
    {4,5,8,7,9,2,6,1,3}, 
    {8,3,6,9,2,4,1,5,7},
    {2,1,9,8,5,7,4,3,6},
    {7,4,5,3,1,6,2,9,8}
};


int G3[9][9] = {
    {0,0,0,2,6,0,7,0,1},
    {6,8,0,0,7,0,0,9,0},
    {1,9,0,0,0,4,5,0,0},
    {8,2,0,1,0,0,0,4,0},
    {0,0,4,6,0,2,9,0,0},
    {0,5,0,0,0,3,0,2,8},
    {0,0,9,3,0,0,0,7,4},
    {0,4,0,0,5,0,0,3,6},
    {7,0,3,0,1,8,0,0,0}
};

int S3[9][9] = {
    {4,3,5,2,6,9,7,8,1},
    {6,8,2,5,7,1,4,9,3},
    {1,9,7,8,3,4,5,6,2},
    {8,2,6,1,9,7,3,4,5},
    {3,7,4,6,8,2,9,1,5}, 
    {9,5,1,7,4,3,6,2,8}, 
    {5,1,9,3,2,6,8,7,4},
    {2,4,8,9,5,7,1,3,6},
    {7,6,3,8,1,4,2,5,9}
};

int G4[9][9] = {
    {0,0,0,0,0,0,2,0,0},
    {0,8,0,0,0,7,0,9,0},
    {6,0,2,0,0,0,5,0,0},
    {0,7,0,0,6,0,0,0,0},
    {0,0,0,9,0,1,0,0,0},
    {0,0,0,0,2,0,0,7,0},
    {0,0,9,0,0,0,8,0,6},
    {0,6,0,7,0,0,0,2,0},
    {0,0,1,0,0,0,0,0,0}
};

int S4[9][9] = {
    {9,1,7,3,4,5,2,6,8},
    {3,8,5,1,6,7,4,9,2},
    {6,9,2,3,4,8,5,1,7}, 
    {2,7,3,4,6,5,1,8,9}, 
    {2,9,4,9,8,1,6,5,3},
    {5,3,6,4,2,9,1,7,8},
    {7,4,9,1,3,2,8,5,6}, 
    {8,6,3,7,1,4,9,2,5},
    {7,5,1,2,9,8,3,0,4}
};

int main() {

    int choix;
    cout << "Choisissez une grille (1 à 4) : ";
    cin >> choix;

    int (*grille)[9] = nullptr;
    int (*solution)[9] = nullptr;

    if (choix == 1) { grille = G1; solution = S1; }
    else if (choix == 2) { grille = G2; solution = S2; }
    else if (choix == 3) { grille = G3; solution = S3; }
    else if (choix == 4) { grille = G4; solution = S4; }
    else {
        cout << "Choix invalide !";
        return 0;
    }

int originale[9][9];
for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
        originale[i][j] = grille[i][j];

    cout << "\nGrille de départ :";
    afficherGrille(grille, originale, solution);

    while (true) {
        int l, c, n;
        cout << "\nEntrez ligne (1-9), colonne (1-9) et chiffre : ";
        cin >> l >> c >> n;

        l--; c--;

        if (solution[l][c] == n) {
            cout << "Correct !\n";
            grille[l][c] = n;
        } else {
            cout << "Incorrect.\n";
        }

        afficherGrille(grille, originale, solution);
        
char demande;
cout << "Voulez-vous une aide ? (o/n) : ";
cin >> demande;

if (demande == 'o' || demande == 'O') {
    int la, ca;
    cout << "Entrez la ligne (1-9) : ";
    cin >> la;
    cout << "Entrez la colonne (1-9) : ";
    cin >> ca;

    la--; 
    ca--;
    
    if (la < 0 || la > 8 || ca < 0 || ca > 8) {
        cout << "Coordonnées invalides.\n";
    } else {
        cout << "La valeur correcte est : " << solution[la][ca] << "\n";
    }

    afficherGrille(grille, originale, solution);
    continue; 
}

    }

    return 0;
}
