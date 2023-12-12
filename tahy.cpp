#include "tahy.h"
#include "sachovnice.h"
#include <iostream>
#include <string>


char Pozice (char P[10][10], char PP[10][10], int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10],int T11[10][10], int T22[10][10],int TK1[10][10], int TK2[10][10], int ik1, int ik2, int jk1,int jk2,int H,char OP[10][10][1000],int SACH[3], int MAT[3],int ZH, int PAT[3],int KH[3],int MIMO1[10],int MIMO2[10])
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
int n=0;
bool PT1=false;
bool PT2=false;
bool PT;
int POCPT[3];
int POCPTK[3];
int NT[3];
bool T;
int pom2[1000];
int pom3;
int PO[1000];
int ZT[3];
ZT[0]=1;
int KT[3];
KT[0]=0;
int ZS[3];
ZS[0]=0;
int A1[100];
int A2[100];
int B1[100];
int B2[100];
char NR;
for (int i=8;i>0;i--) {
               for (int j=1;j<9;j++) {

                    T11[i][j]=0;
                    T22[i][j]=0;
                                    }
                    }
if (H==1) {PT=PT1;}
else {PT=PT2;}
while (PT==false&&KH[0]==0)
{


     NT[0]=0;
    while(PT==false){

    std::cout<<std::endl;
    if (H==1) {std::cout<<"Hraje bily"<<std::endl;  }
    else {std::cout<<"Hraje cerny"<<std::endl;  }

    kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
    if (H==1&&POCPT[1]==0&&ZH==0)
        {
            if (SACH[1]==1) {MAT[2]=2;}
            else {PAT[0]=1;}
           // KH[0]=1;
        }


     if (H==2&&POCPT[2]==0&&ZH==0)
        {
            if (SACH[2]==2) {MAT[1]=1;}
            else {PAT[0]=1;}
          //  KH[0]=1;
        }



    if(SACH[1]==1&&H==1)

            {
                ZS[0]=0;
                //std::cout<<"Sach 11"<<SACH<<std::endl;
                kontrola_matu (P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,PP,MP,A1,A2,B1,B2,KT,ZS,MIMO1,MIMO2);
                if (ZS[0]==0) {MAT[2]=2;
                               // KH[0]=1;
                               }

            }
    if(SACH[2]==2&&H==2)

            {
                ZS[0]=0;
                //std::cout<<"Sach 11"<<SACH<<std::endl;
                kontrola_matu (P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,PP,MP,A1,A2,B1,B2,KT,ZS,MIMO1,MIMO2);
                 if (ZS[0]==0) {MAT[1]=1;
                              //  KH[0]=1;
                              }


            }
    if(MAT[1]==1||MAT[2]==2||PAT[0]==1)
        {
            KH[0]==1;
        }


//std::cout<<"SACH1= "<<SACH[1]<<std::endl;
//std::cout<<"SACH2= "<<SACH[2]<<std::endl;
    //std::cout<<"Pocet PT 1 "<<POCPT[1]<<std::endl;
    // std::cout<<"Pocet PT 2 "<<POCPT[2]<<std::endl;

   // std::cout<<"Pocet PTK 1 "<<POCPTK[1]<<std::endl;
   //  std::cout<<"Pocet PTK 2 "<<POCPTK[2]<<std::endl;

    POCPT[1]=0;
     POCPT[2]=0;
    POCPTK[1]=0;
    POCPTK[2]=0;
    ZS[0]=0;
    ZT[0]=0;
    ZH=0;
    std::cout<<"Zadej vychozi pozici"<<std::endl;
    std::cin>>Pozv;

    if(Pozv=="draw")
    {
        if (H==1)
            {
            std::cout<<"Bily hrac nabizi remizu. Souhlasi cerny hrac? (Zadejte a/n)"<<std::endl;
             std::cin>>NR;

              while(NR!='a'&&NR!='n')
                {
                   std::cout<<"Spatne zadano! (Zadejte a/n)"<<std::endl;
                    std::cin>>NR;
                }
               if (NR=='a')
               {
                    PAT[0]=1;
                    KH[0]=1;
               }
               else if (NR=='n')
               {
                    std::cout<<"Cerny hrac s remizou nesouhlasi"<<std::endl;
                    std::cout<<"Zadej vychozi pozici"<<std::endl;
                    std::cin>>Pozv;
               }


            }
    }

     if(Pozv=="draw")
    {
        if (H==2)
            {
            std::cout<<"Cerny hrac nabizi remizu. Souhlasi bily hrac? (Zadejte a/n)"<<std::endl;
             std::cin>>NR;

              while(NR!='a'&&NR!='n')
                {
                   std::cout<<"Spatne zadano! (Zadejte a/n)"<<std::endl;
                    std::cin>>NR;
                }
               if (NR=='a')
               {
                    PAT[0]=1;
                    KH[0]=1;
               }
               else if (NR=='n')
               {
                    std::cout<<"Bily hrac s remizou nesouhlasi"<<std::endl;
                    std::cout<<"Zadej vychozi pozici"<<std::endl;
                    std::cin>>Pozv;
               }


            }

    }
     if(Pozv=="res")
            {
                std::cout<<"Opravdu chcete vzdat hru? (Zadejte a/n)"<<std::endl;
                std::cin>>NR;
                while(NR!='a'&&NR=='n')
                {
                   std::cout<<"Spatne zadano! (Zadejte a/n)"<<std::endl;
                    std::cin>>NR;
                }
                if (NR=='a')
               {
                   if (H==1) {MAT[2]=2;}
                   else     {MAT[1]=1;}
                    KH[0]=1;
               }
               else if (NR=='n')
               {
                    std::cout<<"Zadej vychozi pozici"<<std::endl;
                    std::cin>>Pozv;
               }

        }



   // std::cout<<"PAT  "<<PAT[0]<<std::endl;
    if (KH[0]==1) {break;}
    kv=Pozv[1];
    lv=Pozv[0];
    int kiv=int(kv);
    int liv=int(lv);
    iv=kiv-48;
    jv=liv-96;

     if (liv>96&&liv<105&&kiv>48&&kiv<57)
        {
        if (Pozv.size()!= 2)
            {
            std::cout<<"Zadana pozice je spatne zadana"<<std::endl;
             NT[0]=1;
            break;
            }
        if ((M[iv][jv]==1&&H==2)||(M[iv][jv]==2&&H==1)||(M[iv][jv]==0))
            {
               std::cout<<"Na pozici neni hratelna figurka"<<std::endl;
                 NT[0]=1;
                break;
            }
        }
     else {
             std::cout<<"Zadana pozice neni na sachovnici" <<std::endl;
               NT[0]=1;
            break;

            }

    std::cout<<"Zadej cilovou pozici"<<std::endl;
    std::cin>>Pozc;
    kc=Pozc[1];
    lc=Pozc[0];
    int kic=int(kc);
    int lic=int(lc);
    ic=kic-48;
    jc=lic-96;
    if (lic>96&&lic<105&&kic>48&&kic<57)
        {
            if (Pozc.size()!= 2)
            {
            std::cout<<"Zadana pozice je spatne zadana"<<std::endl;
              NT[0]=1;
            break;
            }
        if ((M[ic][jc]==1&&H==1)||(M[ic][jc]==2&&H==2))
            {
               std::cout<<"Pozice je obsazena vlastni figurkou"<<std::endl;
                 NT[0]=1;
                break;
            }
        }
     else {
             std::cout<<"Zadana pozice neni na sachovnici" <<std::endl;
              NT[0]=1;
            break;

            }

         nulovani_pole (M,T1,T2);
        for ( i=8;i>0;i--) {
               for (j=1;j<9;j++) {
                    TK1[i][j]=0;
                    TK2[i][j]=0;
               }
    }



    //if (liv>96&&liv<105&&kiv>48&&kiv<57) { std::cout<<"Zadana pozice je na sachovnici" <<std::endl;}
   // else {
           // std::cout<<"Zadana pozice neni na sachovnici" <<std::endl;
           // break;
           // }
    //if (Pozv.size() == 2) {
    //std::cout<<"Zadana pozice je ok" <<std::endl;
        //    }
    //else {
      //  std::cout<<"Zadana pozice je spatne zadana"<<std::endl;
       // break;

       // }
   // std::cout<<"Zadana pozice je" <<Pozv<<std::endl;

    //std::cout<<"Slozky jsou " <<iv<<"   "<<jv<<std::endl;

   // std::cout<<"M je " <<M[iv][jv]<<std::endl;
   // if (M[iv][jv]==1&&H==2||M[iv][jv]==2&&H==1||M[iv][jv]==0) {
                                    //    std::cout<<"Na pozici neni hratelna figurka"<<std::endl;
                                      //  break;
                                      //  }
  //  else {std::cout<<"Zadana pozice obsahuje hratelnou figurku"<<std::endl;}

       //for (int iv=8;iv>0;iv--) {
             //   for (int jv=1;jv<9;jv++) {

                //    std::cout<<P[iv][jv];
            //}
              //  std::cout<<std::endl;
       // }


   // std::cout<<"Zadej cilovou pozici"<<std::endl;
   // std::cin>>Pozc;
   // kc=Pozc[1];
   // lc=Pozc[0];
   // int kic=int(kc);
    //int lic=int(lc);
    //ic=kic-48;
   // jc=lic-96;
   // if (lic>96&&lic<105&&kic>48&&kic<57) { std::cout<<"Zadana pozice je na sachovnici" <<std::endl;}
   // else {std::cout<<"Zadana pozice neni na sachovnici" <<std::endl;}
   // if (Pozc.size() == 2) {
   // std::cout<<"Zadana pozice je ok" <<std::endl;
   //     }
   // else {
    //        std::cout<<"Zadana pozice je spatne zadana"<<std::endl;
    //        break;

   //     }
   // std::cout<<"Zadana pozice je" <<Pozc<<std::endl;

    //std::cout<<"Slozky jsou " <<ic<<"   "<<jc<<std::endl;

   // std::cout<<"M je " <<M[ic][jc]<<std::endl;
   // if (M[ic][jc]==1||M[ic][jc]==2) {std::cout<<"Zadana pozice je obsazena"<<std::endl;}
   // else {std::cout<<"Zadana pozice neni obsazena"<<std::endl;}

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

        for ( ic=8;ic>0;ic--) {
                for ( jc=1;jc<9;jc++) {

             //   std::cout<<P[ic][jc];
          }
         //   std::cout<<std::endl;
        }
        for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                for (j=1;j<9;j++) {
                        PP[i][j]=P[i][j];
                        MP[i][j]=M[i][j];
                }
        }
    T=false;
    if(P[iv][jv]=='p') {
            //Zjistim, ze se na zvolene pozici nachazi figurka pesec
            if (H==1){
                                    tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);


                            }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);

                            }
                        }
     if(P[iv][jv]=='Q') {
        tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
     }

    if(P[iv][jv]=='B') {
    tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
    }

    if(P[iv][jv]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
    }
     if(P[iv][jv]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }

    if(P[iv][jv]=='K'){
     tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);
    }
    T=true;
  //  std::cout<<"Matice T1"<<std::endl;
    for ( i=8;i>0;i--) {

            //nasledujici casti jsou jen pomocne vypisy
                for (int j=1;j<9;j++) {


                   //  std::cout<<T1[i][j];
                                        }
              // std::cout<<std::endl;
                    }
      nulovani_pole (M,T1,T2);
    for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {
                   TK1[i][j]=0;
                    TK2[i][j]=0;
               }
    }
   // std::cout<<"NT podm"<<NT[0]<<std::endl;

    //   std::cout<<"pomoc"<<pomoc<<std::endl;

    if (NT[0]==1) {
            deska(P,M);
    break;
                    };
    if (NT[0]==1)
        {
             for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {


                   //  std::cout<<P[i][j];
                                    }
             //  std::cout<<std::endl;
                    }
            break;
        }

    for ( i=8;i>0;i--) {
            for (int j=1;j<9;j++) {
                    //Zde prochazim cele pole sachovnice kvuli zjisteni potencialnich "nebezpecnych" pozic pro krale
                    k=i;
                    l=j;
                    if(P[k][l]=='p') {

                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);
                                 //  nulovani_pole (M,T1,T2);
                                  //  tahp2(P,PP,M,T2,T22,iv2,ic2,jv2,jc2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);
                                   // tahp1(P,PP,M,T1,T11,iv1,ic1,jv1,jc1);
                                  //  nulovani_pole (M,T1,T2);
                                }
                                    }
                      if(P[k][l]=='B') {
                                tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }

                        if(P[k][l]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }
                        if(P[k][l]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }


                          if(P[k][l]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }
                       //if(P[k][l]=='K'){
                                   // tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);
                                  //   nulovani_pole (M,T1,T2);
                        }

                            }



         for ( i=8;i>0;i--) {
            for (int j=1;j<9;j++) {
                      k=i;
                    l=j;
                    if(P[k][l]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);
                                  //   nulovani_pole (M,T1,T2);

                                    }
            }
         }

                    //Kontrola proti matu,,,zatim s chybou proto odkomentovano
  //  if(H==1) {
            //  std::cout<<"ik1   "<<ik1<<"   "<<jk1<<std::endl;
             //   std::cout<<"ik2   "<<ik2<<"   "<<jk2<<std::endl;
      // if (T2[ik1][jk1]==2) {
        //     std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
            //    break;

                   //        }
           // }
   // else if (T1[ik2][jk2]==1) {
         //   std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
         //   break;
           //                     }
   if ( NT[0]==1) {
        deska(P,M);
    break;
                    };

    if ( NT[0]==1)
        {
             for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {


               //      std::cout<<P[i][j];
                                    }
             //  std::cout<<std::endl;
                    }
            break;
        }
   // std::cout<<"Matice T1"<<std::endl;
    for ( i=8;i>0;i--) {

            //nasledujici casti jsou jen pomocne vypisy
                for (int j=1;j<9;j++) {


                  //   std::cout<<T1[i][j];
                                        }
            //   std::cout<<std::endl;
                    }
  //  std::cout<<std::endl;
   // std::cout<<"Matice T2"<<std::endl;
    for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {


                   //  std::cout<<T2[i][j];
                                    }
             //  std::cout<<std::endl;
                    }
   // std::cout<<std::endl;
    for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {


                 //    std::cout<<P[i][j];
                                    }
                //   std::cout<<std::endl;
                                }


    for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {
                    OP[i][j][n]=P[i][j];

                                        }
                    }

    kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
    if ( NT[0]==1) {
        deska(P,M);
    break;
    }
   // std::cout<<"T2"<<std::endl;
    for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                for (j=1;j<9;j++) {
                     //  std::cout<<T2[i][j];
                                    }
                  // std::cout<<std::endl;
                                }
     //std::cout<<"TK2"<<std::endl;
    for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                for (j=1;j<9;j++) {
                      //  std::cout<<TK2[i][j];
                                    }
               //    std::cout<<std::endl;
                                }



                                // std::cout<<"T1"<<std::endl;
    for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                for (j=1;j<9;j++) {
                     //   std::cout<<T1[i][j];
                                    }
                 //  std::cout<<std::endl;
                                }
     //std::cout<<"TK1"<<std::endl;
    for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                for (j=1;j<9;j++) {
                       // std::cout<<TK1[i][j];
                                    }
                 //  std::cout<<std::endl;
    }
                   // std::cout<<"M"<<std::endl;
    for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                for (j=1;j<9;j++) {
                       // std::cout<<M[i][j];
                                    }
                 //  std::cout<<std::endl;
                                }
    PT=true;



for ( i=8;i>0;i--) {
               for (j=1;j<9;j++) {
                       T11[i][j]=0;
                        T22[i][j]=0;
               }
        }


//std::cout<<"Zkouska matice"<<std::endl;
 for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {
                //     std::cout<<OP[i][j][n];
               }
               //  std::cout<<std::endl;
 }
 n=n+1;
 int m=n;
 int ll=0;
 //std::cout<<"Konec zkousky matice"<<std::endl;
 opak_pozice (OP,P,M,PO,n,pom2,pom3);
 for (ll=0;ll<=m;ll++){
 //std::cout<<"opakovani 2="<<PO[ll]<<std::endl;
 //std::cout<<"opakovani 3="<<pom2[ll]<<std::endl;
 //std::cout<<"opakovani 4="<<pom3<<std::endl;
 }
}
}
for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {
                 //    std::cout<<PP[i][j];
               }
                 // std::cout<<std::endl;
                  }
  //std::cout<<"pom2"<<pom2<<std::endl;
return 0;

//}
}
char tahp1 (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int k, int l, int H, bool T,int NT[3],int iv2,int MIMO1[10],int MIMO2[10]){   //funkce ktera definuje tahy pesce 1, cili bileho hrace
    int i;
    int j;
    bool PT1;
    bool PT2;
     if (T==false) {
                    i=iv1;
                    j=jv1;
                    }
       else {
            i=k;
          j=l;
        }
      //  std::cout<<"i "<<i<<"j "<<j<<std::endl;
    // nasledujici if dava pro konkretni vychozi pozici volne tahy (Nejsou vsechny, budou doplneny)
     if(i>0&&i<9&&j>0&&j<9&&H==1&&M[i][j]==1){
                    if(M[i+1][j]==0&&i<8) {
                        T1[i+1][j]=1;}
                    if(M[i+1][j-1]==2&&i<8&&j>1) {
                        T1[i+1][j-1]=1;
                                        }
                    if(M[i+1][j+1]==2&&i<8&&j<8) {
                        T1[i+1][j+1]=1;
                                        }
                     if(M[i+2][j]==0&&i==2)         //tah o 2 pole dopredu
                        {
                          T1[i+2][j]=1;
                        }

                                                    //brani mimochodem - rozpracovano

                          if(M[i][j-1]==2&&P[i][j]=='p'&&iv2==7&&j>1)
                          {


                                        MIMO1[j-1]=1;
                          }

                                }
         if(H==1&&P[iv1][jv1]=='p'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='p';
                    M[ic1][jc1]=1;
                    P[iv1][jv1]=' ';
                    M[iv1][jv1]=0;



                                        }
                else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;
                  //  std::cout<<"Neplatny NT "<<NT<<std::endl;

                    return 0;


       // std::cout<<"NT "<< NT[0]<<std::endl;


//Kontrola jestli se mohu dostat figurkou na danou pozici platnym tahem
                    }
                }


     // i=k;
     // j=l;
    //std::cout<<i<<"  "<<j<<std::endl;
    //for ( i=8;i>0;i--) {
           //    for (int j=1;j<9;j++) {
                 //   T11[i][j]=0;

                 // Vsechny mozne tahy pro danou figurku bilou
                  //  if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1){
                      // if(M[i+1][j]==0&&i<8) {
                           // T1[i+1][j]=1;}
                       // if(M[i+1][j-1]==2&&i<8&&j>1) {
                           // T1[i+1][j-1]=1;
                                           // }
                       //if(M[i+1][j+1]==2&&i<8&&j<8) {
                        //   T1[i+1][j+1]=1;
                                         //   }
                                                        //}
           //Vsechny mozne tahy pro figurku cernou
        if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2){
            if(M[i-1][j]==0&&i>1) {
                T2[i-1][j]=2;}
            if(M[i-1][j-1]==1&&i>1&&j>1) {
                T2[i-1][j-1]=2;
                                }
             if(M[i-1][j+1]==1&&i>1&&j<8) {
                T2[i-1][j+1]=2;
                                }
                if(M[i-2][j]==0&&i==7)  //tah o 2 pole dolu
                {


                          T2[i-2][j]=1;
                        }

                }
           //    }
       // }




//T1[2][3]=1;
return 0;
}

char tahp2 (char P[10][10], char PP[10][10], int M[10][10],int MP[10][10], int T2[10][10],int T1[10][10], int iv2, int ic2, int jv2, int jc2, int k, int l,int H,bool T,int NT[3],int iv1,int MIMO1[10],int MIMO2[10])
{  //funkce ktera definuje tahy pesce 2, cili cerneho hrace
    int i;
    int j;
    bool PT1;
    bool PT2;

     if (T==false) {
                    i=iv2;
                    j=jv2;
                    }
       else {
            i=k;
           j=l;
        }
    //std::cout<<
    if(i>0&&i<9&&j>0&&j<9&&H==2&&M[i][j]==2){
            if(M[i-1][j]==0&&i>1) {
                T2[i-1][j]=2;}
            if(M[i-1][j-1]==1&&i>1&&j>1) {
                T2[i-1][j-1]=2;
                                }
             if(M[i-1][j+1]==1&&i>1&&j<8) {
                T2[i-1][j+1]=2;
                                }

             if(M[i-2][j]==0&&i==7)  //tah o 2 pole dolu
                {


                          T2[i-2][j]=1;
                        }

                }


       if (H==2&&P[iv2][jv2]=='p')      {
        if (T2[ic2][jc2]==2&& NT[0]==0) {
            P[ic2][jc2]='p';
            M[ic2][jc2]=2;
            P[iv2][jv2]=' ';
            M[iv2][jv2]=0;

                            }
          else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;

                }
                    }

    //std::cout<<i<<"  "<<j<<std::endl;
    //for ( i=8;i>0;i--) {
          //     for (int j=1;j<9;j++) {
           //Vsechny mozne tahy pro figurku cernou
       //i=k;
      //j=l;
    //if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2){
          //  if(M[i-1][j]==0&&i>1) {
            //    T2[i-1][j]=2;}
            //if(M[i-1][j-1]==1&&i>1&&j>1) {
             //   T2[i-1][j-1]=2;
                               // }
            // if(M[i-1][j+1]==1&&i>1&&j<8) {
               // T2[i-1][j+1]=2;
                               // }
                                        //}

        //Vsechny mozne tahy pro figurku bilou                             }

     if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1){
                       if(M[i+1][j]==0&&i<8) {
                            T1[i+1][j]=1;}
                        if(M[i+1][j-1]==2&&i<8&&j>1) {
                            T1[i+1][j-1]=1;
                                            }
                       if(M[i+1][j+1]==2&&i<8&&j<8) {
                           T1[i+1][j+1]=1;
                                        }

                        if(M[i+2][j]==0&&i==2)         //tah o 2 pole dopredu
                        {
                          T1[i+2][j]=1;
                        }
               //}
    //}


                                        }
}

char tahq (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{
int i;
    int j;
    int u;
    int v;
  //  std::cout<<"T je "<<T<<std::endl;
    if (T==false) {
            if (H==1){
                    i=iv1;
                    j=jv1;
                    }
             else {i=iv2;
                    j=jv2;}
                }
       else {
            i=k;
          j=l;
        }
    bool PT1;
    bool PT2;
  //   std::cout<<"i "<<i<<"j "<<j<<std::endl;
    //bile figurky
    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1)
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru
               {
                T1[u+1][v]=1;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==2)
            {
                 T1[u+1][v]=1;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu
               {
                T1[u-1][v]=1;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==2)
            {
                 T1[u-1][v]=1;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva
               {
                T1[u][v-1]=1;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==2)
            {
                 T1[u][v-1]=1;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava
               {
                T1[u][v+1]=1;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==2)
            {
                 T1[u][v+1]=1;
            }
        u=i;
            v=j;
            while (u<8&&j>1&&M[u+1][v-1]==0) // tahy diagonalne vlevo nahoru
               {
                T1[u+1][v-1]=1;
                u=u+1;
                v=v-1;
               }
            if (u<8&&j>1&&M[u+1][v]==2)
            {
                 T1[u+1][v-1]=1;
            }
     u=i;
    v=j;
    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu
               {
                T1[u-1][v-1]=1;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==2)
            {
                 T1[u-1][v-1]=1;
            }

         u=i;
    v=j;
    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru
               {
                T1[u+1][v+1]=1;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==2)
            {
                 T1[u+1][v+1]=1;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu
               {
                T1[u-1][v+1]=1;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==2)
            {
                 T1[u-1][v+1]=1;
            }
        }


     if(H==1&&P[iv1][jv1]=='Q'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='Q';
                    M[ic1][jc1]=1;
                    P[iv1][jv1]=' ';
                    M[iv1][jv1]=0;
                                    }
                                    else
                                    {
                                         NT[0]=1;
                                        return 0;
                                    }
     }

   //cerne figurky
  if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2)
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru
               {
                T2[u+1][v]=2;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==1)
            {
                 T2[u+1][v]=2;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu
               {
                T2[u-1][v]=2;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==1)
            {
                 T2[u-1][v]=2;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva
               {
                T2[u][v-1]=2;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==1)
            {
                 T2[u][v-1]=2;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava
               {
                T2[u][v+1]=2;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==1)
            {
                 T2[u][v+1]=2;
            }
        u=i;
            v=j;
            while (u<8&&j>1&&M[u+1][v-1]==0) // tahy diagonalne vlevo nahoru
               {
                T2[u+1][v-1]=2;
                u=u+1;
                v=v-1;
               }
            if (u<8&&j>1&&M[u+1][v]==1)
            {
                 T2[u+1][v-1]=2;
            }
     u=i;
    v=j;
    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu
               {
                T2[u-1][v-1]=2;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==1)
            {
                 T2[u-1][v-1]=2;
            }

         u=i;
    v=j;
    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru
               {
                T2[u+1][v+1]=2;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==1)
            {
                 T2[u+1][v+1]=2;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu
               {
                T2[u-1][v+1]=2;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==1)
            {
                 T2[u-1][v+1]=2;
            }
        }
    if(H==2&&P[iv2][jv2]=='Q'){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='Q';
                    M[ic2][jc2]=2;
                    P[iv2][jv2]=' ';
                    M[iv2][jv2]=0;
                    T2[iv2][jv2]=0;
                                    }
                                     else
                                    {
                                         NT[0]=1;
                                    }

        }
}

char tahk (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10],int TK1[10][10],int TK2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,int k, int l,  int ik1, int jk1, int ik2,int jk2, int H,bool T,int NT[3])
{
   int i;
    int j;

   if (T==false) {
            if (H==1){
                    i=iv1;
                    j=jv1;
                    ik1=i;
                    jk1=j;
                    }
             else {i=iv2;
                    j=jv2;
                    ik2=i;
                    jk2=j;}
                }
       else {
            i=k;
          j=l;
        }
  //  std::cout<<"i = "<<i<<"j="<<j<<std::endl;
   if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1)
   {
   if (M[i+1][j]!=1&&T2[i+1][j]==0&&i<8)        //tahy nahoru
        {
            T1[i+1][j]=1;
            TK1[i+1][j]=1;
        }
     if (M[i-1][j]!=1&&T2[i-1][j]==0&&i>1)      //tahy dolu
        {
            T1[i-1][j]=1;
            TK1[i-1][j]=1;
        }

        if (M[i][j+1]!=1&&T2[i][j+1]==0&&j<8)      //tahy doprava
        {
            T1[i][j+1]=1;
            TK1[i][j+1]=1;
        }
     if (M[i][j-1]!=1&&T2[i][j-1]==0&&j>1)      //tahy doleva
        {
            T1[i][j-1]=1;
            TK1[i][j-1]=1;
        }

        if (M[i+1][j+1]!=1&&T2[i+1][j+1]==0&&i<8&&j<8)   //tahy diagonalne vpravo nahoru
        {
            T1[i+1][j+1]=1;
            TK1[i+1][j+1]=1;
        }
     if (M[i-1][j+1]!=1&&T2[i-1][j+1]==0&&i>1&&j<8)      //tahy diagonalne vpravo dolu
        {
            T1[i-1][j+1]=1;
            TK1[i-1][j+1]=1;
        }

        if (M[i+1][j-1]!=1&&T2[i+1][j-1]==0&&i<8&&j>1)   //tahy diagonalne vlevo nahoru
        {
            T1[i+1][j-1]=1;
            TK1[i+1][j-1]=1;
        }
     if (M[i-1][j-1]!=1&&T2[i-1][j-1]==0&&i>1&&j>1)      //tahy diagonalne vlevo dolu
        {
            T1[i-1][j-1]=1;
            TK1[i-1][j-1]=1;
        }
   }


    if(H==1&&P[iv1][jv1]=='K'&&M[iv1][jv1]==1){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='K';
                    M[ic1][jc1]=1;
                    P[iv1][jv1]=' ';
                    M[iv1][jv1]=0;
                }
                 else
                                    {
                                         NT[0]=1;
                                    }
    }

    //cerne figurky

    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2)
   {
   if (M[i+1][j]!=2&&T1[i+1][j]==0&&i<8)        //tahy nahoru
        {
            T2[i+1][j]=2;
            TK2[i+1][j]=2;
        }
     if (M[i-1][j]!=2&&T1[i-1][j]==0&&i>1)      //tahy dolu
        {
            T2[i-1][j]=2;
            TK2[i-1][j]=2;
        }

        if ((M[i][j+1]!=2)&&(T1[i][j+1]==0)&&(j<8))      //tahy doprava
        {
            T2[i][j+1]=2;
            TK2[i][j+1]=2;
        }
     if (M[i][j-1]!=2&&T1[i][j-1]==0&&j>1)      //tahy doleva
        {
            T2[i][j-1]=2;
            TK2[i][j-1]=2;
        }

        if (M[i+1][j+1]!=2&&T1[i+1][j+1]==0&&i<8&&j<8)   //tahy diagonalne vpravo nahoru
        {
            T2[i+1][j+1]=2;
            TK2[i+1][j+1]=2;
        }
     if (M[i-1][j+1]!=2&&T1[i-1][j+1]==0&&i>1&&j<8)      //tahy diagonalne vpravo dolu
        {
            T2[i-1][j+1]=2;
            TK2[i-1][j+1]=2;
        }

        if (M[i+1][j-1]!=2&&T1[i+1][j-1]==0&&i<8&&j>1)   //tahy diagonalne vlevo nahoru
        {
            T2[i+1][j-1]=2;
            TK2[i+1][j-1]=2;
        }
     if (M[i-1][j-1]!=2&&T1[i-1][j-1]==0&&i>1&&j>1)      //tahy diagonalne vlevo dolu
        {
            T2[i-1][j-1]=2;
            TK2[i-1][j-1]=2;
        }

   }

   if(H==2&&P[iv2][jv2]=='K'&&M[iv2][jv2]==2){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='K';
                    M[ic2][jc2]=2;
                    P[iv2][jv2]=' ';
                    M[iv2][jv2]=0;
                }
                 else
                                    {
                                         NT[0]=1;
                                    }
    }
}

char tahb (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{
int i;
    int j;
    int u;
    int v;
  //  std::cout<<"T je "<<T<<std::endl;
    if (T==false) {
            if (H==1){
                    i=iv1;
                    j=jv1;
                    }
             else {i=iv2;
                    j=jv2;}
                }
       else {
            i=k;
          j=l;
        }
    bool PT1;
    bool PT2;
  //   std::cout<<"i "<<i<<"j "<<j<<std::endl;
    //bile figurky
    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1)
        {
        u=i;
            v=j;
            while (u<8&&j>1&&M[u+1][v-1]==0) // tahy diagonalne vlevo nahoru
               {
                T1[u+1][v-1]=1;
                u=u+1;
                v=v-1;
               }
            if (u<8&&j>1&&M[u+1][v]==2)
            {
                 T1[u+1][v-1]=1;
            }
     u=i;
    v=j;
    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu
               {
                T1[u-1][v-1]=1;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==2)
            {
                 T1[u-1][v-1]=1;
            }

         u=i;
    v=j;
    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru
               {
                T1[u+1][v+1]=1;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==2)
            {
                 T1[u+1][v+1]=1;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu
               {
                T1[u-1][v+1]=1;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==2)
            {
                 T1[u-1][v+1]=1;
            }
        }


     if(H==1&&P[iv1][jv1]=='B'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='B';
                    M[ic1][jc1]=1;
                    P[iv1][jv1]=' ';
                    M[iv1][jv1]=0;
                                    }
                                    else
                                    {
                                         NT[0]=1;
                                        return 0;
                                    }
     }

   //cerne figurky
  if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2)
        {
             u=i;
            v=j;

    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu
               {
                T2[u-1][v-1]=2;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==1)
            {
                 T2[u-1][v-1]=2;
            }

         u=i;
    v=j;
    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru
               {
                T2[u+1][v+1]=2;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==1)
            {
                 T2[u+1][v+1]=2;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu
               {
                T2[u-1][v+1]=2;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==1)
            {
                 T2[u-1][v+1]=2;
            }
        }
    if(H==2&&P[iv2][jv2]=='B'){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='B';
                    M[ic2][jc2]=2;
                    P[iv2][jv2]=' ';
                    M[iv2][jv2]=0;
                    T2[iv2][jv2]=0;
                                    }
                                     else
                                    {
                                         NT[0]=1;
                                    }

        }
}
char tahr (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{
int i;
    int j;
    int u;
    int v;
  //  std::cout<<"T je "<<T<<std::endl;
    if (T==false) {
            if (H==1){
                    i=iv1;
                    j=jv1;
                    }
             else {i=iv2;
                    j=jv2;}
                }
       else {
            i=k;
          j=l;
        }
    bool PT1;
    bool PT2;
  //   std::cout<<"i "<<i<<"j "<<j<<std::endl;
    //bile figurky
    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1)
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru
               {
                T1[u+1][v]=1;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==2)
            {
                 T1[u+1][v]=1;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu
               {
                T1[u-1][v]=1;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==2)
            {
                 T1[u-1][v]=1;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva
               {
                T1[u][v-1]=1;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==2)
            {
                 T1[u][v-1]=1;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava
               {
                T1[u][v+1]=1;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==2)
            {
                 T1[u][v+1]=1;
            }

        }


     if(H==1&&P[iv1][jv1]=='R'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='R';
                    M[ic1][jc1]=1;
                    P[iv1][jv1]=' ';
                    M[iv1][jv1]=0;
                                    }
                                    else
                                    {
                                         NT[0]=1;
                                        return 0;
                                    }
     }

   //cerne figurky
  if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2)
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru
               {
                T2[u+1][v]=2;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==1)
            {
                 T2[u+1][v]=2;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu
               {
                T2[u-1][v]=2;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==1)
            {
                 T2[u-1][v]=2;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva
               {
                T2[u][v-1]=2;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==1)
            {
                 T2[u][v-1]=2;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava
               {
                T2[u][v+1]=2;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==1)
            {
                 T2[u][v+1]=2;
            }

    }
    if(H==2&&P[iv2][jv2]=='R'){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='R';
                    M[ic2][jc2]=2;
                    P[iv2][jv2]=' ';
                    M[iv2][jv2]=0;
                    T2[iv2][jv2]=0;
                                    }
                                     else
                                    {
                                         NT[0]=1;
                                    }

        }
}

char tahh (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{

  int i;
    int j;
    bool PT1;
    bool PT2;
     if (T==false) {
                    i=iv1;
                    j=jv1;
                    }
       else {
            i=k;
          j=l;
        }

    //bile figurky
     if(i>0&&i<9&&j>0&&j<9&&H==1&&M[i][j]==1){
                                                    //pohyb o vetsi hodnotu nahoru

                    if(M[i+2][j+1]!=1&&i<7&&j<8) {
                        T1[i+2][j+1]=1;
                        }

                    if(M[i+2][j-1]!=1&&i<7&&j>1) {
                        T1[i+2][j-1]=1;
                        }
                                                    //pohyb o vetsi hodnotu dolu
                    if(M[i-2][j+1]!=1&&i>2&&j<8) {
                        T1[i-2][j+1]=1;
                        }

                    if(M[i-2][j-1]!=1&&i>1&&j>1) {
                        T1[i-2][j-1]=1;
                        }

                                                    //pohyb o vetsi hodnotu doprava

                    if(M[i+1][j+2]!=1&&i<8&&j<7) {
                        T1[i+1][j+2]=1;
                        }

                    if(M[i-1][j+2]!=1&&i>2&&j<7) {
                        T1[i-1][j+2]=1;
                        }
                                                    //pohyb o vetsi hodnotu doleva
                    if(M[i+1][j-2]!=1&&i<8&&j>2) {
                        T1[i+1][j-2]=1;
                        }

                    if(M[i-1][j-2]!=1&&i>1&&j>2) {
                        T1[i-1][j-2]=1;
                        }

                                }


         if(H==1&&P[iv1][jv1]=='H'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='H';
                    M[ic1][jc1]=1;
                    P[iv1][jv1]=' ';
                    M[iv1][jv1]=0;
                                }
                else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;
                  //  std::cout<<"Neplatny NT "<<NT<<std::endl;


                }
         }


    //cerne figurky

    if(i>0&&i<9&&j>0&&j<9&&H==2&&M[i][j]==2){
                                                    //pohyb o vetsi hodnotu nahoru

                    if(M[i+2][j+1]!=2&&i<7&&j<8) {
                        T2[i+2][j+1]=1;
                        }

                    if(M[i+2][j-1]!=2&&i<7&&j>1) {
                        T2[i+2][j-1]=1;
                        }
                                                    //pohyb o vetsi hodnotu dolu
                    if(M[i-2][j+1]!=2&&i>2&&j<8) {
                        T2[i-2][j+1]=1;
                        }

                    if(M[i-2][j-1]!=2&&i>1&&j>1) {
                        T2[i-2][j-1]=1;
                        }

                                                    //pohyb o vetsi hodnotu doprava

                    if(M[i+1][j+2]!=2&&i<8&&j<7) {
                        T2[i+1][j+2]=1;
                        }

                    if(M[i-1][j+2]!=2&&i>2&&j<7) {
                        T2[i-1][j+2]=1;
                        }
                                                    //pohyb o vetsi hodnotu doleva
                    if(M[i+1][j-2]!=2&&i<8&&j>2) {
                        T2[i+1][j-2]=1;
                        }

                    if(M[i-1][j-2]!=2&&i>1&&j>2) {
                        T2[i-1][j-2]=1;
                        }

                                }


         if(H==2&&P[iv2][jv2]=='H'){
                if (T2[ic2][jc2]==1&& NT[0]==0) {
                    P[ic2][jc2]='H';
                    M[ic2][jc2]=2;
                    P[iv2][jv2]=' ';
                    M[iv2][jv2]=0;
                                }
                else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;
                  //  std::cout<<"Neplatny NT "<<NT<<std::endl;


                }
         }





                    return 0;




    }



char opak_pozice (char OP[10][10][1000],char P[10][10], int M[10][10],int PO[1000],int n,int pom2[1000],int pom3) {

int m;

int i;
int j;
int k=n;
int l=n;
m=n;

for (k=n;k<=0;k--)
 {PO[k]=0;}

    while (l>=0) {
            while (k>=0) {

                for ( i=8;i>0;i--) {
                    for (int j=1;j<9;j++) {
                            if ( OP[i][j][l]!=OP[i][j][k])
                                {
                                PO[l]=PO[l]+1;
                                pom2[l]=PO[l]*2;
                                }
                                        }
                            }
                            k=k-1;
            }
            l=l-1;



}
pom3=27;
return pom3;
}

char kontrola_sachu (char P[10][10],int M[10][10], int T1[10][10],int T2[10][10],int TK1[10][10],int TK2[10][10],int k, int l, int ik1, int jk1, int ik2,int jk2, int H,bool T, int SACH[3],int NT[3],int POCPT[3],int POCPTK[3], int ZT[3],char PP[10][10],int MP[10][10],int KT[3],int ZS[3])
{


int i;
int j;


for ( i=8;i>0;i--) {
               for (j=1;j<9;j++) {
                    if(P[i][j]=='K')        {
                            if(M[i][j]==1)
                                {
                                ik1=i;
                                jk1=j;
                                }
                            else if(M[i][j]==2)
                                {
                                ik2=i;
                                jk2=j;
                                }

                                    }


               }
            }




        if(M[ik1][jk1]==1&&T2[ik1][jk1]==2)
            {
                if(H==1&&ZT[0]==0&&KT[0]==0)
                {
                std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
                NT[0]=1;
                for ( i=8;i>0;i--) { //Ulozeni puvodnich pozic pro pripad neplatneo tahu
                    for (j=1;j<9;j++) {
                        P[i][j]=PP[i][j];
                        M[i][j]=MP[i][j];
                                    }
                                }
                }
                else {
                SACH[1]=1;
                }

            }
        if(M[ik2][jk2]==2&&T1[ik2][jk2]==1)
        {
            if(H==2&&ZT[0]==0&&KT[0]==0)
                {
                std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
                NT[0]=1;
                for ( i=8;i>0;i--) { //Nacteni puvodnich hodnot
                for (j=1;j<9;j++) {
                        P[i][j]=PP[i][j];
                        M[i][j]=MP[i][j];
                            }
                    }
                }
            else
                {
            SACH[2]=2;
            }
        }

    if(KT[0]==1)
        {
        if(M[ik1][jk1]==1&&T2[ik1][jk1]==0)
            {
            SACH[1]=0;
            }

    if(M[ik2][jk2]==1&&T1[ik2][jk2]==0)
            {
            SACH[2]=0;
            }

        }
    for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {


                 //    std::cout<<T1[i][j];
                                    }
             //  std::cout<<std::endl;
                    }
     POCPT[1]=0;
                      POCPTK[1]=0;
                       POCPT[2]=0;
                      POCPTK[2]=0;

    if  (NT[0]!=1)
    {
        for ( i=8;i>0;i--) {
               for (j=1;j<9;j++) {
                    if(T1[i][j]==1)
                    {
                      POCPT[1]=POCPT[1]+1;

                    }
                    if(T2[i][j]==2)
                    {
                      POCPT[2]=POCPT[2]+1;

                    }
                     if(TK1[i][j]==1)
                    {

                      POCPTK[1]=POCPTK[1]+1;
                    }
                    if(TK2[i][j]==2)
                    {
                      POCPTK[2]=POCPTK[2]+1;

                    }

               }
        }
    }




//std::cout<<"Pocet PT 1 "<<POCPT[1]<<std::endl;
    // std::cout<<"Pocet PT 2 "<<POCPT[2]<<std::endl;

    //std::cout<<"Pocet PTK 1 "<<POCPTK[1]<<std::endl;
   //  std::cout<<"Pocet PTK 2 "<<POCPTK[2]<<std::endl;


//std::cout<<"ik1 "<<ik1<<"jk1 " <<jk1<<std::endl;
//std::cout<<"ik2 "<<ik2<<"jk2 " <<jk2<<std::endl;
int w=0;
bool ww;
while (w<10)
{
    //std::cout<<"Snaha o ukonceni w " <<w<<std::endl;
    if (w==4) {ZS[1]=1;}
    w=w+1;
}


return 0;
}

int nulovani_pole (int M[10][10], int T1[10][10],int T2[10][10]){
    int i;
    int j;
    for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    T1[i][j]=0;
                    T2[i][j]=0;
                                }
    }
    return 0;
}

char kontrola_matu (char P[10][10],int M[10][10], int T1[10][10],int T2[10][10],int TK1[10][10],int TK2[10][10],int k, int l, int ik1, int jk1, int ik2,int jk2, int H,bool T, int SACH[3],int NT[3],int POCPT[3],int POCPTK[3], int ZT[3], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2, char PP[10][10],int MP[10][10],int A1[100],int A2[100],int B1[100],int B2[100],int KT[3],int ZS[3],int MIMO1[10],int MIMO2[10])
{
int i;
    int j;
    int nm1;
    int nm2;
    int km=0;
    nm1=POCPT[1];
    nm2=POCPT[2];

if(H==1)
{



    while(km<nm1) {
     for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    if (T1[i][j]==1)
                        {
                            A1[km]=i;
                            B1[km]=j;
                            km=km+1;

                        }

               }
            }

        }


     if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);
                                 //  nulovani_pole (M,T1,T2);
                                  //  tahp2(P,PP,M,T2,T22,iv2,ic2,jv2,jc2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);
                                   // tahp1(P,PP,M,T1,T11,iv1,ic1,jv1,jc1);
                                  //  nulovani_pole (M,T1,T2);
                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);

                                    }
                        if(P[k][l]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }
                       if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);
                                  //   nulovani_pole (M,T1,T2);


                        }


      for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    PP[i][j]=P[i][j];
                    MP[i][j]=M[i][j];
               }

          }
     km=0;

      while (km<nm1)
      {


        for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                       if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);
                                 //  nulovani_pole (M,T1,T2);
                                  //  tahp2(P,PP,M,T2,T22,iv2,ic2,jv2,jc2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);
                                   // tahp1(P,PP,M,T1,T11,iv1,ic1,jv1,jc1);
                                  //  nulovani_pole (M,T1,T2);
                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);

                                    }
                        if(P[i][j]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }

               }

               }


              for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);
                                  //   nulovani_pole (M,T1,T2);

                        }
                    }
                }
             kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
             if(SACH[1]==0)
                {
                    ZS[0]=1;
                }

            for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    P[i][j]=PP[i][j];
                    M[i][j]=MP[i][j];
                            }

                            }

        if (ZS[0]==1) {break;}
               }


}




        //hrac 2

if (H==2)
{


        km=0;
    while(km<nm2)
    {


     for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    if (T2[i][j]==2)
                        {
                            A2[km]=i;
                            B2[km]=j;
                              km=km+1;
                        }


               }

            }
    }

 if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);
                                 //  nulovani_pole (M,T1,T2);
                                  //  tahp2(P,PP,M,T2,T22,iv2,ic2,jv2,jc2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);
                                   // tahp1(P,PP,M,T1,T11,iv1,ic1,jv1,jc1);
                                  //  nulovani_pole (M,T1,T2);
                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);

                                    }
                        if(P[i][j]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }
                       if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);
                                  //   nulovani_pole (M,T1,T2);

                        }


      for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    PP[i][j]=P[i][j];
                    MP[i][j]=M[i][j];
               }

          }

 km=0;
      while (km<nm2)
      {


        for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                       if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);
                                 //  nulovani_pole (M,T1,T2);
                                  //  tahp2(P,PP,M,T2,T22,iv2,ic2,jv2,jc2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);
                                   // tahp1(P,PP,M,T1,T11,iv1,ic1,jv1,jc1);
                                  //  nulovani_pole (M,T1,T2);
                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);

                                    }
                        if(P[i][j]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }

               }

               }


              for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);
                                  //   nulovani_pole (M,T1,T2);

                        }
                    }
                }
             kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
             if(SACH[2]==0)
                {
                    ZS[0]=1;
                }


            for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    P[i][j]=PP[i][j];
                    M[i][j]=MP[i][j];
                            }

                            }

                if (ZS[0]==1) {break;}
               }

}

}
