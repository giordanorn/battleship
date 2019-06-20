#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // -FUNDAMENTAL PARA GERAR VALORES ALEEARTORIOS

#define LIN 17
#define COL 17

typedef enum tab_player
{
    WATER, //�GUA
    N1,    //NAVIOS DE TAMANHO 1 2 3 E 4;
    N2,
    N3,
    N4,
    EDGE  // BORDAS
} PLAYER;

int basePL[LIN][COL];                       //MATRIZ DE BASE
char tabPL[LIN][COL];                       //MATRIZ CHAR QUE SER� IMPRESSA

int i, j;                                    //COORDENADAS DO JOGADOR
int PLc1, PLc2, PLc3, PLc4, winPL;              //CONTADORES DO JOGADOR
int GeraAuto, Load;

int Menu (void);
void Instrucoes (void);
void ZeraBase (void);
void BordaBase (void);
void GeraNavios (int base[][COL]);
void EscolheNavios (int base[][COL]);
void ImprimeEscolheNavio (void);
int VH (void);
int LinhaEscolherNavio (int);
int ColunaEscolherNavio (int);
void FormaMapa (char tab[][COL]);
void linha (void);
void coluna (void);
void TiroCerto (void);
void ImprimeMapa (void);
void ImprimeMapas (void);
int VerificaTiro (void);
int VerificaAcerto (void);
void SomVitoria (void);
void SomDerrota (void);
void VerificaVencedor (int);
void SalvaJogo (void);
void CarregaJogo (void);
void ApagaSave (void);
int JogarNovamente (void);