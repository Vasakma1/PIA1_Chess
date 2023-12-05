#include "tahy.h"
#include "sachovnice.h"
#include <iostream>
#include <string>


char Pozice (char P[10][10], char PP[10][10], int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10],int T11[10][10], int T22[10][10],int ik1, int ik2, int jk1,int jk2,int H)
{
    //funkce pozice zajistuje zadani pocatecni a cilove pozice, jaka figurka se na dane pozici nachazi
    //a implenetuje na danou figurku prislusnou funkci pro tah, pripadne kontroluje pozici krale proti matu ...bude doplneno
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
int iv1;
int iv2;
int jv1;
int jv2;
int ic1;
int ic2;
int jc1;
int jc2;
int k=0;
int l=0;
bool PT1=false;
bool PT2=false;
bool PT;
for (int i=8;i>0;i--) {
               for (int j=1;j<9;j++) {

                    T11[i][j]=0;
                    T22[i][j]=0;
                                    }
                    }
if (H==1) {PT=PT1;}
else {PT=PT2;}
while(PT==false){
    std::cout<<"Zadej vychozi pozici"<<std::endl;
    std::cin>>Pozv;
    kv=Pozv[1];
    lv=Pozv[0];
    int kiv=int(kv);
    int liv=int(lv);
    iv=kiv-48;
    jv=liv-96;
    if (liv>96&&liv<105&&kiv>48&&kiv<57) { std::cout<<"Zadana pozice je na sachovnici" <<std::endl;}
    else {
            std::cout<<"Zadana pozice neni na sachovnici" <<std::endl;
            break;
            }
    if (Pozv.size() == 2) {
    std::cout<<"Zadana pozice je ok" <<std::endl;
            }
    else {
        std::cout<<"Zadana pozice je spatne zadana"<<std::endl;
        break;

        }
    std::cout<<"Zadana pozice je" <<Pozv<<std::endl;

    std::cout<<"Slozky jsou " <<iv<<"   "<<jv<<std::endl;

    std::cout<<"M je " <<M[iv][jv]<<std::endl;
    if (M[iv][jv]==1&&H==2||M[iv][jv]==2&&H==1||M[iv][jv]==0) {
                                        std::cout<<"Na pozici neni hratelna figurka"<<std::endl;
                                        break;
                                        }
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
            break;

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
        for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                for (int j=1;j<9;j++) {
                        PP[i][j]=P[i][j];
                        MP[i][j]=M[i][j];
                }
        }

    if(P[iv][jv]=='p') {
            //Zjistim, ze se na zvolene pozici nachazi figurka pesec
            if (H==1){
                                    tahp1(P,PP,M,MP,T1,T2,T11,iv1,ic1,jv1,jc1,k,l,H);


                            }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,T22,iv2,ic2,jv2,jc2,k,l,H);

                            }
                        }

    for ( i=8;i>0;i--) {
            for (int j=1;j<9;j++) {
                    //Zde prochazim cele pole sachovnice kvuli zjisteni potencialnich "nebezpecnych" pozic pro krale
                    k=i;
                    l=j;
                    if(P[k][l]=='p') {

                            if (H==1){
                                    tahp1(P,PP,M,MP,T1,T2,T11,iv1,ic1,jv1,jc1,k,l,H);
                                  //  tahp2(P,PP,M,T2,T22,iv2,ic2,jv2,jc2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,T22,iv2,ic2,jv2,jc2,k,l,H);
                                   // tahp1(P,PP,M,T1,T11,iv1,ic1,jv1,jc1);
                                }
                                    }

                            }
                    }
                    //Kontrola proti matu,,,zatim s chybou proto odkomentovano
   // if(H==1) {
     //   if (T2[ik1][jk1]==2) {
              //  std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
               // break;

                           // }
         //   }
   // else if (T1[ik2][jk2]==1) {
          //  std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
          //  break;
                            //    }


    for ( i=8;i>0;i--) {

            //nasledujici casti jsou jen pomocne vypisy
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

PT=true;
}

return 0;

//}
}
char tahp1 (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10],int T11[10][10], int iv1, int ic1, int jv1, int jc1, int k, int l, int H)
{   //funkce ktera definuje tahy pesce 1, cili bileho hrace
    int i;
    int j;
    i=iv1;
    j=jv1;
    bool PT1;
    bool PT2;
    // nasledujici if dava pro konkretni vychozi pozici volne tahy (Nejsou vsechny, budou doplneny)
     if(i>0&&i<9&&j>0&&j<9&&H==1){
                    if(M[i+1][j]==0) {
                        T11[i+1][j]=1;}
                    if(M[i+1][j-1]==2) {
                        T11[i+1][j-1]=1;
                                        }
                    if(M[i+1][j+1]==2) {
                        T11[i+1][j+1]=1;
                                        }

                                }
         if(H==1){
                if (T11[ic1][jc1]==1) {
                    P[ic1][jc1]='p';
                    M[ic1][jc1]=1;
                    P[iv1][jv1]='_';
                    M[iv1][jv1]=0;
                                        }
                else {
                    std::cout<<"Neplatny tah"<<std::endl;

//Kontrola jestli se mohu dostat figurkou na danou pozici platnym tahem
                    }
                }


      i=k;
      j=l;
    //std::cout<<i<<"  "<<j<<std::endl;
    //for ( i=8;i>0;i--) {
           //    for (int j=1;j<9;j++) {
                 //   T11[i][j]=0;

                 // Vsechny mozne tahy pro danou figurku bilou
                    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1){
                       if(M[i+1][j]==0) {
                            T1[i+1][j]=1;}
                        if(M[i+1][j-1]==2) {
                            T1[i+1][j-1]==1;
                                            }
                       if(M[i+1][j+1]==2) {
                           T1[i+1][j+1]==1;
                                            }
                                                        }
           //Vsechny mozne tahy pro figurku cernou
        if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2){
            if(M[i-1][j]==0) {
                T2[i-1][j]=2;}
            if(M[i-1][j-1]==1) {
                T2[i-1][j-1]=2;
                                }
             if(M[i-1][j+1]==1) {
                T2[i-1][j+1]=2;
                                }

                                        }
           //    }
       // }




//T1[2][3]=1;
}

char tahp2 (char P[10][10], char PP[10][10], int M[10][10],int MP[10][10], int T2[10][10],int T1[10][10],int T22[10][10], int iv2, int ic2, int jv2, int jc2, int k, int l,int H)
{  //funkce ktera definuje tahy pesce 2, cili cerneho hrace
    int i;
    int j;
    bool PT1;
    bool PT2;
     i=iv2;
    j=jv2;

            if(M[i-1][j]==0) {
                T22[i-1][j]=1;}
            if(M[i-1][j-1]==1) {
                T22[i-1][j-1]=2;
                                }
             if(M[i-1][j+1]==1) {
                T22[i-1][j+1]=2;
                                }

       if (H==2)      {
        if (T22[ic2][jc2]==2) {
            P[ic2][jc2]='p';
            M[ic2][jc2]=2;
            P[iv2][jv2]='_';
            M[iv2][jv2]=0;
                            }
          else {
                    std::cout<<"Neplatny tah"<<std::endl;

                }
                    }

    //std::cout<<i<<"  "<<j<<std::endl;
    //for ( i=8;i>0;i--) {
          //     for (int j=1;j<9;j++) {
           //Vsechny mozne tahy pro figurku cernou
    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2){
            if(M[i-1][j]==0) {
                T2[i-1][j]=2;}
            if(M[i-1][j-1]==1) {
                T2[i-1][j-1]=2;
                                }
             if(M[i-1][j+1]==1) {
                T2[i-1][j+1]=2;
                                }
                                        }

        //Vsechny mozne tahy pro figurku bilou                             }

     if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1){
                       if(M[i+1][j]==0) {
                            T1[i+1][j]=1;}
                        if(M[i+1][j-1]==2) {
                            T1[i+1][j-1]==1;
                                            }
                       if(M[i+1][j+1]==2) {
                           T1[i+1][j+1]==1;
                                        }
               //}
    //}


                                        }
}
