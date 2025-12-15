#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

// ANSI Color codes
#define RESET "\033[0m"
#define BLEU "\033[34m"   // User's correct input
#define VERT "\033[32m"   // Solver's hints

// Function declarations
void afficherGrille(int g[9][9], int originale[9][9], int solution[9][9]);
void selectionnerGrille(int choix, int*& grille, int*& solution);
bool verifierSaisie(int l, int c, int n, int solution[9][9]);
void demanderAide(int grille[9][9], int originale[9][9], int solution[9][9]);
bool estComplete(int g[9][9], int solution[9][9]);

// Sudoku grids and solutions
extern int G1[9][9];
extern int S1[9][9];
extern int G2[9][9];
extern int S2[9][9];
extern int G3[9][9];
extern int S3[9][9];
extern int G4[9][9];
extern int S4[9][9];

#endif