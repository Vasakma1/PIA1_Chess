#include <iostream>
#include "sachovnice.h"
#include "tahy.h"
using namespace std;

int main()
{
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
      int ik1;
      int ik2;
      int jk1;
      int jk2;
      int mm=0;
      int SACH[3];
        int MAT[3];
        int PAT[3];
        int POCPT[3];
        int POCPTK[3];
     int MIMO1[10];
     int MIMO2[10];

bool NT=false;
        char OP[10][10][1000];
    int TTL=0;
   int  H=1;
   int ZH=1;
   PAT[0]=0;
   MAT[1]=0;
   MAT[2]=0;
   int KH[3];
   KH[0]=0;
    pocatek(P,M,T1,T2,T11,T22,ik1,ik2,jk1,jk2,POCPT,POCPTK,TK1,TK2);
    deska(P,M);
//     Pozice(P,M,T1,T2);
//      deska(P,M);
//     Pozice(P,M,T1,T2);
     TTL=0;
            //std::cout<< TTL <<std::endl;

            HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    while (KH[0]==0)
        {
            //Hraci cyklus...prozatim an pocet tahu...bude upraveno na remizu pripadne sach mat
            Pozice(P,PP,M,MP,T1,T2,T11,T22,TK1,TK2,ik1,ik2,jk1,jk2,H,OP,SACH,MAT,ZH,PAT,KH,MIMO1,MIMO2);
             deska(P,M);
             //Pozice(P,M,T1,T2);
            TTL=TTL+1;
            if(H==1) {H=2;}
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
