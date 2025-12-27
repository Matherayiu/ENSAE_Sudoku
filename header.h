#ifndef HEADER_H
#define HEADER_H

#include <iostream>

#define RESET "\033[0m"
#define BLEU  "\033[34m"
#define VERT  "\033[32m"

void afficherGrille(
    const int g[9][9],
    const int originale[9][9],
    const int solution[9][9],
    const bool userMark[9][9],
    const bool solverMark[9][9]
);

class Sudoku {
public:
    Sudoku(int g[9][9], int s[9][9]);

    void afficher() const;

    bool checkAndSet(int line, int column, int number);
    bool provideHint(int line, int column);
    bool estComplete() const;

private:
    int (*grille)[9];
    int (*solution)[9];
    int originale[9][9];

    bool userMark[9][9];
    bool solverMark[9][9];
};

extern int G1[9][9];
extern int S1[9][9];
extern int G2[9][9];
extern int S2[9][9];
extern int G3[9][9];
extern int S3[9][9];
extern int G4[9][9];
extern int S4[9][9];

#endif
