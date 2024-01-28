#include "sachovnice.h"
#include "tahy.h"
#include <iostream>

char pocatek(char P[10][10],int M[10][10],int T1[10][10],int T2[10][10],int T11[10][10], int T22[10][10],int ik1, int ik2, int jk1,int jk2,int POCPT[3],int POCPTK[3],int TK1[10][10], int TK2[10][10])
 {
  //Sachovnice bude pole 8x8 ale chceme mit na stranach legendu s pozicemi
  //Funkce pocatek zahrnuje pocatecni rozestaveni figur
    POCPT[1]=0;
    POCPT[2]=0;
    POCPTK[1]=0;
    POCPTK[2]=0;


    P[0][0]=' ';    //rohy, kde je legenda zbytecna
    P[0][9]=' ';
    P[9][0]=' ';
    P[9][9]=' ';
    for (int j=1;j<9;j++) {
          for (int i=8;i>0;i--) {
                T1[i][j]=0;     //vynulovani poli
                T2[i][j]=0;
                TK1[i][j]=0;
                TK2[i][j]=0;
                T11[i][j]=0;
                P[i][0]=char(i+48); //legenda pro radky
                P[i][9]=char(i+48);
                P[0][j]=char(j+96); // legenda pro sloupce
                P[9][j]=char(j+96);

                if(i>2&&i<7) {      //volne pozice na sachovnici
                    P[i][j]=' ';
                    M[i][j]=0;

                            }
                else {
                    P[2][j]='p';    //umisteni bilych pescu
                    M[2][j]=1;
                    P[7][j]='p';    //umosteni cernych pescu
                    M[7][j]=2;
                    }

                    }


               }
        P[1][5]='K';        //umisteni bileho krale
        M[1][5]=1;
        P[8][5]='K';        //umisteni cerneho krale
        M[8][5]=2;
        ik1=1;              //pozice bileho krale
        jk1=5;
        ik2=8;              //pozice cerneho krale
        jk2=5;
        P[1][4]='Q';        //umisteni bile kralovny
        M[1][4]=1;
        P[8][4]='Q';        //umisteni cerne kralovny
        M[8][4]=2;
//
        P[1][1]='R';        //umisteni bilych vezi
        M[1][1]=1;
        P[1][8]='R';
        M[1][8]=1;

        P[8][1]='R';        //umisteni cernych vezi
        M[8][1]=2;
        P[8][8]='R';
        M[8][8]=2;

        P[1][3]='B';        // umisteni bilych strelcu
        M[1][3]=1;
        P[1][6]='B';
        M[1][6]=1;

        P[8][3]='B';        //umisteni cernych strelcu
        M[8][3]=2;
        P[8][6]='B';
        M[8][6]=2;

         P[1][2]='H';       //umisteni bilych koni
        M[1][2]=1;
        P[1][7]='H';
        M[1][7]=1;

        P[8][2]='H';        // umisteni cernych koni
        M[8][2]=2;
        P[8][7]='H';
        M[8][7]=2;


        }





char deska (char P[10][10], int M[10][10]) {
    //funkce deska vykresluje aktualni stav na sachovnici
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);       //inicializace grafickeho vystupu
    //tato funkce bude definovat barvu figurek a barvu poli
    int B=1; // B strida hodnoty 0 a 1, jde o rozliseni svetlych a tmavych poli na sachovnici


for (int i=9;i>=0;i--)
    {
    for (int j=0;j<10;j++)
        {
            B=B+1;
            if(M[i][j]==0&&i!=0&&i!=9&&j!=0&&j!=9) // pokud je pole na sachovnici a neobszene
                {
                   if (B%2==0){
                             SetConsoleTextAttribute(h,127);

                                }
                   else
                            {
                                SetConsoleTextAttribute(h,143);
                            }

            }
            else if(M[i][j]==1&&i!=0&&i!=9&&j!=0&&j!=9)  // pokud je pole na sachovnici a obsazene bilou figurkou
                {
                   if (B%2==0){
                             SetConsoleTextAttribute(h,127);

                                }
                   else
                            {
                                SetConsoleTextAttribute(h,143);
                            }

            }
            else if(M[i][j]==2&&i!=0&&i!=9&&j!=0&&j!=9)     // pokud je pole na sachovnici a obsazene cernou figurkou
                {
                   if (B%2==0){
                             SetConsoleTextAttribute(h,121);

                                }
                   else
                            {
                                SetConsoleTextAttribute(h,137);
                            }

            }








           else {
             SetConsoleTextAttribute(h,7);  // Pole mimo sachovnici


            }
             std::cout<<P[i][j];

        }
    std::cout<<std::endl;
    B=B+1;
    }
    SetConsoleTextAttribute(h,7);   //nastaveni puvodni barvy pro textove prikazy


}
