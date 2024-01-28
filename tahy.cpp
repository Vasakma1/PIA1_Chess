#include "tahy.h"
#include "sachovnice.h"
#include <iostream>
#include <string>



char Pozice (char P[10][10], char PP[10][10], int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10],int T11[10][10], int T22[10][10],int TK1[10][10], int TK2[10][10], int ik1, int ik2, int jk1,int jk2,int H,char OP[10][10][1000],int SACH[3], int MAT[3],int ZH, int PAT[3],int KH[3],int MIMO1[10],int MIMO2[10])
{
    //funkce pozice zajistuje zadani pocatecni a cilove pozice, jaka figurka se na dane pozici nachazi
    //a implenetuje na danou figurku prislusnou funkci pro tah, pripadne kontroluje pozici krale proti matu ...bude doplneno
std::string Pozv,Pozc;
int i;          //index radku obecny
int j;          //index sloupce obecny

                //nasledujici hodnoty jsou zadany jako znaky
char kv;    // radek na sachovnici vychozi
char kc;    // radek na sachovnici cilovy
char lv;     //sloupec na sachovnici vychozi
char lc;    // sloupec na sachovnici cilovy


        // prevedeni znaku do int


    int kiv; // radek na sachovnici vychozi
    int liv;   // radek na sachovnici cilovy
    int kic;    //sloupec na sachovnici vychozi
    int lic;     // sloupec na sachovnici cilovy

                // nasledujici promenne jsou posunute o hodnotu z ASCi aby odpovidaly skutecnym hodnotam radku a sloupcu
int iv;         // radek na sachovnici vychozi
int ic;         // radek na sachovnici cilovy
int jv;         // sloupec na ssachovnici vychozi
int jc;         // sloupec na sachovnici cilovy

            // rozdeleni pro bile figurky...index 1 a cerne figurky...index 2
int iv1;
int iv2;
int jv1;
int jv2;
int ic1;
int ic2;
int jc1;
int jc2;

            // obecne indexy pro praci s poli
int k=0;
int l=0;
int n=0;

                    // platny tah pro bile figurkz, cerne figurky a obecny
bool PT1=false;
bool PT2=false;
bool PT;

  //nasledujici promenne s indexem [], index [1] plati pro bile figurky, index [2] pro cerne a index [0] je univerzalni
int POCPT[3];   //pocet platnych tahu
int POCPTK[3];  // pocet platnych tahu kralem
int NT[3];      // neplatny tah

int ZT[3];      // promenna, ktera urcuje, zda-li jiz tah probehl(kvuli kontrole na sach)
ZT[0]=1;
int KT[3];
KT[0]=0;
                // promenne , ktere urcuji zda tah zabrani sachu
int ZS[3];
ZS[0]=0;


bool T;     // promenna ktera rika, zda tah  jiz probehl
            //pomocne promenne pro pocet opakovani pozice
int pom2[1000];
int pom3;

int PO[1000];    //pole pro ulozeni pozic pro kontrolu opakovani pozice

                // promenne pro pole,ktere bude vypocitavat mozne tahy
int A1[100];
int A2[100];
int B1[100];
int B2[100];

                // navrh remizy
char NR;
char F1;        // promenna pro volbu figurky pri pruchodu sachovnici pro bile pesce
char F2;        // promenna pro volbu figurky pri pruchodu sachovnici pro cerne pesce


// na zacatku hrt potrebuji vynulovat pole
for (int i=8;i>0;i--) {
               for (int j=1;j<9;j++) {

                    T11[i][j]=0;
                    T22[i][j]=0;
                                    }
                    }
                    //prirazeni prommene pro platny tah dle hrace
if (H==1) {PT=PT1;}
else {PT=PT2;}

// cyklus opakovani dokud nebude proveden platny tah nebo konec hry
while (PT==false&&KH[0]==0)
{


     NT[0]=0;
    while(PT==false){

    std::cout<<std::endl;
    if (H==1) {std::cout<<"Hraje bily"<<std::endl;  }
    else {std::cout<<"Hraje cerny"<<std::endl;  }
    //kontrola na sach...pokud je sach zjistuji zda existuji tahy ktere zabrani matu
    kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
    //pokud neexistuji mozne tahy bude mat nebo pat
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
               // kontrola_matu (P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,PP,MP,A1,A2,B1,B2,KT,ZS,MIMO1,MIMO2);
                if (ZS[0]==0) {//MAT[2]=2;
                               // KH[0]=1;
                               }

            }
    if(SACH[2]==2&&H==2)

            {
                ZS[0]=0;
                //std::cout<<"Sach 11"<<SACH<<std::endl;
                //kontrola_matu (P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,PP,MP,A1,A2,B1,B2,KT,ZS,MIMO1,MIMO2);
                 if (ZS[0]==0) {//MAT[1]=1;
                              //  KH[0]=1;
                              }


            }
    if(MAT[1]==1||MAT[2]==2||PAT[0]==1)
        {
            KH[0]==1;
        }

    if (KH[0]==1) {break;}
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

    if(Pozv=="draw") // navrh remizy od bileho hrace
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

     if(Pozv=="draw") //navrh remizy od bileho hrace
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
     if(Pozv=="res") //vzdani hry
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
    if (KH[0]==1) {break;} //kontrola zda neni konec hry
    kv=Pozv[1];
    lv=Pozv[0];
     kiv=int(kv);   //prevedeni pozice do int
     liv=int(lv);
    iv=kiv-48;      // posun o ASCI hodnotu
    jv=liv-96;

     if (liv>96&&liv<105&&kiv>48&&kiv<57) // Nachazi se pozice na sachovnici?
        {
        if (Pozv.size()!= 2)    //dimenze pozice
            {
            std::cout<<"Zadana pozice je spatne zadana"<<std::endl;
             NT[0]=1;
            break;
            }
        if ((M[iv][jv]==1&&H==2)||(M[iv][jv]==2&&H==1)||(M[iv][jv]==0)) //kontrola obsazenosti
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
     kic=int(kc);   //prevedeni pozice do int
     lic=int(lc);
    ic=kic-48;      // Posun o ACSI hodnotu
    jc=lic-96;
    if (lic>96&&lic<105&&kic>48&&kic<57) //// Nachazi se pozice na sachovnici?
        {
            if (Pozc.size()!= 2)
            {
            std::cout<<"Zadana pozice je spatne zadana"<<std::endl;
              NT[0]=1;
            break;
            }
        if ((M[ic][jc]==1&&H==1)||(M[ic][jc]==2&&H==2)) //kontrola obsazenosti
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

         // nulovani pole pro tahy kralem
        for ( i=8;i>0;i--) {
               for (j=1;j<9;j++) {
                    TK1[i][j]=0;
                    TK2[i][j]=0;
               }
    }




   //rozdeleni nactenych pozic figurek pro jednotlive hrace
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



      //Ulozeni puvodnich pozic pro pripad neplatneho tahu
        for ( i=8;i>0;i--) {
                for (j=1;j<9;j++) {
                        PP[i][j]=P[i][j];
                        MP[i][j]=M[i][j];
                }
        }
    T=false;
    //Zjistim, ze se na zvolene pozici nachazi figurka pesec
    if(P[iv][jv]=='p') {

            if (H==1){
                                    tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);


                            }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);

                            }
                        }
       //Zjistim, ze se na zvolene pozici nachazi figurka kralovna
     if(P[iv][jv]=='Q') {
        tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
     }
        //Zjistim, ze se na zvolene pozici nachazi figurka strelec
    if(P[iv][jv]=='B') {
    tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
    }
    //Zjistim, ze se na zvolene pozici nachazi figurka vez
    if(P[iv][jv]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
    }
    //Zjistim, ze se na zvolene pozici nachazi figurka kun
     if(P[iv][jv]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                               //  nulovani_pole (M,T1,T2);
                                    }
    //Zjistim, ze se na zvolene pozici nachazi figurka kral
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

    //Pokud je neplatny tah , tak se znovu vykresli figurky na sachovnici
    if (NT[0]==1) {
            deska(P,M);
    break;
                    };
    if (NT[0]==1)   //Pokud je neplatnz tah...navrat na zacatek czklu
        {
            break;
        }
  //Zde prochazim cele pole sachovnice kvuli zjisteni potencialnich "nebezpecnych" pozic pro krale
    for ( i=8;i>0;i--) {
            for (int j=1;j<9;j++) {

                    k=i;
                    l=j;
                    if(P[k][l]=='p') {

                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);


                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);

                                }
                                    }
                      if(P[k][l]=='B') {
                                tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }

                        if(P[k][l]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }
                        if(P[k][l]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }


                          if(P[k][l]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }

                        }

                            }


        //kontrolu nebezpecnych pozic pri tahu kralem provedeme az nakonec
         for ( i=8;i>0;i--) {
            for (int j=1;j<9;j++) {
                      k=i;
                    l=j;
                    if(P[k][l]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);


                                    }
            }
         }



     // pri neplatnem tahu se vykresli sachovnice
   if ( NT[0]==1) {
        deska(P,M);
    break;
                    };

    if ( NT[0]==1)
        {
            break;
        }


//ulozeni pozic pro kontrolu opakovani
    for ( i=8;i>0;i--) {
               for (int j=1;j<9;j++) {
                    OP[i][j][n]=P[i][j];

                                        }
                    }
    // kontrola zda dojde k sachu
    kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
    //Pokud bych se vystavil do sachu, tak by slo o neplatny tah a proto ynova vykreslim sachovnici
    if ( NT[0]==1) {
        deska(P,M);
    break;
    }

    //volba figurky pri pruchodu pesce sachovnici
    if (H==1)
    {
        for (j=1;j<9;j++)
        {
            if (P[8][j]=='p') {
                std::cout<<"Jakou figurku si p5ejete zvolit (dama - Q, kun - H, strelec - B, vez - R "<<std::endl;
                std::cin>>F1;
                while(F1!='Q'&&F1!='H'&&F1!='B'&&F1!='R')
                {
                     std::cout<<"Spatne zadano! (Zadejte Q H B R )"<<std::endl;
                    std::cin>>F1;
                }
                if (F1=='Q')
                    {
                        P[8][j]='Q';
                    }
                else if (F1=='B')
                    {
                        P[8][j]='B';
                    }

                 else if (F1=='H')
                    {
                        P[8][j]='H';
                    }

                else if (F1=='R')
                    {
                        P[8][j]='R';
                    }
            }
        }
    }

    if (H==2)
    {
        for (j=1;j<9;j++)
        {
            if (P[1][j]=='p') {
                std::cout<<"Jakou figurku si prejete zvolit (dama - Q, kun - H, strelec - B, vez - R "<<std::endl;
                std::cin>>F2;
                while(F2!='Q'&&F2!='H'&&F2!='B'&&F2!='R')
                {
                     std::cout<<"Spatne zadano! (Zadejte Q H B R )"<<std::endl;
                    std::cin>>F2;
                }
                if (F2=='Q')
                    {
                        P[1][j]='Q';
                    }
                else if (F2=='B')
                    {
                        P[1][j]='B';
                    }

                 else if (F2=='H')
                    {
                        P[1][j]='H';
                    }

                else if (F2=='R')
                    {
                        P[1][j]='R';
                    }
            }
        }
    }

kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
    if ( NT[0]==1) {
        deska(P,M);
    break;
    }

    PT=true;


//vynulovani pole 'dosazitelnych' pozic
for ( i=8;i>0;i--) {
               for (j=1;j<9;j++) {
                       T11[i][j]=0;
                        T22[i][j]=0;
               }
        }




 // kontrola na pocet opakovani pozice...rozpracovano
 opak_pozice (OP,P,M,PO,n,pom2,pom3);

        }
    }

return 0;

//}
}
// Funkce pro tah bilym pescem
char tahp1 (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int k, int l, int H, bool T,int NT[3],int iv2,int MIMO1[10],int MIMO2[10]){   //funkce ktera definuje tahy pesce 1, cili bileho hrace
    int i;  //obecny index pro radky
    int j;  //obecny index pro sloupec
    bool PT1; //Platny tah bile figurky
    bool PT2;   //Platny tah cerne figurky
    //Pokud nebylo jiz tazeno...
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
    // Pole T1 udava pozice pro pohyb figurky
     if(i>0&&i<9&&j>0&&j<9&&H==1&&M[i][j]==1){ //Pokud je vyzchozi pozice na sachovnici a obsazena bilou figurkou
                    if(M[i+1][j]==0&&i<8) { // Pokud je cilova pozice volna
                        T1[i+1][j]=1;}      //Pohyb o pole nahoru
                    if(M[i+1][j-1]==2&&i<8&&j>1) {  //Pokud je cilova pozice obsazena cernou figurkou
                        T1[i+1][j-1]=1;             // Pohyb pesce diagonalne
                                        }
                    if(M[i+1][j+1]==2&&i<8&&j<8) {
                        T1[i+1][j+1]=1;
                                        }
                     if(M[i+2][j]==0&&M[i+1][j]==0&&i==2)         //tah o 2 pole dopredu
                        {
                          T1[i+2][j]=1;
                        }

                                                    //brani mimochodem - rozpracovano

                          if(M[i][j-1]==2&&P[i][j]=='p'&&iv2==7&&j>1)
                          {


                                        MIMO1[j-1]=1;
                          }

          //                      }

          // tah figurkou
         if(H==1&&P[iv1][jv1]=='p'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='p';    //obsazeni cilove pozice
                    M[ic1][jc1]=1;      //cilova pozice obsazena bilou figurkou
                    P[iv1][jv1]=' ';    //uvolneni puvodni pozice
                    M[iv1][jv1]=0;      //puvodni pozice neobsazena



                                        }
                else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;
                  //  std::cout<<"Neplatny NT "<<NT<<std::endl;

                    return 0;

                    }
                }

           //Vsechny mozne tahy pro figurku cernou
           //Pole T2 ukazuje kam je mozne dostat se cernou figurkou
        if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2){
            if(M[i-1][j]==0&&i>1) {
                T2[i-1][j]=2;}
            if(M[i-1][j-1]==1&&i>1&&j>1) {
                T2[i-1][j-1]=2;
                                }
             if(M[i-1][j+1]==1&&i>1&&j<8) {
                T2[i-1][j+1]=2;
                                }
                if(M[i-2][j]==0&&M[i-1][j]==0&&i==7)  //tah o 2 pole dolu
                {


                          T2[i-2][j]=2;
                        }

                }



}

return 0;
}
//tah cernym pescem
char tahp2 (char P[10][10], char PP[10][10], int M[10][10],int MP[10][10], int T2[10][10],int T1[10][10], int iv2, int ic2, int jv2, int jc2, int k, int l,int H,bool T,int NT[3],int iv1,int MIMO1[10],int MIMO2[10])
{
    //funkce ktera definuje tahy cerneho pesce
    int i;
    int j;
    bool PT1;
    bool PT2;
                    //pokud nebylo tazeno, tak...
     if (T==false) {
                    i=iv2;
                    j=jv2;
                    }
       else {
            i=k;
           j=l;
        }

    if(i>0&&i<9&&j>0&&j<9&&H==2&&M[i][j]==2){   //Pokud je pozice na sachovnici a obsazena cernou figurkou
            if(M[i-1][j]==0&&i>1) {             // Pokud je cilova pozice volna
                T2[i-1][j]=2;}                  //pohyb o pole dolu
            if(M[i-1][j-1]==1&&i>1&&j>1) {      //Pokud je pozice obsazena bilou figurkou
                T2[i-1][j-1]=2;                 //Pohyb pesce diagonalne
                                }
             if(M[i-1][j+1]==1&&i>1&&j<8) {
                T2[i-1][j+1]=2;
                                }

             if(M[i-2][j]==0&&M[i-1][j]==0&&i==7)  //tah o 2 pole dolu
                {


                          T2[i-2][j]=2;
                        }

                }


       if (H==2&&P[iv2][jv2]=='p')      {
        if (T2[ic2][jc2]==2&& NT[0]==0) {
            P[ic2][jc2]='p';    //obsazeni cilove pozice
            M[ic2][jc2]=2;      //cilova pozice obsazena cernou figurkou
            P[iv2][jv2]=' ';    //uvolneni puvodni pozice
            M[iv2][jv2]=0;      //puvodni pozice neobsazena

                            }
          else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;

                }
                    }



        //Vsechny mozne tahy pro figurku bilou

     if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1){
                       if(M[i+1][j]==0&&i<8) {
                            T1[i+1][j]=1;}
                        if(M[i+1][j-1]==2&&i<8&&j>1) {
                            T1[i+1][j-1]=1;
                                            }
                       if(M[i+1][j+1]==2&&i<8&&j<8) {
                           T1[i+1][j+1]=1;
                                        }

                        if(M[i+2][j]==0&&M[i+1][j]==0&&i==2)         //tah o 2 pole dopredu
                        {
                          T1[i+2][j]=1;
                        }


                    }

}
//tahy damou
char tahq (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{
int i;          //obecny index radku
    int j;      //obecny index sloupce
    int u;  // pomocny index radku
    int v;  // pomocny index sloupce

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

    //bile figurky
    //T1 je pole pro mozne pozice tahu bilou figurkou
    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1)  //Pokud je vychozi pozice na sachovnici a obsazena bilou figurkou
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru + pokud je cilova pozice volna
               {
                T1[u+1][v]=1;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==2)  // tahy nahoru + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u+1][v]=1;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu + pokud je cilova pozice volna
               {
                T1[u-1][v]=1;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==2)   //tahy dolu + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u-1][v]=1;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva + pokud je cilova pozice volna
               {
                T1[u][v-1]=1;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==2)  //tahy doleva + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u][v-1]=1;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava + pokud je cilova pozice volna
               {
                T1[u][v+1]=1;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==2)  // tahy doprava + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u][v+1]=1;
            }
        u=i;
            v=j;
            while (u<8&&j>1&&M[u+1][v-1]==0) // tahy diagonalne vlevo nahoru + pokud je cilova pozice volna
               {
                T1[u+1][v-1]=1;
                u=u+1;
                v=v-1;
               }
            if (u<8&&j>1&&M[u+1][v]==2) // tahy diagonalne vlevo nahoru + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u+1][v-1]=1;
            }
     u=i;
    v=j;
    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu + pokud je cilova pozice volna
               {
                T1[u-1][v-1]=1;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==2)   //tahy diagonalne vlevo dolu + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u-1][v-1]=1;
            }

         u=i;
    v=j;
    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru + pokud je cilova pozice volna
               {
                T1[u+1][v+1]=1;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==2)   // tahy diagonalne vpravo nahoru + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u+1][v+1]=1;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu + pokud je cilova pozice volna
               {
                T1[u-1][v+1]=1;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==2) //tahy diagnoalne vpravo dolu + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u-1][v+1]=1;
            }
        }


     if(H==1&&P[iv1][jv1]=='Q'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='Q';    //obsazeni cilove pozice
                    M[ic1][jc1]=1;      //cilova pozice obsazena bilou figurkou
                    P[iv1][jv1]=' ';    //uvolneni puvodni pozice
                    M[iv1][jv1]=0;      //puvodni pozice neobsazena
                                    }
                                    else
                                    {
                                         NT[0]=1;
                                        return 0;
                                    }
     }

   //cerne figurky
  if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2) //Pokud je vychozi pozice na sachovnici a obsazena cernou figurkou
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru + pokud je cilova pozice volna
               {
                T2[u+1][v]=2;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==1) // tahy nahoru + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u+1][v]=2;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu + pokud je cilova pozice volna
               {
                T2[u-1][v]=2;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==1) // tahy dolu + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u-1][v]=2;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva + pokud je cilova pozice volna
               {
                T2[u][v-1]=2;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==1) // tahy doleva + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u][v-1]=2;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava + pokud je cilova pozice volna
               {
                T2[u][v+1]=2;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==1) // tahy doprava + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u][v+1]=2;
            }
        u=i;
            v=j;
            while (u<8&&j>1&&M[u+1][v-1]==0) // tahy diagonalne vlevo nahoru + pokud je cilova pozice volna
               {
                T2[u+1][v-1]=2;
                u=u+1;
                v=v-1;
               }
            if (u<8&&j>1&&M[u+1][v]==1) // tahy diagonalne vlevo nahoru + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u+1][v-1]=2;
            }
     u=i;
    v=j;
    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu + pokud je cilova pozice volna
               {
                T2[u-1][v-1]=2;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==1) // tahy diagonalne vlevo dolu + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u-1][v-1]=2;
            }

         u=i;
    v=j;
    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru + pokud je cilova pozice volna
               {
                T2[u+1][v+1]=2;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==1) // tahy diagonalne vpravo nahoru + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u+1][v+1]=2;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu + pokud je cilova pozice volna
               {
                T2[u-1][v+1]=2;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==1) // tahy diagnoalne vpravo dolu + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u-1][v+1]=2;
            }
        }
    if(H==2&&P[iv2][jv2]=='Q'){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='Q';    //obsazeni cilove pozice
                    M[ic2][jc2]=2;      //cilova pozice obsazena cernou figurkou
                    P[iv2][jv2]=' ';    //uvolneni puvodni pozice
                    M[iv2][jv2]=0;      //puvodni pozice neobsazena
                   // T2[iv2][jv2]=0;
                                    }
                                     else
                                    {
                                         NT[0]=1;
                                    }

        }
}
//tahy kralem
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
  //

    //T1 je pole pro mozne pozice tahu bilou figurkou
    //TK1 je pole pro mozny pohyb bileho krale
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
                    P[ic1][jc1]='K';    //obsazeni cilove pozice
                    M[ic1][jc1]=1;      //cilova pozice obsazena bilou figurkou
                    P[iv1][jv1]=' ';    //uvolneni puvodni pozice
                    M[iv1][jv1]=0;      //puvodni pozice neobsazena
                }
                 else
                                    {
                                         NT[0]=1;
                                    }
    }

    //cerne figurky
 //T2 je pole pro mozne pozice tahu cernou figurkou
    //TK2 je pole pro mozny pohyb cerneho krale
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
                    P[ic2][jc2]='K';    //obsazeni cilove pozice
                    M[ic2][jc2]=2;      //cilova pozice obsazena cernou figurkou
                    P[iv2][jv2]=' ';    //uvolneni puvodni pozice
                    M[iv2][jv2]=0;      //puvodni pozice neobsazena
                }
                 else
                                    {
                                         NT[0]=1;
                                    }
    }
}
//tahy strelcem
char tahb (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{
int i;
    int j;
    int u;
    int v;

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

    //bile figurky
    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1) //Pokud je vychozi pozice na sachovnici a obsazena bilou figurkou
        {
        u=i;
            v=j;
            while (u<8&&j>1&&M[u+1][v-1]==0) // tahy diagonalne vlevo nahoru + pokud je cilova pozice volna
               {
                T1[u+1][v-1]=1;
                u=u+1;
                v=v-1;
               }
            if (u<8&&j>1&&M[u+1][v]==2)   // tahy diagonalne vlevo nahoru + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u+1][v-1]=1;
            }
     u=i;
    v=j;
    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu + pokud je cilova pozice volna
               {
                T1[u-1][v-1]=1;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==2)  // tahy diagonalne vlevo dolu + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u-1][v-1]=1;
            }

         u=i;
    v=j;
    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru + pokud je cilova pozice volna
               {
                T1[u+1][v+1]=1;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==2)   // tahy diagonalne vpravo nahoru + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u+1][v+1]=1;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu + pokud je cilova pozice volna
               {
                T1[u-1][v+1]=1;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==2) // tahy diagnoalne vpravo dolu + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u-1][v+1]=1;
            }
        }


     if(H==1&&P[iv1][jv1]=='B'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='B';    //obsazeni cilove pozice
                    M[ic1][jc1]=1;      //cilova pozice obsazena bilou figurkou
                    P[iv1][jv1]=' ';    //uvolneni puvodni pozice
                    M[iv1][jv1]=0;      //puvodni pozice neobsazena
                                    }
                                    else
                                    {
                                         NT[0]=1;
                                        return 0;
                                    }
     }

   //cerne figurky
  if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2) //Pokud je vychozi pozice na sachovnici a obsazena cernou figurkou
        {
             u=i;
            v=j;

    while (u>1&&v>1&&M[u-1][v-1]==0)   // tahy diagonalne vlevo dolu + pokud je cilova pozice volna
               {
                T2[u-1][v-1]=2;
                u=u-1;
                v=v-1;
               }
            if (u>1&&v>1&&M[u-1][v-1]==1)   // tahy diagonalne vlevo dolu + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u-1][v-1]=2;
            }

         u=i;
    v=j;

    while (u<8&&j>1&&M[u+1][v-1]==0) // tahy diagonalne vlevo nahoru + pokud je cilova pozice volna
               {
                T2[u+1][v-1]=1;
                u=u+1;
                v=v-1;
               }
            if (u<8&&j>1&&M[u+1][v]==1)   // tahy diagonalne vlevo nahoru + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u+1][v-1]=1;
            }
     u=i;
    v=j;








    while (u<8&&v<8&&M[u+1][v+1]==0)   // tahy diagonalne vpravo nahoru + pokud je cilova pozice volna
               {
                T2[u+1][v+1]=2;
                u=u+1;
                v=v+1;
               }
            if (u<8&&v<8&&M[u+1][v+1]==1)    // tahy diagonalne vpravo nahoru + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u+1][v+1]=2;
            }


         u=i;
    v=j;
    while (u>1&&v<8&&M[u-1][v+1]==0)   // tahy diagnoalne vpravo dolu + pokud je cilova pozice volna
               {
                T2[u-1][v+1]=2;
                u=u-1;
                v=v+1;
               }
            if (u>1&&v<8&&M[u][v+1]==1)  // tahy diagnoalne vpravo dolu + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u-1][v+1]=2;
            }
        }
    if(H==2&&P[iv2][jv2]=='B'){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='B';    //obsazeni cilove pozice
                    M[ic2][jc2]=2;      //cilova pozice obsazena cernou figurkou
                    P[iv2][jv2]=' ';    //uvolneni puvodni pozice
                    M[iv2][jv2]=0;      //puvodni pozice neobsazena
                  //  T2[iv2][jv2]=0;
                                    }
                                     else
                                    {
                                         NT[0]=1;
                                    }

        }
}
//tahy vezi
char tahr (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{
int i;
    int j;
    int u;
    int v;

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
    if(i>0&&i<9&&j>0&&j<9&&M[i][j]==1) //Pokud je vychozi pozice na sachovnici a obsazena bilou figurkou
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru + pokud je cilova pozice volna
               {
                T1[u+1][v]=1;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==2)      // tahy nahoru + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u+1][v]=1;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu + pokud je cilova pozice volna
               {
                T1[u-1][v]=1;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==2)  // tahy dolu + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u-1][v]=1;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva + pokud je cilova pozice volna
               {
                T1[u][v-1]=1;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==2)  // tahy doleva + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u][v-1]=1;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava + pokud je cilova pozice volna
               {
                T1[u][v+1]=1;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==2)  // tahy doprava + pokud je cilova pozice obsazena cernou figurkou
            {
                 T1[u][v+1]=1;
            }

        }


     if(H==1&&P[iv1][jv1]=='R'){
                if (T1[ic1][jc1]==1&& NT[0]==0) {
                    P[ic1][jc1]='R';    //obsazeni cilove pozice
                    M[ic1][jc1]=1;      //cilova pozice obsazena bilou figurkou
                    P[iv1][jv1]=' ';    //uvolneni puvodni pozice
                    M[iv1][jv1]=0;      //puvodni pozice neobsazena
                                    }
                                    else
                                    {
                                         NT[0]=1;
                                        return 0;
                                    }
     }

   //cerne figurky
  if(i>0&&i<9&&j>0&&j<9&&M[i][j]==2) //Pokud je vychozi pozice na sachovnici a obsazena cernou figurkou
        {
             u=i;
            v=j;
            while (u<8&&M[u+1][v]==0) // tahy nahoru + pokud je cilova pozice volna
               {
                T2[u+1][v]=2;
                u=u+1;
               }
            if (u<8&&M[u+1][v]==1)  // tahy nahoru + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u+1][v]=2;
            }
     u=i;
    v=j;
    while (u>1&&M[u-1][v]==0)   // tahy dolu + pokud je cilova pozice volna
               {
                T2[u-1][v]=2;
                u=u-1;
               }
            if (u>1&&M[u-1][v]==1)  // tahy dolu + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u-1][v]=2;
            }

         u=i;
    v=j;
    while (v>1&&M[u][v-1]==0)   // tahy doleva + pokud je cilova pozice volna
               {
                T2[u][v-1]=2;
                v=v-1;
               }
            if (v>1&&M[u][v-1]==1)  // tahy doleva + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u][v-1]=2;
            }


         u=i;
    v=j;
    while (v<8&&M[u][v+1]==0)   // tahy doprava + pokud je cilova pozice volna
               {
                T2[u][v+1]=2;
                v=v+1;
               }
            if (v<8&&M[u][v+1]==1)  // tahy doprava + pokud je cilova pozice obsazena bilou figurkou
            {
                 T2[u][v+1]=2;
            }

    }
    if(H==2&&P[iv2][jv2]=='R'){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='R';    //obsazeni cilove pozice
                    M[ic2][jc2]=2;      //cilova pozice obsazena cernou figurkou
                    P[iv2][jv2]=' ';    //uvolneni puvodni pozice
                    M[iv2][jv2]=0;      //puvodni pozice neobsazena
                    //T2[iv2][jv2]=0;
                                    }
                                     else
                                    {
                                         NT[0]=1;
                                    }

        }
}
//tahy konem
char tahh (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3])
{

  int i;
    int j;
    bool PT1;
    bool PT2;
     if (T==false) {
            if (H==1)
            {
                i=iv1;
                j=jv1;
            }
            else
            {
                i=iv2;
                j=jv2;
            }
        }
       else {
            i=k;
          j=l;
        }

    //bile figurky
     if(i>0&&i<9&&j>0&&j<9&&H==1&&M[i][j]==1){      // //Pokud je vychozi pozice na sachovnici a obsazena bilou figurkou
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
                    P[ic1][jc1]='H';    //obsazeni cilove pozice
                    M[ic1][jc1]=1;      //cilova pozice obsazena bilou figurkou
                    P[iv1][jv1]=' ';    //uvolneni puvodni pozice
                    M[iv1][jv1]=0;      //puvodni pozice neobsazena
                                }
                else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;
                  //  std::cout<<"Neplatny NT "<<NT<<std::endl;


                }
         }


    //cerne figurky

    if(i>0&&i<9&&j>0&&j<9&&H==2&&M[i][j]==2){       //Pokud je vychozi pozice na sachovnici a obsazena cernou figurkou
                                                    //pohyb o vetsi hodnotu nahoru

                    if(M[i+2][j+1]!=2&&i<7&&j<8) {
                        T2[i+2][j+1]=2;
                        }

                    if(M[i+2][j-1]!=2&&i<7&&j>1) {
                        T2[i+2][j-1]=2;
                        }
                                                    //pohyb o vetsi hodnotu dolu
                    if(M[i-2][j+1]!=2&&i>2&&j<8) {
                        T2[i-2][j+1]=2;
                        }

                    if(M[i-2][j-1]!=2&&i>1&&j>1) {
                        T2[i-2][j-1]=2;
                        }

                                                    //pohyb o vetsi hodnotu doprava

                    if(M[i+1][j+2]!=2&&i<8&&j<7) {
                        T2[i+1][j+2]=2;
                        }

                    if(M[i-1][j+2]!=2&&i>2&&j<7) {
                        T2[i-1][j+2]=2;
                        }
                                                    //pohyb o vetsi hodnotu doleva
                    if(M[i+1][j-2]!=2&&i<8&&j>2) {
                        T2[i+1][j-2]=2;
                        }

                    if(M[i-1][j-2]!=2&&i>1&&j>2) {
                        T2[i-1][j-2]=2;
                        }

                                }


         if(H==2&&P[iv2][jv2]=='H'){
                if (T2[ic2][jc2]==2&& NT[0]==0) {
                    P[ic2][jc2]='H';    //obsazeni cilove pozice
                    M[ic2][jc2]=2;      //cilova pozice obsazena cernou figurkou
                    P[iv2][jv2]=' ';    //uvolneni puvodni pozice
                    M[iv2][jv2]=0;      //puvodni pozice neobsazena
                                }
                else {
                    std::cout<<"Neplatny tah"<<std::endl;
                     NT[0]=1;
                  //  std::cout<<"Neplatny NT "<<NT<<std::endl;


                }
         }





                    return 0;




    }


// Tato funkce kontroluje opakovani pozice...zatim rozpracovano
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

}
// Tato funkce kontroluje zda doslo k sachu, pripadne k tomu aby se hrac nevzstavil vlastnim pohybem do matu
char kontrola_sachu (char P[10][10],int M[10][10], int T1[10][10],int T2[10][10],int TK1[10][10],int TK2[10][10],int k, int l, int ik1, int jk1, int ik2,int jk2, int H,bool T, int SACH[3],int NT[3],int POCPT[3],int POCPTK[3], int ZT[3],char PP[10][10],int MP[10][10],int KT[3],int ZS[3])
{


int i;
int j;


for ( i=8;i>0;i--) {
               for (j=1;j<9;j++) {
                    if(P[i][j]=='K')        { //priradim indexum i a j pozice krale, bud bileho nebo cerneho
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




        if(M[ik1][jk1]==1&&T2[ik1][jk1]==2) //Pokud je bily kral na pozici ktera je ohrozena matem
            {
                if(H==1&&ZT[0]==0&&KT[0]==0) // Pokud v tento moment hral hrac s bilymi fifurkami...jedna se o neplatny tah
                {
                std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
                NT[0]=1;
                for ( i=8;i>0;i--) { ////Nacteni puvodnich pozic
                    for (j=1;j<9;j++) {
                        P[i][j]=PP[i][j];
                        M[i][j]=MP[i][j];
                                    }
                                }
                }
                else { //pokud ne, je bily kral vystaven do sachu
                SACH[1]=1;
                }

            }
        if(M[ik2][jk2]==2&&T1[ik2][jk2]==1) //Pokud je cerny kral na pozici ktera je ohrozena matem
        {
            if(H==2&&ZT[0]==0&&KT[0]==0) // Pokud v tento moment hral hrac s cernymi figurkami...jedna se o neplatny tah
                {
                std::cout<<"Neplatny tah - Nelze vystavit krale do sachu"<<std::endl;
                NT[0]=1;
                for ( i=8;i>0;i--) { //Nacteni puvodnich pozic
                for (j=1;j<9;j++) {
                        P[i][j]=PP[i][j];
                        M[i][j]=MP[i][j];
                            }
                    }
                }
            else //pokud ne, je cerny kral vystaven do sachu
                {
            SACH[2]=2;
            }
        }

    if(KT[0]==1)
        {
        if(M[ik1][jk1]==1&&T2[ik1][jk1]==0) //Pokud po konci tahu nedojde k sachu pro bile figurky
            {
            SACH[1]=0;
            }

    if(M[ik2][jk2]==1&&T1[ik2][jk2]==0) //Pokud po konci tahu nedojde k sachu pro cerne figurky
            {
            SACH[2]=0;
            }

        }


       // nulovani poctu platnych tahu
     POCPT[1]=0;
                      POCPTK[1]=0;
                       POCPT[2]=0;
                      POCPTK[2]=0;
// vypocet poctu platnych tahu PT pro figurky a PTK pro krale
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



return 0;
}
// Tato funkce vznulje hodnoty dosazitelnch pozic pro jednotlive figurky
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
// Tato funkce zjistuje, zda existuje moznost zabraneni matu pri sachu at uz pohybem krale nebo jinych figurek
char kontrola_matu (char P[10][10],int M[10][10], int T1[10][10],int T2[10][10],int TK1[10][10],int TK2[10][10],int k, int l, int ik1, int jk1, int ik2,int jk2, int H,bool T, int SACH[3],int NT[3],int POCPT[3],int POCPTK[3], int ZT[3], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2, char PP[10][10],int MP[10][10],int A1[100],int A2[100],int B1[100],int B2[100],int KT[3],int ZS[3],int MIMO1[10],int MIMO2[10])
{
int i;
    int j;
    int nm1;    //indexace poctu poli pro vsechny potencialni tahy bilych figurek
    int nm2;    //indexace poctu poli pro vsechny potencialni tahy cernych figurek
    int km=0;   //pomocny index pole
    nm1=POCPT[1];
    nm2=POCPT[2];

    // ulozeni puvodnich pozic
      for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    PP[i][j]=P[i][j];
                    MP[i][j]=M[i][j];
               }

          }




//hrac s bilymi figurkami
if(H==1)
{


// V teto funkci se vytvori rada poli pro vsechny mozne tahy jednotlivych  bilych figurek
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


     km=0;

      while (km<nm1)
      {                 //ulozeni parametru pole do indexu
          i=A1[km];
          j=B1[km];
          // Zde zjistuji mozne tahy pro danou pozici na sachovnici
        if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);


                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);

                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }
                        if(P[i][j]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }
                        if(P[i][j]=='B') {
                                tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                                            }

                            if(P[i][j]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                                                }
                       if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);


                        }
        //zde se zjistuje potencialni pohyb ostatnich figurek
        for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                       if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);

                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);


                                    }
                        if(P[i][j]=='B') {
                            tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                                            }

                        if(P[i][j]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                        }
                        if(P[i][j]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }

               }

               }


              for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);

                        }
                    }
                }
              // kontrola zda doslo k sachu, pripadne zda mu bylo zabraneno
             kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
             if(SACH[1]==0)
                {
                    ZS[0]=1;
                }
            //nacteni puvodnich pozic pro dalsi variantu
            for ( i=8;i>0;i--) {
              for ( j=1;j<9;j++) {
                   P[i][j]=PP[i][j];
                   M[i][j]=MP[i][j];
                            }

                            }

        if (ZS[0]==1) {break;}

        km=km+1;

               }


}




        //hrac s cernymi figurkami

if (H==2)
{


        km=0;
        // V teto funkci se vytvori rada poli pro vsechny mozne tahy jednotlivych  cernych figurek
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




 km=0;
      while (km<nm2)
      {
          i=A2[km];
          j=B2[km];


      // Zde zjistuji mozne tahy pro danou pozici na sachovnici
    if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);

                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }
                        if(P[i][j]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }
                        if(P[i][j]=='B') {
                                tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                                }

                            if(P[i][j]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                            }
                       if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);


                        }
      //zde se zjistuje potencialni pohyb ostatnich figurek
        for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                       if(P[i][j]=='p')
                {


                            if (H==1){
                                   tahp1(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,k,l,H,T,NT,iv2,MIMO1,MIMO2);

                                }
                            else {
                                    tahp2(P,PP,M,MP,T2,T1,iv2,ic2,jv2,jc2,k,l,H,T,NT,iv1,MIMO1,MIMO2);

                                }

                    }
                      if(P[i][j]=='Q') {
                                tahq(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);


                                    }
                        if(P[i][j]=='H') {
                                tahh(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);

                                    }
                         if(P[i][j]=='B') {
                            tahb(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                                            }

                            if(P[i][j]=='R') {
                                tahr(P,PP,M,MP,T1,T2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,H,T,NT);
                                            }

               }

               }


              for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {

                if(P[i][j]=='K'){
                                    tahk (P,PP,M,MP,T1,T2,TK1,TK2,iv1,ic1,jv1,jc1,iv2,ic2,jv2,jc2,k,l,ik1,jk1,ik2,jk2,H,T,NT);


                        }
                    }
                }
                 // kontrola zda doslo k sachu, pripadne zda mu bylo zabraneno
             kontrola_sachu(P,M,T1,T2,TK1,TK2,k,l,ik1,jk1,ik2,jk2,H,T,SACH,NT,POCPT,POCPTK,ZT,PP,MP,KT,ZS);
             if(SACH[2]==0)
                {
                    ZS[0]=1;
                }

    //nacteni puvodni pozice pro dalsi pozici
            for ( i=8;i>0;i--) {
               for ( j=1;j<9;j++) {
                    P[i][j]=PP[i][j];
                    M[i][j]=MP[i][j];
                            }

                            }

                if (ZS[0]==1) {break;}

                km=km+1;

               }

    }

}
