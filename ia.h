#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 17
#define COL 17

typedef enum tab_ia{
    WATER_IA, //�GUA
    N1_IA,    //NAVIOS DE TAMANHO 1 2 3 E 4;
    N2_IA,
    N3_IA,
    N4_IA,
    EDGE_IA,  // BORDAS
}IA;

int baseIA[LIN][COL];
char tabIA[LIN][COL];
int x,y,z,I,J;                                          // COORDENADAS DA IA
int IAc1,IAc2,IAc3,IAc4,winIA;                          // CONTADORES DA IA
char colunaInimigo(int j);                              // CONVERTE A COLUNA DE INTEIRO PARA CHAR
void TiroCertoIA();                                     // PISCA A TELA E FAZ SOM
void ZeraBaseIA();
void BordaBaseIA();
void GeraNaviosIA(int base[][COL]);
void FormaMapaIA(char tab[][COL]);
void ImprimeMapaIA();
void GeraTiroIA(int i,int j);
void ProximoTiroIA();
int VerificaAcertoIA(int i,int j);




