#ifndef TAHY_H
#define TAHY_H

char Pozice(char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10],int T11[10][10], int T22[10][10],int TK1[10][10], int TK2[10][10], int ik1, int ik2, int jk1,int jk2,int H,char OP[10][10][1000],int SACH[3], int MAT[3],int ZH, int PAT[3],int KH[3],int MIMO1[10],int MIMO2[10]);
char tahp1 (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1,int k, int l,int H, bool T,int NT[3],int iv2,int MIMO1[10],int MIMO2[10]);
char tahp2 (char P[10][10], char PP[10][10], int M[10][10],int MP[10][10], int T2[10][10],int T1[10][10], int iv2, int ic2, int jv2, int jc2, int k, int l, int H,bool T,int NT[3],int iv1,int MIMO1[10],int MIMO2[10]);
char tahq (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2, int k, int l, int H,bool T,int NT[3]);
char tahk (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int TK1[10][10],int TK2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2, int k,int l, int ik1, int jk1, int ik2,int jk2, int H,bool T,int NT[3]);
char opak_pozice (char OP[10][10][1000],char P[10][10], int M[10][10],int PO[1000],int n,int pom2[1000],int pom3);
char kontrola_sachu (char P[10][10],int M[10][10], int T1[10][10],int T2[10][10],int TK1[10][10],int TK2[10][10],int k, int l, int ik1, int jk1, int ik2,int jk2, int H,bool T, int SACH[3],int NT[3],int POCPT[3],int POCPTK[3],int ZT[3],char PP[10][10],int MP[10][10],int KT[3],int ZS[3]);
char tahb (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3]);
char tahr (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3]);
int nulovani_pole (int M[10][10], int T1[10][10],int T2[10][10]);
char tahh (char P[10][10], char PP[10][10],int M[10][10],int MP[10][10], int T1[10][10],int T2[10][10], int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,  int k, int l, int H,bool T, int NT[3]);
char kontrola_matu (char P[10][10],int M[10][10], int T1[10][10],int T2[10][10],int TK1[10][10],int TK2[10][10],int k, int l, int ik1, int jk1, int ik2,int jk2, int H,bool T, int SACH[3],int NT[3],int POCPT[3],int POCPTK[3], int ZT[3],int iv1, int ic1, int jv1, int jc1, int iv2, int ic2, int jv2, int jc2,char PP[10][10],int MP[10][10],int A1[100], int A2[100],int B1[100], int B2[100],int KT[3],int ZS[3],int MIMO1[10],int MIMO2[10]);
#endif


