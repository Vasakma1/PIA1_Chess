#include "sachovnice.h"
#include "tahy.h"
#include <iostream>

// Inicializace hrací desky
char pocatek(char P[10][10], int M[10][10]) {
    P[0][0] = ' ';
    P[0][9] = ' ';
    P[10][0] = ' ';
    P[10][10] = ' ';

    for (int j = 1; j < 9; j++) {
        for (int i = 8; i > 0; i--) {
            P[i][0] = char(i + 48);
            P[i][9] = char(i + 48);
            P[0][j] = char(j + 96);
            P[9][j] = char(j + 96);
            P[1][j] = '_'; // Chybějící figurky
            P[8][j] = '_'; // Chybějící figurky
            M[1][j] = 0;   // Chybějící figurky
            M[8][j] = 0;   // Chybějící figurky

            if (i > 2 && i < 7) {
                P[i][j] = '_';
                M[i][j] = 0;
            } else {
                P[2][j] = 'p';
                M[2][j] = 1;
                P[7][j] = 'p';
                M[7][j] = 2;
            }
        }
    }
}

// Výpis hrací desky
char deska(char P[10][10], int M[10][10]) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int B = 0;

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            B++;
            if ((M[i][j] == 0 || M[i][j] == 1 || M[i][j] == 2) && i != 0 && i != 9 && j != 0 && j != 9) {
                if (B % 2 == 0) {
                    SetConsoleTextAttribute(h, 34);
                } else {
                    SetConsoleTextAttribute(h, 24);
                }
            } else {
                SetConsoleTextAttribute(h, 7);
            }

            std::cout << P[i][j];
        }
        std::cout << std::endl;
        B++;
    }
    SetConsoleTextAttribute(h, 7);
}

