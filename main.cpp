#include <iostream>
#include "sachovnice.h"
#include "tahy.h"
using namespace std;

int main() {
    // Definice proměnných
    char P[10][10];
    int M[10][10];
    int T1[10][10];
    int T2[10][10];
    int T11[10][10];
    int T22[10][10];
    int TK1[10][10];
    int TK2[10][10];
    char PP[10][10];
    int MP[10][10];
    int ik1, ik2, jk1, jk2;
    int mm = 0;
    int SACH[3];
    int MAT[3];
    int POCPT[3];
    int POCPTK[3];
    bool NT = false;
    char OP[10][10][1000];
    int TTL = 0;
    int H = 1;

    // Inicializace hrací desky
    pocatek(P, M, T1, T2, T11, T22, ik1, ik2, jk1, jk2, POCPT, POCPTK);
    deska(P, M);

    // Hlavní herní smyčka
    while (TTL < 20) {
        // Aktualizace pozice
        Pozice(P, PP, M, MP, T1, T2, T11, T22, TK1, TK2, ik1, ik2, jk1, jk2, H, OP, SACH, MAT);
        
        // Výpis herní desky
        deska(P, M);

        // Zvýšení počtu tahů
        TTL++;

        // Přepnutí hráče
        H = (H == 1) ? 2 : 1;

        // Debug výpis
        cout << "  pokus" << endl;
    }

    // Příklad použití Console API pro změnu barvy výstupu v příkazovém řádku
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    while (mm < 256) {
        SetConsoleTextAttribute(h, mm);
        cout << mm << " Hello world!" << endl;
        mm++;
        // Pomocný skript pro určení vhodné barvy polí i figurek
    }

    return 0;
}

