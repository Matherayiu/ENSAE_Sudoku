// Ce que fait notre code : il affiche des grilles à l'utilisateur, il connait déjà les réponses aux 4 sudokus, l'utilisateur entre un chiffre
//  un par un et le code vérifie si c'est le bon chiffre.
//  Pour rentrer un chiffre, le code demande le numéro de la ligne et le numéro de la colonne pour positionner la valeur puis on note la
//  valeur : exemple j'écris : 1 3 8 : ligne 1 colonne 3 valeur 8.

#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void afficherGrille(int g[9][9], int originale[9][9], int solution[9][9])
{
    cout << "\n┌───────┬───────┬───────┐\n";
    for (int i = 0; i < 9; i++)
    {
        cout << "│ ";
        for (int j = 0; j < 9; j++)
        {
            if (g[i][j] == 0) // les cases vides sont remplies par des points
                cout << ". ";
            else
            {
                if (originale[i][j] == 0 && g[i][j] == solution[i][j])  //Quand une valeur correcte est ajoutée...
                {
                    if (solverMark[i][j]) cout << VERT << g[i][j] << RESET << " ";  //..par le solveur, le nombre est affiché en vert
                    else if (userMark[i][j]) cout << BLEU << g[i][j] << RESET << " "; //.....par l'utilisateur, le nombre est affiché en bleu
                }
                else
                {
                    cout << g[i][j] << " "; 
                }
            }

            if ((j + 1) % 3 == 0) //Ajoute les barres de séparation verticales toutes les trois valeurs 
                cout << "│ ";
        }
        cout << "\n";
        if ((i + 1) % 3 == 0 && i != 8)
            cout << "├───────┼───────┼───────┤\n";
    }
    cout << "└───────┴───────┴───────┘\n";
}

int G1[9][9] = {
    {8, 0, 1, 0, 2, 6, 0, 4, 0},
    {0, 0, 9, 8, 0, 0, 0, 2, 6},
    {0, 5, 0, 0, 7, 3, 8, 9, 1},
    {1, 3, 2, 0, 8, 0, 0, 7, 9},
    {0, 0, 0, 0, 0, 4, 0, 0, 0},
    {7, 6, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 0, 9, 1, 0},
    {9, 0, 0, 3, 4, 0, 0, 0, 7},
    {0, 8, 3, 0, 9, 0, 0, 5, 4}};

int S1[9][9] = {
    {8, 7, 1, 9, 2, 6, 3, 4, 5},
    {3, 4, 9, 8, 5, 1, 7, 2, 6},
    {2, 5, 6, 4, 7, 3, 8, 9, 1},
    {1, 3, 2, 6, 8, 5, 4, 7, 9},
    {5, 9, 8, 7, 3, 4, 1, 6, 2},
    {7, 6, 4, 2, 1, 9, 5, 3, 8},
    {4, 2, 7, 5, 6, 8, 9, 1, 3},
    {9, 1, 5, 3, 4, 2, 6, 8, 7},
    {6, 8, 3, 1, 9, 7, 2, 5, 4}};

int G2[9][9] = {
    {5, 1, 3, 7, 2, 0, 6, 4, 0},
    {6, 0, 8, 5, 4, 0, 7, 9, 1},
    {0, 9, 0, 1, 8, 0, 0, 0, 0},
    {2, 0, 6, 4, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 2, 0},
    {3, 4, 0, 0, 0, 0, 9, 0, 6},
    {0, 0, 5, 0, 0, 4, 1, 0, 2},
    {0, 0, 0, 9, 0, 5, 8, 6, 0},
    {0, 3, 0, 6, 0, 0, 0, 0, 0}};

int S2[9][9] = {
    {5, 1, 3, 7, 2, 9, 6, 4, 8},
    {6, 2, 8, 5, 4, 3, 7, 9, 1},
    {4, 9, 7, 1, 8, 6, 2, 5, 3},
    {2, 5, 6, 4, 9, 8, 3, 1, 7},
    {7, 8, 9, 3, 6, 1, 4, 2, 5},
    {3, 4, 1, 2, 5, 7, 9, 8, 6},
    {9, 6, 5, 8, 7, 4, 1, 3, 2},
    {1, 7, 2, 9, 3, 5, 8, 6, 4},
    {8, 3, 4, 6, 1, 2, 5, 7, 9}};

int G3[9][9] = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}};

int S3[9][9] = {
    {4, 3, 5, 2, 6, 9, 7, 8, 1},
    {6, 8, 2, 5, 7, 1, 4, 9, 3},
    {1, 9, 7, 8, 3, 4, 5, 6, 2},
    {8, 2, 6, 1, 9, 5, 3, 4, 7},
    {3, 7, 4, 6, 8, 2, 9, 1, 5},
    {9, 5, 1, 7, 4, 3, 6, 2, 8},
    {5, 1, 9, 3, 2, 6, 8, 7, 4},
    {2, 4, 8, 9, 5, 7, 1, 3, 6},
    {7, 6, 3, 4, 1, 8, 2, 5, 9}};

int G4[9][9] = {
    {0, 0, 0, 0, 0, 0, 2, 0, 0},
    {0, 8, 0, 0, 0, 7, 0, 9, 0},
    {6, 0, 2, 0, 0, 0, 5, 0, 0},
    {0, 7, 0, 0, 6, 0, 0, 0, 0},
    {0, 0, 0, 9, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 7, 0},
    {0, 0, 9, 0, 0, 0, 8, 0, 6},
    {0, 6, 0, 7, 0, 0, 0, 2, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0}};

int S4[9][9] = {
    {5, 9, 7, 1, 3, 6, 2, 4, 8},
    {4, 8, 3, 2, 5, 7, 6, 9, 1},
    {6, 1, 2, 8, 9, 4, 5, 3, 7},
    {9, 7, 5, 4, 6, 3, 1, 8, 2},
    {2, 4, 8, 9, 7, 1, 3, 6, 5},
    {1, 3, 6, 5, 2, 8, 4, 7, 9},
    {7, 5, 9, 3, 4, 2, 8, 1, 6},
    {8, 6, 4, 7, 1, 5, 9, 2, 3},
    {3, 2, 1, 6, 8, 9, 7, 5, 4}};

bool userMark[9][9] = {{false}};
bool solverMark[9][9] = {{false}};

int main()

{
    bool gagne = false; //indique si le joueur a gagné, initialisé à false

    int choix;
    cout << "Choisissez une grille (1 à 4) : "; //Demande à l'utilisateur de choisir une grille
    cin >> choix;

//On utilise des pointeurs pour sélectionner la grille et la solution choisies par l'utilisateur
    int (*grille)[9] = nullptr; //Seront utilisés après pour initialiser l'objet Sudoku
    int (*solution)[9] = nullptr;

    int (*grille_array[4])[9] = { G1, G2, G3, G4 }; //Tableaux de pointeurs vers les grilles
    int (*solution_array[4])[9] = { S1, S2, S3, S4 };

    if (choix >= 1 && choix <= 4) { //Affectation
        grille = grille_array[choix - 1];
        solution = solution_array[choix - 1];
    } else {
        cout << "Choix invalide !";
        return 0;
    }

    Sudoku s(grille, solution);

    cout << "\nGrille de départ :";
    s.afficher();

    while (true) //Boucle principale du jeu
    {
        //On invite l'utilisateur à entrer une commande dans l'odre suivant : ligne, colonne, valeur. Il peut aussi demander de l'aide ou quitter le jeu
        cout << "\nEntrez ligne (1-9), colonne (1-9) et chiffre (ou 'a' pour aide, 'q' pour quitter) : ";
        string command;
        if (!(cin >> command)) break; //Quitte le programme si la valeur saisie est invalide

        if (command == "q" || command == "Q") {
            cout << "Au revoir !\n";
            break;
        }

        // Si l'utilisateur veut de l'aide : solveur 
        if (command == "a" || command == "A") {
            int line_help, column_help;
            cout << "Entrez la ligne (1-9) : ";
            if (!(cin >> line_help)) break; //Là encore, quitte si la valeur est invalide
            cout << "Entrez la colonne (1-9) : ";
            if (!(cin >> column_help)) break;
            line_help--; column_help--; //Retranche d'une unité pour correspondre aux coordonnées des cases (de 0 à 8)
            if (line_help < 0 || line_help > 8 || column_help < 0 || column_help > 8) { //Vérifie la validité des coordonnées
                cout << "Coordonnées invalides.\n";
            } else {
                s.provideHint(line_help, column_help); //Fournit l'aide
                cout << "Valeur ajoutée par le solveur en vert : " << VERT << solution[line_help][column_help] << RESET << "\n";
            }

            s.afficher();
            continue;
        }

        //L'utilisateur va rentrer une ligne, une colonne puis une valeur
        int line, column, number;
        //pour la ligne
        if (command.size() == 1 && isdigit(static_cast<unsigned char>(command[0]))) {
            line = command[0] - '0';
        } else {
            cout << "Saisie invalide.\n";
            continue;
}
        //pour la colonne
        if (command.size() == 1 && isdigit(static_cast<unsigned char>(command[0]))) {
            column = command[0] - '0';
        } else {
            cout << "Saisie invalide.\n";
            continue;
}
        //pour la valeur
        if (command.size() == 1 && isdigit(static_cast<unsigned char>(command[0]))) {
            number = command[0];
        } else {
            cout << "Saisie invalide.\n";
            continue;
}
        if (!(cin >> column >> number)) break;

        line--; //Retranche d'une unité pour correspondre aux coordonnées des cases (de 0 à 8)
        column--;

        //Dit si la combinaison est correcte, et met à jour la grille en conséquence
        if (s.checkAndSet(line, column, number))
        {
            cout << "Correct !\n";
        }
        else
        {
            cout << "Incorrect.\n";
        }

        s.afficher();

        if (s.estComplete()) { //Si la grille est complète, met fin au jeu
            gagne = true;
            break; 
        }

            
        
    }
    if (gagne) { //A la fin du jeu (si gagné), félicité le joueur 
    cout << "\n Bravo, sudoku terminé !\n";
}
    return 0;

}
