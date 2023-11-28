#include "tahy.h"
#include "sachovnice.h"
#include <iostream>
#include <string>


char Pozice (char P[10][10], int M[10][10], int T1[10][10],int T2[10][10],int T11[10][10]){
std::string Pozv,Pozc;
int i;
int j;
int iv;
int ic;
int jv;
int jc;
char kv;
char kc;
char lv;
char lc;
int H=1;
int iv1;
int iv2;
int jv1;
int jv2;
int ic1;
int ic2;
int jc1;
int jc2;
for (int iv=8;iv>0;iv--) {
               for (int jv=1;jv<9;jv++) {
                    T1[iv][jv]=0;
                    T2[iv][jv]=0;
                    T11[iv][jv]=0;
               }
        }

std::cout<<"Zadej vychozi pozici"<<std::endl;
std::cin>>Pozv;
kv=Pozv[1];
lv=Pozv[0];
int kiv=int(kv);
int liv=int(lv);
iv=kiv-48;
jv=liv-96;
if (liv>96&&liv<105&&kiv>48&&kiv<57) { std::cout<<"Zadana pozice je na sachovnici" <<std::endl;}
else {std::cout<<"Zadana pozice neni na sachovnici" <<std::endl;}
if (Pozv.size() == 2) {
    std::cout<<"Zadana pozice je ok" <<std::endl;
}
else {
        std::cout<<"Zadana pozice je spatne zadana"<<std::endl;

    }
std::cout<<"Zadana pozice je" <<Pozv<<std::endl;

std::cout<<"Slozky jsou " <<iv<<"   "<<jv<<std::endl;

std::cout<<"M je " <<M[iv][jv]<<std::endl;
if (M[iv][jv]==1&&H==2||M[iv][jv]==1&&H==2||M[iv][jv]==0) {std::cout<<"Na pozici neni hratelna figurka"<<std::endl;}
else {std::cout<<"Zadana pozice obsahuje hratelnou figurku"<<std::endl;}

       for (int iv=8;iv>0;iv--) {
               for (int jv=1;jv<9;jv++) {

                std::cout<<P[iv][jv];
          }
            std::cout<<std::endl;
}


std::cout<<"Zadej cilovou pozici"<<std::endl;
std::cin>>Pozc;
 kc=Pozc[1];
 lc=Pozc[0];
int kic=int(kc);
int lic=int(lc);
ic=kic-48;
jc=lic-96;
if (lic>96&&lic<105&&kic>48&&kic<57) { std::cout<<"Zadana pozice je na sachovnici" <<std::endl;}
else {std::cout<<"Zadana pozice neni na sachovnici" <<std::endl;}
if (Pozc.size() == 2) {
    std::cout<<"Zadana pozice je ok" <<std::endl;
}
else {
        std::cout<<"Zadana pozice je spatne zadana"<<std::endl;

    }
std::cout<<"Zadana pozice je" <<Pozc<<std::endl;

std::cout<<"Slozky jsou " <<ic<<"   "<<jc<<std::endl;

std::cout<<"M je " <<M[ic][jc]<<std::endl;
if (M[ic][jc]==1||M[ic][jc]==2) {std::cout<<"Zadana pozice je obsazena"<<std::endl;}
else {std::cout<<"Zadana pozice neni obsazena"<<std::endl;}

if (H==1) {
    iv1=iv;
    jv1=jv;
    ic1=ic;
    jc1=jc;
}
else if (H==2) {
    iv2=iv;
    jv2=jv;
    ic2=ic;
    jc2=jc;
}

       for (int ic=8;ic>0;ic--) {
               for (int jc=1;jc<9;jc++) {

                std::cout<<P[ic][jc];
          }
            std::cout<<std::endl;
        }


for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {
                    if(P[iv][jv]=='p') {tahp1(P,M,T1,T11,iv1,ic1,jv1,jc1);}
               }
               }


for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {


                     std::cout<<T1[i][j];
               }
               std::cout<<std::endl;
        }
  std::cout<<std::endl;
for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {


                     std::cout<<T11[i][j];
               }
               std::cout<<std::endl;
        }
 std::cout<<std::endl;
 for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {


                     std::cout<<P[i][j];
               }
                   std::cout<<std::endl;
 }

return 0;

}
char tahp1 (char P[10][10], int M[10][10], int T1[10][10],int T11[10][10], int iv1, int ic1, int jv1, int jc1){
    int i;
    int j;

    //std::cout<<i<<"  "<<j<<std::endl;
    for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {
                    T11[i][j]=0;
                    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1&&P[i][j]=='p'){
                        if(M[i+1][j]==0) {
                            T1[i+1][j]=1;}
                        if(M[i+1][j-1]==2) {
                            T1[i+1][j-1]==1;
                        }
                        if(M[i+1][j+1]==2) {
                            T1[i+1][j+1]==1;
                        }
                }
               }
        }
        i=iv1;
        j=jv1;
       if(i>0&&i<9&&j>0&&j<9){
                    if(M[i+1][j]==0) {
                        T11[i+1][j]=1;}
                    if(M[i+1][j-1]==2) {
                        T11[i+1][j-1]=1;
                    }
                    if(M[i+1][j+1]==2) {
                        T11[i+1][j+1]=1;
                    }

            }
        if (T11[ic1][jc1]==1) {
            P[ic1][jc1]='p';
            P[iv1][jv1]='_';
        }

//T1[2][3]=1;
}

char tahp2 (char P[10][10], int M[10][10], int T2[10][10],int T22[10][10], int iv2, int ic2, int jv2, int jc2){
    int i;
    int j;
    i=iv2;
    j=jv2;

    //std::cout<<i<<"  "<<j<<std::endl;
    if(i>0&&i<9&&j>0&&j<9){
            if(M[i-1][j]==0) {
                T2[i-1][j]=1;}
            if(M[i-1][j-1]==1) {
                T2[i-1][j-1]=1;
            }
             if(M[i-1][j+1]==1) {
                T2[i-1][j+1]=1;
            }

        }




}
