// Ce que fait notre code : il affiche des grilles à l'utilisateur, il connait déjà les réponses aux 4 sudokus, l'utilisateur entre une combinaison
//  et le code vérifie si c'est le bon chiffre.
//  Pour rentrer un chiffre, le code demande le numéro de la ligne et le numéro de la colonne pour positionner la valeur puis on note la
//  valeur : exemple j'écris : 1 3 8 : ligne 1 colonne 3 valeur 8.
// Pour demander de l'aide, il suffit de cliquer sur 'a' puis de rentrer les coordonnées de la case (ligne colonne)
// exemple : a 2 3 ligne 2 colonne 3

#include <iostream>
#include <sstream>
#include "header.h"
using namespace std;

Sudoku::Sudoku(int g[9][9], int s[9][9])
{
    grille = g;
    solution = s;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            originale[i][j] = g[i][j];
            userMark[i][j] = false;
            solverMark[i][j] = false;
        }
}

bool Sudoku::checkAndSet(int line, int column, int number)
{                                                         // Dit si la combinaison est correcte, et met à jour la grille en conséquence
    if (line < 0 || line > 8 || column < 0 || column > 8) // Vérifie la validité des coordonnées
        return false;
    if (originale[line][column] != 0) // Vérifie que la case n'est pas déjà remplie dans la grille originale
        return false;

    if (solution[line][column] == number)
    { // Vérifite si la valeur est correcte
        grille[line][column] = number;
        userMark[line][column] = true;
        solverMark[line][column] = false;
        return true; // la valeur est correcte, et sera affichée en bleu
    }
    return false;
}

bool Sudoku::provideHint(int line, int column)
{
    if (line < 0 || line > 8 || column < 0 || column > 8) // Vérifie la validité des coordonnées
        return false;
    if (originale[line][column] != 0) // Vérifie que la case n'est pas déjà remplie dans la grille originale
        return false;

    grille[line][column] = solution[line][column];
    solverMark[line][column] = true;
    userMark[line][column] = false;
    return true; // la valeur est ajoutée par le solveur, et sera affichée en vert
}

bool Sudoku::estComplete() const
{ // Vérifie si la grille est complète
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grille[i][j] != solution[i][j])
                return false;
    return true;
}

void afficherGrille(
    const int g[9][9],
    const int originale[9][9],
    const int solution[9][9],
    const bool userMark[9][9],
    const bool solverMark[9][9])
{
    cout << "\n┌───────┬───────┬───────┐\n"; // le haut de la grille

    for (int i = 0; i < 9; i++)
    {
        cout << "│ ";
        for (int j = 0; j < 9; j++)
        {
            if (g[i][j] == 0)
            { // les cases vides sont remplies par un point
                cout << ". ";
            }
            else if (originale[i][j] == 0 && g[i][j] == solution[i][j])
            { // Quand une valeur correcte est ajoutée...
                if (solverMark[i][j])
                    cout << VERT << g[i][j] << RESET << " "; //..par le solveur, le nombre est affiché en vert
                else if (userMark[i][j])
                    cout << BLEU << g[i][j] << RESET << " "; //.....par l'utilisateur, le nombre est affiché en bleu
            }
            else
            {
                cout << g[i][j] << " ";
            }

            if ((j + 1) % 3 == 0)
                cout << "│ ";
        }
        cout << "\n";
        if ((i + 1) % 3 == 0 && i != 8) // Ajoute les barres de séparation verticales toutes les trois valeurs
            cout << "├───────┼───────┼───────┤\n";
    }
    cout << "└───────┴───────┴───────┘\n"; // affiche le bas de la grille
}

void Sudoku::afficher() const
{
    afficherGrille(grille, originale, solution, userMark, solverMark);
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

int main()
{
    int choix;
    cout << "Choisissez une grille (1 à 4) : ";
    cin >> choix;

    int (*grille_array[4])[9] = {G1, G2, G3, G4}; // Tableaux de pointeurs vers les grilles
    int (*solution_array[4])[9] = {S1, S2, S3, S4};

    if (choix < 1 || choix > 4)
    {
        cout << "Choix invalide.\n";
        return 0;
    }

    Sudoku s(grille_array[choix - 1], solution_array[choix - 1]); // Affectation de la grille chosie
    cout << "\nGrille de départ :";
    s.afficher();

    cin.ignore(); // Ignore le caractère de nouvelle ligne restant après l'entrée précédente. Essentiel pour que "MERCI D'ENTRER..." ne soit affiché qu'une fois.

    while (true)
    { // Boucle principale du jeu
        cout << "\nMERCI D'ENTRER TOUTE COMBINAISON AVEC DES ESPACES. Pour jouer, entrez ligne (1-9), colonne (1-9) et chiffre. Pour de l'aide, appuyez sur 'a' puis entrez la ligne et la colonne de la case que vous souhaitez remplir. Appuyez sur 'q' pour quitter) :  ";
        string command; // combinaison entrée par l'utiisateur
        getline(cin, command);

        if (command == "q" || command == "Q")
        { // Arrête le jeu
            cout << "Au revoir !\n";
            break;
        }

        if (command[0] == 'a' || command[0] == 'A')
        { // Si l'utilisateur veut de l'aide : solveur
            int line_help, column_help;
            stringstream command_help(command.substr(1));  // Create a stream after the charatecter 'a'
            command_help >> line_help >> column_help;      // and affects the first character to line_help and the second to column_help
            s.provideHint(line_help - 1, column_help - 1); // Fournit l'aide en prenant en compte le décalage de 1
            s.afficher();
            continue;
        }

        int line, column, value;
        stringstream command_stream(command);
        if (!(command_stream >> line >> column >> value))
        { // Affecte la combinaison entrée par l'utilisateur. Si problème, affiche un message d'erreur
            cout << "Commande invalide.\n";
            continue;
        }

        if (s.checkAndSet(line - 1, column - 1, value)) // Vérifie et met à jour la grille en conséquence
            cout << "Correct !\n";
        else
            cout << "Incorrect.\n";

        s.afficher();

        if (s.estComplete())
        { // Si la grille est complète, met fin au jeu
            cout << "\nBravo, sudoku terminé !\n";
            break; // Permet de sortir de la boucle while
        }
    }
    return 0;
}