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
      char PP[10][10];
      int MP[10][10];
      int ik1;
      int ik2;
      int jk1;
      int jk2;
      int m=0;

    int TTL=0;
   int  H=1;
    pocatek(P,M,T1,T2,T11,T22,ik1,ik2,jk1,jk2);
    deska(P,M);
//     Pozice(P,M,T1,T2);
//      deska(P,M);
//     Pozice(P,M,T1,T2);
     TTL=0;
            std::cout<< TTL <<std::endl;
    while (TTL<10)
        {
            //Hraci cyklus...prozatim an pocet tahu...bude upraveno na remizu pripadne sach mat
            Pozice(P,PP,M,MP,T1,T2,T11,T22,ik1,ik2,jk1,jk2,H);
             deska(P,M);
             //Pozice(P,M,T1,T2);
            TTL=TTL+1;
           std::cout<<"  pokus"<<std::endl;
        }

    cout << "Hello world!" << endl;

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
while (m<256) {
    SetConsoleTextAttribute(h,m);
    cout << m<<" Hello world!" << endl;
    m=m+1;
 //pomocny skript pro urceni vhodne barvy poli i figurek

}


    return 0;
}
