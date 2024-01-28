#include <iostream>
#include "sachovnice.h"
#include "tahy.h"
using namespace std;

int main()
{
    char P[10][10];     //Pole figurek na sachovnici
    int M[10][10];      // Pole obsazenosti...0 volne pole, 1 pole obsazene bilou figurkou, 2 pole obsazene cernou figurkou
     int T1[10][10];    // Pole pozic kam je mozne tahnout zvolenou bilou figurkou
     int T2[10][10];     // Pole pozic kam je mozne tahnout zvolenou cernou figurkou
      int T11[10][10];  // Pole pozic kam je mozne tahnout vsemi bilymi figurkami
      int T22[10][10];  // Pole pozic kam je mozne tahnout vsemi cernymi figurkami
      int TK1[10][10];  // Pole pozic kam je mozne tahnout bilym kralem
      int TK2[10][10];  // Pole pozic kam je mozne tahnout cernym kralem
      char PP[10][10];  //Pole pocatecnich pozic figurek na sachovnici pred kazdym tahem
      int MP[10][10];   // Pole obsazenosti pred kazdym tahem
      int ik1;          //radkovy index pozice bileho krale
      int ik2;          //radkovy index pozice cerneho krale
      int jk1;          //sloupcovy index pozice bileho krale
      int jk2;          //slpupcovy index pozice cerneho krale
      int mm=0;         // pomocna promennna
      int SACH[3];      // indikace sachu
        int MAT[3];     // indikace matu
        int PAT[3];     // indikace remizy
        int POCPT[3];   // pocet platnych tahu
        int POCPTK[3];  // pocet platnych tahu kralem
     int MIMO1[10];     // brani mimochodem bilym pesccem....rozpracovano
     int MIMO2[10];     // brani mimochodem cernym pescem....rozpracovano

bool NT=false;          // neplatny tah
        char OP[10][10][1000];  // Pole pro ulozeni pozic pro kontrolu jejich opakovani
    int TTL=0;  //pomocna prommenna
   int  H=1;    // index pro hrace...1 bile figurky...2 cerne figurky
   int ZH=1;    // zacatek hry
   PAT[0]=0;
   MAT[1]=0;
   MAT[2]=0;
   int KH[3];   // konec hry
   KH[0]=0;
    pocatek(P,M,T1,T2,T11,T22,ik1,ik2,jk1,jk2,POCPT,POCPTK,TK1,TK2);    // Puvodni pozice figurek
    deska(P,M);             //vykresleni figurek na sachovnici

            HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);   //indikace grafickeho rozhranni

    while (KH[0]==0)
        {
            //Hraci cyklus. upraveno na konec hry

            Pozice(P,PP,M,MP,T1,T2,T11,T22,TK1,TK2,ik1,ik2,jk1,jk2,H,OP,SACH,MAT,ZH,PAT,KH,MIMO1,MIMO2);    // Provedeni tahu

             deska(P,M);    //Vykresleni pozic figurek
             //Pozice(P,M,T1,T2);
         //   TTL=TTL+1;
            if(H==1) {H=2;} // Hraje druhy hrac
            else {H=1;}
         //  std::cout<<"  pokus"<<std::endl;
        }
   if (PAT[0]==1) {std::cout<<"Hra konci remizou, gratulujeme :) "<<std::endl;}
     if (MAT[1]==1) {std::cout<<"Vitezi bily hrac, gratulujeme :) "<<std::endl;}
       if (MAT[2]==2) {std::cout<<"Vitezi cerny hrac, gratulujeme :) "<<std::endl;}
    //cout << "Hello world!" << endl;


 //pomocny skript pro urceni vhodne barvy poli i figurek

// while (mm<256) {
   //SetConsoleTextAttribute(h,mm);
   // cout << mm<<" Hello world!" << endl;
   // mm=mm+1;
//}

//}


    return 0;
}
