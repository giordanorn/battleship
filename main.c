#include "player.h"
#include "ia.h"

int main(){
    srand(time(NULL));
    while(1){                   /// LOOP DO JOGO
        ZeraBase();                     //ZERA AS MATRIZES DE BASE
        ZeraBaseIA();
        GeraNavios(basePL);             //GERA OS NAVIOS ALEARTORIAMENTE
        GeraNaviosIA(baseIA);
        FormaMapa(tabPL);               //DA FORMATO AS MATRIZES CHAR QUE SERÃO IMPRESSAS
        FormaMapaIA(tabIA);
        BordaBase();                    //DAR VALOR AS BORDAS
        BordaBaseIA();
        while(Menu());                  //MENU DO JOGO, É RETORNADO ZERO PARA CADA OPÇÃO DO MENU
        if(!GeraAuto&&!Load){           //SE O JOGADOR DECIDIU ESCOLHER OS NAVIOS E CRIOU UM NOVO JOGO
            ZeraBaseIA();                   //ZERA A MATRIZ DE INTEIROS, POIS AGORA O JOGADOR ESCOLHERÁ
            EscolheNavios(baseIA);          //ESCOLHES OS NAVIOS NA MATRIZ DA IA, POIS É ELA QUEM VAI ATIRAR NOS NAVIOS QUE FORAM POSICIONADOS
            FormaMapa(tabPL);               //DÁ FORMATO A MATRIZ CHAR NOVAMENTE, POIS FOI UTILIZADO NA HORA DE ESCOLHER OS NAVIOS
        }
        if(Load){
            CarregaJogo();
        }
        ImprimeMapas();
        while(winIA==0&&winPL==0){      /// A PARTIDA COMEÇA AQUI! SE ENCERRARÁ QUANDO ALGUM JOGADOR DESTRUIR TODOS OS NAVIOS
            printf("\nTurno de JOGADOR\n");
            while(1){                           /// VEZ DO JOGADOR, VAI REPETIR ENQUANTO ACERTAR OS TIROS
                do{
                    fflush(stdin);                  // LIMPA O BUFFER
                    linha();
                    coluna();
                }while(VerificaTiro());
                system("cls");
                if(VerificaAcerto()){           // SE ACERTAR NA ÁGUA A ´R RETORNADO 1 PARA A FUNÇÃO E SAI DO LOOP DA VEZ DO JOGADOR
                    break;
                }
                if(PLc1>=4 && PLc2>=3 && PLc3>=2 && PLc4>=1){   // VERIFICA SE O JOGADOR DESTRUIU TODOS OS NAVIOS
                    winPL++;
                    break;
                }
            }
            SalvaJogo();
            while(winPL==0&&winIA==0){          /// VEZ DA IA, VAI REPETIR ENQUANTO ACERTAR OS TIROS
                system("pause");
                system("cls");
                if(z==0){                               // SE NÃO TIVER NENHUM NAVIO NA MIRA
                    GeraTiroIA(I,J);                           // GERA COORDENADA ALEARTORIA, QUE NÃO FOI ATIRADA AINDA
                }
                else{                                   // SE TIVER ACERTADO UM NAVIO E NAO TIVER DESTRUIDO AINDA
                    ProximoTiroIA();                        // TENTA ATIRAR NAS PROXIMIDADES
                }
                if(VerificaAcertoIA(I,J)){
                    break;
                }
                if(IAc1>=4 && IAc2>=3 && IAc3>=2 && IAc4>=1){// VERIFICA SE A IA DESTRUIU TODOS OS NAVIOS
                    winIA++;
                    break;
                }
            }
            SalvaJogo();
        }
        ImprimeMapas();
        VerificaVencedor(winIA);
        ApagaSave();
        if(JogarNovamente()){           // SE O JOGADOR ESCOLHEU JOGAR NOVAMENTE RETORNA 1 E REPETE O LOOP
            continue;
        }
        break;                          // SE NÃO, SAI DO LOOP
    }
    return 0;
}
