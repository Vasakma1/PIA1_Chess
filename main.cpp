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
    int TTL=0;
   int  H=1;
    pocatek(P,M);
    deska(P,M);
//     Pozice(P,M,T1,T2);
//      deska(P,M);
//     Pozice(P,M,T1,T2);
     TTL=0;
            std::cout<< TTL <<std::endl;
    while (TTL<10)
        {
            Pozice(P,M,T1,T2,T11);
             deska(P,M);
             //Pozice(P,M,T1,T2);
            TTL=TTL+1;
            std::cout<<"  pokus"<<std::endl;
        }

    cout << "Hello world!" << endl;

    return 0;
}
