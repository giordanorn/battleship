#include "player.h"
#include "ia.h"

int x=0,y=0,z=0,I,J;                          /* COORDENADAS DA IA, x,y= posição do primeiro disparo em um navio (usado para atirar do outro lado caso não destrua)
                                                 z= AUXILIA A IA EM ATIRAR NOS REDORES CASO ACERTE UM TIRO, SE ACERTAR UM TIRO z VIRA VERDADEIRO */
int IAc1=0,IAc2=0,IAc3=0,IAc4=0,winIA=0;        // CONTADORES DA IA

char colunaInimigo(int j){                      // CONVERTE A COLUNA DA IA PARA O CARACTERE CORRESPONDENTE(USADO APENAS PARA O PRINTF)
    char x;
    switch (j){
        case 1:
            x='A';
            break;
        case 2:
            x='B';
            break;
        case 3:
            x='C';
            break;
        case 4:
            x='D';
            break;
        case 5:
            x='E';
            break;
        case 6:
            x='F';
            break;
        case 7:
            x='G';
            break;
        case 8:
            x='H';
            break;
        case 9:
            x='I';
            break;
        case 10:
            x='J';
            break;
        case 11:
            x='K';
            break;
        case 12:
            x='L';
            break;
        case 13:
            x='M';
            break;
        case 14:
            x='N';
            break;
        case 15:
            x='O';
            break;
        default:
            break;
    }
    return x;
}
void TiroCertoIA(){                             // PISCA A TELA EM VERMELHO E FAZ SOM
    Beep(400,50);
    system("color 40");
    system("color C0");
    system("color 40");
    system("color C0");
    system("color 40");
    system("color 0f");
    system("color f");
}
void ZeraBaseIA(){                              // ZERA A MATRIZ DE BASE(INT) DA IA
    int i,j;
    for(i=0;i<LIN;i++){                 // ZERANDO AS BASES
        for(j=0;j<COL;j++){
            baseIA[i][j]=WATER;
        }
    }
}
void BordaBaseIA(){                             // DA VALOR "EDGE" ÀS BORDAS DA MATRIZ DE BASE(INT)
    int i,j;
    for(i=0;i<LIN;i++){                 // NUMERANDO AS BORDAS
        for(j=0;j<COL;j++){
            if((i==0||j==0)||(i==LIN-1||j==COL-1)){
                baseIA[i][j]=EDGE;
                continue;
            }
        }
    }
}
void GeraNaviosIA(int base[][COL]){             // GERA OS NAVIOS DA IA ALEARTORIAMENTE
    int v,c,i,j; // v=Navio na vertical ou horizontal, c= Limita quantas vezes vai repetir os laços, i,j= coordenadas
    for(c=0;c<4;c++){               // GERA SUBMARINOS(NAVIO DE 1)
            do{
                i=(rand()%(LIN-2))+1;
                j=(rand()%(COL-2))+1;
            }while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||
            base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||
            base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0);  // EVITA NAVIOS ENCIMA DE NAVIOS

            base[i][j]=N1;
    }
    for(c=0;c<3;c++){               // GERA CORVETAS(NAVIO DE 2)
        v=rand()%2;                     // RANDOMIZA SE O BARCO VAI FICAR NA HORIZONTAL OU VERTICAL (0=horizontal,1=vertical)
        if(v==0){                       // SE FOR HORIZONTAL
            do{
                i=(rand()%(LIN-2))+1;
                j=(rand()%(COL-3))+1;
            }while(base[i][j]!=0  ||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||
            base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||base[i+1][j+2]!=0||
            base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0||base[i-1][j+2]!=0);  // EVITA NAVIOS ENCIMA DE NAVIOS

            base[i][j]=N2;
            base[i][j+1]=N2;
        }
        else{                           // VERTICAL
            do{
                i=(rand()%(LIN-3))+1;
                j=(rand()%(COL-2))+1;
            }while(base[i][j]!=0||base[i-1][j]!=0||base[i+1][j]!=0||base[i+2][j]!=0||
            base[i][j+1]!=0||base[i-1][j+1]!=0||base[i+1][j+1]!=0||base[i+2][j+1]!=0||
            base[i][j-1]!=0||base[i-1][j-1]!=0||base[i+1][j-1]!=0||base[i+2][j-1]!=0);  // EVITA NAVIOS SOBREPOSTOS

            base[i][j]=N2;
            base[i+1][j]=N2;
        }
    }
    for(c=0;c<2;c++){               // GERA FRAGATAS(NAVIO DE 3)
        v=rand()%2;
        if(v==0){
            do{
                i=(rand()%(LIN-2))+1;
                j=(rand()%(COL-4))+1;
            }while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||base[i][j+3]!=0|| // EVITA REPETIÇÕES
            base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0||base[i-1][j+2]!=0||base[i-1][j+3]!=0||
            base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||base[i+1][j+2]!=0||base[i+1][j+3]!=0);

            base[i][j]=N3;
            base[i][j+1]=N3;
            base[i][j+2]=N3;
        }
        else{
            do{
                i=(rand()%(LIN-4))+1;
                j=(rand()%(COL-2))+1;
            }while(base[i][j]!=0||base[i-1][j]!=0||base[i+1][j]!=0||base[i+2][j]!=0||base[i+3][j]!=0||
            base[i][j+1]!=0||base[i-1][j+1]!=0||base[i+1][j+1]!=0||base[i+2][j+1]!=0||base[i+3][j+1]!=0||
            base[i][j-1]!=0||base[i-1][j-1]!=0||base[i+1][j-1]!=0||base[i+2][j-1]!=0||base[i+3][j-1]!=0);  // EVITAR REPETIÇÕES

            base[i][j]=N3;
            base[i+1][j]=N3;
            base[i+2][j]=N3;
        }
    }
    for(c=0;c<1;c++){               // GERA PORTA-AVIOES(NAVIO DE 4)
        v=rand()%2;
        if(v==0){
            do{
                i=(rand()%(LIN-2))+1;
                j=(rand()%(COL-5))+1;
            }while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||base[i][j+3]!=0||base[i][j+4]!=0|| // EVITA REPETIÇÕES
            base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0||base[i-1][j+2]!=0||base[i-1][j+3]!=0||base[i-1][j+4]!=0||
            base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||base[i+1][j+2]!=0||base[i+1][j+3]!=0||base[i+1][j+4]!=0);

            base[i][j]=N4;
            base[i][j+1]=N4;
            base[i][j+2]=N4;
            base[i][j+3]=N4;
        }
        else{
            do{
            i=(rand()%(LIN-5))+1;
            j=(rand()%(COL-2))+1;
            }while(base[i][j]!=0||base[i-1][j]!=0||base[i+1][j]!=0||base[i+2][j]!=0||base[i+3][j]!=0||base[i+4][j]!=0||
            base[i][j+1]!=0||base[i-1][j+1]!=0||base[i+1][j+1]!=0||base[i+2][j+1]!=0||base[i+3][j+1]!=0||base[i+4][j+1]!=0||
            base[i][j-1]!=0||base[i-1][j-1]!=0||base[i+1][j-1]!=0||base[i+2][j-1]!=0||base[i+3][j-1]!=0||base[i+4][j-1]!=0);

            base[i][j]=N4;
            base[i+1][j]=N4;
            base[i+2][j]=N4;
            base[i+3][j]=N4;
        }
    }
}
void FormaMapaIA(char tab[][COL]){              // DA FORMATO AOS MAPAS
    int i,j,v,c;

    for(i=1,v=49,c=65;i<LIN; i++){
        for(j=1; j<COL; j++){
            tab[i][j] = '~';
        }
    }
    for(i=0,j=0,v=49;i<LIN-1;i++,v++){
        tab[i+1][j]=v;
        if(v==57){
            v=47;
        }
    }
    for(i=0,j=COL-1,v=49;i<LIN-1;i++,v++){
        tab[i+1][j]=v;
        if(v==57){
            v=47;
        }
    }
    for(i=0,j=0,c=65;j<COL-1;j++,c++){
        tab[i][j+1]=c;
    }
    for(i=LIN-1,j=0,c=65;j<COL-1;j++,c++){
        tab[i][j+1]=c;
    }
    tab[0][0]=' ';
    tab[0][COL-1]=' ';
    tab[LIN-1][0]=' ';
    tab[LIN-1][COL-1]=' ';
}
void ImprimeMapaIA(){                           // IMPRIME O MAPA DA IA
    int i,j;
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            if(i<10&&j==0){
                printf(" ");
            }
            if((i>=10&&i<LIN-1)&&j==0){
                printf("1");
            }
            if(j==COL-1&&(i>=10&&i<LIN-1)){
                printf("1");
            }
            if(i==COL-1&&j==0){
                printf(" ");
            }
            printf("%c ", tabIA[i][j]);
        }
        printf("\n");
    }
}

void GeraTiroIA(int i,int j){                              // GERA AS COORDENADAS DO TIRO DA IA
    do{
        i=(rand()%(LIN-2))+1;
        j=(rand()%(COL-2))+1;
    }while(tabIA[i][j]!='~'||tabIA[i+1][j]=='x'||tabIA[i-1][j]=='x'||
    tabIA[i][j+1]=='x'||tabIA[i+1][j+1]=='x'||tabIA[i-1][j+1]=='x'||
    tabIA[i][j-1]=='x'||tabIA[i+1][j-1]=='x'||tabIA[i-1][j-1]=='x');  // VERIFICA SE O TIRO JA FOI DADO NO LOCAL E SE ALGUM NAVIO ESTÁ NOS ARREDORES
    I=i;
    J=j;
}
void ProximoTiroIA(){                           // FUNÇÃO USADA PARA ATIRAR NOS ARREDORES
    if(tabIA[I+1][y]=='~'&&tabIA[I][y]=='*'&&tabIA[I+2][y]!='x'){   // OLHA SE O TEM AGUA ABAIXO E SE ACERTOU O TIRO ANTERIOR
        ++I;
    }
    else{                                                           // SE NÃO
        if(tabIA[I][y]==' '||I==LIN-1||tabIA[I+1][y]==' '){             // OLHA SE ERROU O TIRO ANTERIOR
            I=x;                                                            //SE ERROU, IGUALA i AO VALOR DO PRIMEIRO TIRO ACERTADO
        }
        if(tabIA[I-1][y]=='~'&&tabIA[I][y]=='*'&&tabIA[I-2][y]!='x'){   // OLHA SE ACIMA TEM AGUA E SE ACERTOU O TIRO ANTERIOR
            --I;
        }
        else{                                                           // SE NÃO
            if(tabIA[x][J+1]=='~'&&tabIA[x][J]=='*'&&tabIA[x][J+2]!='x'){   // OLHA SE A DIREITA TEM AGUA E SE ACERTOU O TIRO ANTERIOR
                ++J;
            }
            else{                                                           // SE NÃO
                if(tabIA[x][J]==' '||J==COL-1||tabIA[x][J+1]==' '){             // OLHA SE ERROU O TIRO ANTERIOR
                    J=y;
                }
                if(tabIA[x][J-1]=='~'&&tabIA[x][J]=='*'&&tabIA[x][J-2]!='x'){   // OLHA SE A ESQUERDA TEM AGUA E SE ACERTOU O TIRO ANTERIOR
                    --J;
                }
            }
        }
    }
}
int VerificaAcertoIA(int i,int j){              // VERIFICA SE A IA ACERTOU O TIRO
    if(baseIA[i][j] == N1_IA){                     // SE ACERTAR O NAVIO DE 1
        TiroCertoIA();
        TiroCertoIA();
        tabIA[i][j] = 'x';
        ImprimeMapas();
        printf("\nTurno de IA\n");
        printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
        printf("IA: ");
        printf("Acertou o tiro!\n");
        printf("Destruiu um Submarino!\n");
        IAc1++;
    }
    if(baseIA[i][j] == N2_IA){                     // SE ACERTAR O NAVIO DE 2
        if(z==0){
            x=i;
            y=j;
            z++;;
        }
        tabIA[i][j] = '*';
        TiroCertoIA();
        TiroCertoIA();
        ImprimeMapas();
        printf("\nTurno de IA\n");
        printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
        printf("IA: ");
        printf("Acertou o tiro!\n");
        if(tabIA[i+1][j]=='*'||tabIA[i][j+1]=='*'||tabIA[i-1][j]=='*'||tabIA[i][j-1]=='*'){  // SE O NAVIO FOI DESTRUIDO TRANSFORMA * EM x
            tabIA[i][j]='x';
            if(tabIA[i+1][j]=='*'){
                tabIA[i+1][j]='x';
            }
            if(tabIA[i-1][j]=='*'){
                tabIA[i-1][j]='x';
            }
            if(tabIA[i][j+1]=='*'){
                tabIA[i][j+1]='x';
            }
            if(tabIA[i][j-1]=='*'){
                tabIA[i][j-1]='x';
            }
            z=0;
            IAc2++;
            TiroCertoIA();
            TiroCertoIA();
            ImprimeMapas();
            printf("\nTurno de IA\n");
            printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
            printf("IA: ");
            printf("Acertou o tiro!\n");
            printf("Destruiu uma Corveta!\n");
        }
    }
    if(baseIA[i][j] == N3_IA){                     // SE ACERTAR O NAVIO DE 3
        if(z==0){
            x=i;
            y=j;
            z++;
        }
        tabIA[i][j] = '*';
        TiroCertoIA();
        TiroCertoIA();
        ImprimeMapas();
        printf("\nTurno de IA\n");
        printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
        printf("IA: ");
        printf("Acertou o tiro!\n");
        if ((tabIA[i+1][j]=='*'&& tabIA[i+2][j]=='*')||(tabIA[i-1][j]=='*'&& tabIA[i-2][j]=='*')||
            (tabIA[i][j+1]=='*'&& tabIA[i][j+2]=='*')||(tabIA[i][j-1]=='*'&& tabIA[i][j-2]=='*')){
            tabIA[i][j]='x';
            if(tabIA[i+1][j]=='*'&& tabIA[i+2][j]=='*'){
                tabIA[i+1][j]='x', tabIA[i+2][j]='x';
            }
            if(tabIA[i-1][j]=='*'&& tabIA[i-2][j]=='*'){
                tabIA[i-1][j]='x', tabIA[i-2][j]='x';
            }
            if(tabIA[i][j+1]=='*'&& tabIA[i][j+2]=='*'){
                tabIA[i][j+1]='x', tabIA[i][j+2]='x';
            }
            if(tabIA[i][j-1]=='*'&& tabIA[i][j-2]=='*'){
                tabIA[i][j-1]='x', tabIA[i][j-2]='x';
            }
            z=0;
            IAc3++;
            TiroCertoIA();
            TiroCertoIA();
            ImprimeMapas();
            printf("\nTurno de IA\n");
            printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
            printf("IA: ");
            printf("Acertou o tiro!\n");
            printf("Afundou um Cruzador!\n");
        }
    }
    if(baseIA[i][j] == N4_IA){                     // SE ACERTAR O NAVIO DE 4
        if(z==0){
            x=i;
            y=j;
            z++;
        }
        tabIA[i][j] = '*';
        TiroCertoIA();
        TiroCertoIA();
        ImprimeMapas();
        printf("\nTurno de IA\n");
        printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
        printf("IA: ");
        printf("Acertou o tiro!\n");
        if ((tabIA[i+1][j]=='*'&&tabIA[i+2][j]=='*'&&tabIA[i+3][j]=='*')||(tabIA[i-1][j]=='*'&&tabIA[i-2][j]=='*'&&tabIA[i-3][j]=='*')||
            (tabIA[i][j+1]=='*'&&tabIA[i][j+2]=='*'&&tabIA[i][j+3]=='*')||(tabIA[i][j-1]=='*'&&tabIA[i][j-2]=='*'&&tabIA[i][j-3]=='*')){
            tabIA[i][j]='x';
            if(tabIA[i+1][j]=='*'&&tabIA[i+2][j]=='*'&&tabIA[i+3][j]=='*'){
                tabIA[i+1][j]='x',tabIA[i+2][j]='x',tabIA[i+3][j]='x';
            }
            if(tabIA[i-1][j]=='*'&&tabIA[i-2][j]=='*'&&tabIA[i-3][j]=='*'){
                tabIA[i-1][j]='x',tabIA[i-2][j]='x',tabIA[i-3][j]='x';
            }
            if(tabIA[i][j+1]=='*'&&tabIA[i][j+2]=='*'&&tabIA[i][j+3]=='*'){
                tabIA[i][j+1]='x',tabIA[i][j+2]='x',tabIA[i][j+3]='x';
            }
            if(tabIA[i][j-1]=='*'&&tabIA[i][j-2]=='*'&&tabIA[i][j-3]=='*'){
                tabIA[i][j-1]='x',tabIA[i][j-2]='x',tabIA[i][j-3]='x';
            }
            z=0;
            IAc4++;
            TiroCertoIA();
            TiroCertoIA();
            ImprimeMapas();
            printf("\nTurno de IA\n");
            printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
            printf("IA: ");
            printf("Acertou o tiro!\n");
            printf("Afundou um Porta-Avioes!\n");
        }
    }
    if(baseIA[i][j] == WATER){                   // SE ERRAR O TIRO
        tabIA[i][j] = ' ';
        ImprimeMapas();
        printf("Turno de IA:\n");
        printf("IA Atirou em:\nLinha= %i Coluna= %c\n",i,colunaInimigo(j));
        printf("IA: ");
        printf("Acertou na agua\n");
        return 1;
    }
    return 0;
}



