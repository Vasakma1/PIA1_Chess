#include "sachovnice.h"
#include "tahy.h"
#include <iostream>

// Inicializace hrací desky
char pocatek(char P[10][10], int M[10][10], int T1[10][10], int T2[10][10], int T11[10][10], int T22[10][10], int& ik1, int& ik2, int& jk1, int& jk2, int POCPT[3], int POCPTK[3]) {
    //Sachovnice bude pole 8x8 ale chceme mit na stranach legendu s pozicemi
    //Funkce pocatek zahrnuje pocatecni rozestaveni figur
    POCPT[1] = 0;
    POCPT[2] = 0;
    POCPTK[1] = 0;
    POCPTK[2] = 0;

    P[0][0] = ' ';
    P[0][9] = ' ';
    P[9][0] = ' ';
    P[9][9] = ' ';

    for (int j = 1; j < 9; j++) {
        for (int i = 8; i > 0; i--) {
            T1[i][j] = 0;
            T2[i][j] = 0;
            T11[i][j] = 0;
            P[i][0] = char(i + 48);
            P[i][9] = char(i + 48);
            P[0][j] = char(j + 96);
            P[9][j] = char(j + 96);
            P[1][j] = ' '; // Chybějící figurky
            P[8][j] = ' '; // Chybějící figurky
            M[1][j] = 0;   // Chybějící figurky
            M[8][j] = 0;   // Chybějící figurky

            if (i > 2 && i < 7) {
                P[i][j] = ' ';
                M[i][j] = 0;
            } else {
                P[2][j] = 'p';
                M[2][j] = 1;
                P[7][j] = 'p';
                M[7][j] = 2;
            }
        }
    }

    P[1][5] = 'K';
    M[1][5] = 1;
    P[8][5] = 'K';
    M[8][5] = 2;
    ik1 = 1;
    jk1 = 5;
    ik2 = 8;
    jk2 = 5;
    P[1][4] = 'Q';
    M[1][4] = 1;
    P[8][4] = 'Q';
    M[8][4] = 2;

    P[1][1] = 'R';
    M[1][1] = 1;
    P[1][8] = 'R';
    M[1][8] = 1;
    P[8][1] = 'R';
    M[8][1] = 2;
    P[8][8] = 'R';
    M[8][8] = 2;

    P[1][3] = 'B';
    M[1][3] = 1;
    P[1][6] = 'B';
    M[1][6] = 1;
    P[8][3] = 'B';
    M[8][3] = 2;
    P[8][6] = 'B';
    M[8][6] = 2;
}

// Výpis hrací desky
char deska(char P[10][10], int M[10][10]) {
    // Funkce deska vykresluje aktualni stav na sachovnici
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    // Tato funkce bude definovat barvu figurek a barvu poli
    int B = 1;

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            B = B + 1;
            if ((M[i][j] == 0 || M[i][j] == 1 || M[i][j] == 2) && i != 0 && i != 9 && j != 0 && j != 9) {
                if (B % 2 == 0) {
                    SetConsoleTextAttribute(h, 127);
                } else {
                    SetConsoleTextAttribute(h, 143);
                }
            } else {
                SetConsoleTextAttribute(h, 7);
            }

            std::cout << P[i][j];
        }
        std::cout << std::endl;
        B = B + 1;
    }
    SetConsoleTextAttribute(h, 7);
}

