#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // -FUNDAMENTAL PARA GERAR VALORES ALEEARTORIOS
#include <dos.h>        // -FUNDAMENTAIS PARA
#include <windows.h>    //  USAR OS BEEPS
#define LIN 17
#define COL 17

typedef enum tab_player{
    WATER, //ÁGUA
    N1,    //NAVIOS DE TAMANHO 1 2 3 E 4;
    N2,
    N3,
    N4,
    EDGE,  // BORDAS
}PLAYER;

int basePL[LIN][COL];                       //MATRIZ DE BASE
char tabPL[LIN][COL];                       //MATRIZ CHAR QUE SERÁ IMPRESSA

int i,j;                                    //COORDENADAS DO JOGADOR
int PLc1,PLc2,PLc3,PLc4,winPL;              //CONTADORES DO JOGADOR
int GeraAuto,Load;

int Menu();
void Instrucoes();
void ZeraBase();
void BordaBase();
void GeraNavios(int base[][COL]);
void EscolheNavios(int base[][COL]);
void ImprimeEscolheNavio();
int VH();
int LinhaEscolherNavio(int tam);
int ColunaEscolherNavio(int tam);
void FormaMapa(char tab[][COL]);
void linha();
void coluna();
void TiroCerto();
void ImprimeMapa();
void ImprimeMapas();
int VerificaTiro();
int VerificaAcerto();
void SomVitoria();
void SomDerrota();
void VerificaVencedor(int winner);
void SalvaJogo();
void CarregaJogo();
void ApagaSave();
int JogarNovamente();
