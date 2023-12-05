#include "sachovnice.h"
#include "tahy.h"
#include <iostream>

char pocatek(char P[10][10],int M[10][10],int T1[10][10],int T2[10][10],int T11[10][10], int T22[10][10],int ik1, int ik2, int jk1,int jk2) {
  //Sachovnice bude pole 8x8 ale chceme mit na stranach legendu s pozicemi
  //Funkce pocatek zahrnuje pocatecni rozestaveni figur
    P[0][0]=' ';
    P[0][9]=' ';
    P[9][0]=' ';
    P[9][9]=' ';
    for (int j=1;j<9;j++) {
          for (int i=8;i>0;i--) {
                T1[i][j]=0;
                T2[i][j]=0;
                T11[i][j]=0;
                P[i][0]=char(i+48);
                P[i][9]=char(i+48);
                P[0][j]=char(j+96);
                P[9][j]=char(j+96);
                P[1][j]='_'; //chybejici figurky
                P[8][j]='_'; //chybejici figurky
                M[1][j]=0; //chybejici figurky
                M[8][j]=0; //chybejici figurky
                if(i>2&&i<7) {
                    P[i][j]='_';
                    M[i][j]=0;

                            }
                else {
                    P[2][j]='p';
                    M[2][j]=1;
                    P[7][j]='p';
                    M[7][j]=2;
                    }

                    }


               }
        P[1][5]='k';
        M[1][5]=1;
        P[8][5]='k';
        M[8][5]=2;
        ik1=1;
        jk1=5;
        ik2=8;
        jk2=5;
        }
    //for (int i=8;i>0;i--) {
    //    P[i][0]=char(i+48);
      //  P[i][9]=char(i+48);


 //P[4][2]='p';
 //P[1][2]='p';
 //P[8][2]='p';

//char deska (char P[10][10], int M[10][10]) {
   // HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
   // int B=0;
   // P[5][7]='p';
//for (int i=9;i>=0;i--)
   // {
   // for (int j=0;j<10;j++)
      //  {
        //    B=B+1;
        //    if(P[i][j]=='p'&&i!=0&&i!=9&&j!=0&&j!=9) {
                 //  if (B%2==0){
                     //        SetConsoleTextAttribute(h,34);
                     //         std::cout<<P[i][j];
                               // }
                 //  else
                        //    {
                            //    SetConsoleTextAttribute(h,24);
                           //  std::cout<<P[i][j];}

             // SetConsoleTextAttribute(h,35);

           //   std::cout<<"p";


          //  }
         //   else if(P[i][j]=='p'&&i!=0&&i!=9&&j!=0&&j!=9) {
             // SetConsoleTextAttribute(h,23);
             // std::cout<<"p";
            // std::cout<<P[i][j];

            //}
           // else if (i!=0&&i!=9&&j!=0&&j!=9) {
                    // if(P[i][j]=='p'&&i!=0&&i!=9&&j!=0&&j!=9) {
                 //  if (B%2==0){
                           //  SetConsoleTextAttribute(h,35);
                             //   }
                  // else
                           // {SetConsoleTextAttribute(h,25);}
                     //}
          //  SetConsoleTextAttribute(h,62);
           // std::cout<<"_";

          //  }
          // else {
          //   SetConsoleTextAttribute(h,7);
          //   std::cout<<P[i][j];

        //    }

      //  }
    //std::cout<<std::endl;
   // B=B+1;
   // }
   // SetConsoleTextAttribute(h,7);


//}



char deska (char P[10][10], int M[10][10]) {
    //funkce deska vykresluje aktualni stav na sachovnici
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    //tato funkce bude definovat barvu figurek a barvu poli
    int B=0;
   // P[5][7]='p';
for (int i=9;i>=0;i--)
    {
    for (int j=0;j<10;j++)
        {
            B=B+1;
            if(M[i][j]==0&&i!=0&&i!=9&&j!=0&&j!=9)
                {
                   if (B%2==0){
                             SetConsoleTextAttribute(h,127);

                                }
                   else
                            {
                                SetConsoleTextAttribute(h,143);
                            }
                    //std::cout<<P[i][j];
            }
            else if(M[i][j]==1&&i!=0&&i!=9&&j!=0&&j!=9)
                {
                   if (B%2==0){
                             SetConsoleTextAttribute(h,127);

                                }
                   else
                            {
                                SetConsoleTextAttribute(h,143);
                            }
                   // std::cout<<P[i][j];
            }
            else if(M[i][j]==2&&i!=0&&i!=9&&j!=0&&j!=9)
                {
                   if (B%2==0){
                             SetConsoleTextAttribute(h,112);

                                }
                   else
                            {
                                SetConsoleTextAttribute(h,128);
                            }

            }








           else {
             SetConsoleTextAttribute(h,7);
             //std::cout<<P[i][j];

            }
             std::cout<<P[i][j];

        }
    std::cout<<std::endl;
    B=B+1;
    }
    SetConsoleTextAttribute(h,7);


}
