#include "player.h"
#include "ia.h"

int PLc1=0, PLc2=0, PLc3=0, PLc4=0, winPL=0;                // CONTADORES DO JOGADOR
int GeraAuto=1, Load=0;                                  // VARIAVEIS QUE AUXILIAM EM GERAR OS NAVIOS AUTOMATICAMENTE E EM CARREGAR O JOGO

void
Instrucoes(void)
{
    system("clear");
    printf("-------------------  BATALHA NAVAL -------------------\n\n");
    printf("Informacoes gerais:\n");
    printf("-  Existem dois mapas, um para o jogador e um para a IA;\n\n");
    printf("-  Em cada mapa existem 4 submarinos(1 espaco), 3 corvetas(2 espacos),\n");
    printf("   2 cruzadores(3 espacos), e 1 porta-avioes(4 espacos);\n\n");
    printf("-  Navios nao ficam juntos um do outro,\n   sao separados por no minimo um espaco, incluindo as diagonais;\n\n");
    printf("-  O jogador vence quando destroi TODOS os navios,\n   e perde quando a IA destroi todos;\n\n");
    printf("-  Os acontecimentos aparecerao logo abaixo dos mapas, e sao atualizados a cada turno;\n\n");
    printf("-  O jogo salva automaticamente a cada turno;\n\n");
    printf("-  Ao terminar uma partida o save sera apagado.\n\n");
    printf("Instrucoes:\n");
    printf("* Para jogar voce deve informar a coordenada(linha e coluna) que deseja atirar;\n\n");
    printf("* Ao acertar um disparo, o jogador podera atirar novamente;\n\n");
    printf("* Para cada vez que a IA for jogar, voce devera apertar qualquer tecla para \n  poder prosseguir.\n\n");
    printf("* ");
    system("read -p \"Pressione enter para sair...\" saindo");
    system("clear");
}

int
Menu(void)
{                                     // MENU DE OP��ES
    system("color 0f");
    char s[2]={0,0};                        //CHAR QUE SER� SCANEADO
    while((s[0]<'1'||s[0]>'5')||s[1]!=0)
    {
        s[1]=0;
        system("clear");
        printf("-------------------  BATALHA NAVAL -------------------\n\n");
        printf("- Menu\n");
        printf("\t(1)-Novo Jogo\n");
        printf("\t(2)-Continuar\n");
        printf("\t(3)-Instrucoes\n");
        printf("\t(4)-Gerar Navios Automaticamente: ");
        if(GeraAuto)
            printf("Ativado\n");
        else{
            printf("Desativado\n");
        }
        printf("\t(5)-Sair\n");
        printf("Digite um valor referente ao menu (1 a 5): ");
        scanf("%s",&s);
    }
    switch(s[0])
    {           // SWITCH DO MENU DE OP��ES
        case '1':
            return 0;       // RETORNA ZERO PARA A FUN��O, FAZENDO COM QUE O WHILE DO main.c SEJA ENCERRADO
        case '2':
            Load=1;
             // CHAMA A FUN��O QUE CARREGA O JOGO ANTERIOR
            return 0;
        case '3':
            Instrucoes();   // CHAMA AS INSTRU��ES, RETORNA 1 PARA VOLTAR PRO MENU
            return 1;
        case '4':
            if(GeraAuto==0)
                GeraAuto=1;
            else
                GeraAuto=0;
            return 1;
        case '5':
            exit(0);        // ENCERRA O JOGO
            break;
        default:
            break;
    }
    return 0;
}

void
linha (void)
{                                   // DA SCAN NA LINHA DO JOGADOR
    char a[3]={0,0,0};                  // CHAR DE TAMANHO 3 POIS S�O 2 CARACTERES EM (10~15),O 3� SERVE PRA GARANTIR QUE N�O FORAM INSERIDOS MAIS DE 2 CARACTERES
    printf("Informe a Linha (1 a 15): ");
    scanf("%s",&a);
    while((a[0]<='0'||a[0]>'9')||(a[0]=='1'&&a[1]>'5')||(a[0]!='1'&&a[1]!=0)||a[2]!=0)
    {
        printf("Digite um valor entre 1 e 15: ");
        a[2]=0;
        scanf("%s",&a);
    }
    if(a[1]==0)
    {
        switch(a[0])
        {
        case '1':
            i=1;
            break;
        case '2':
            i=2;
            break;
        case '3':
            i=3;
            break;
        case '4':
            i=4;
            break;
        case '5':
            i=5;
            break;
        case '6':
            i=6;
            break;
        case '7':
            i=7;
            break;
        case '8':
            i=8;
            break;
        case '9':
            i=9;
            break;
        default:
            break;
        }
    }
    else{
        switch(a[1])
        {
            case '0':
                i=10;
                break;
            case '1':
                i=11;
                break;
            case '2':
                i=12;
                break;
            case '3':
                i=13;
                break;
            case '4':
                i=14;
                break;
            case '5':
                i=15;
                break;
            default:
                break;
        }
    }
}

void
coluna (void)
{                                  // DA SCAN NA COLUNA DO JOGADOR
    char b[2] = {0, 0};
    printf("Informe a Coluna (A a O): ");
    scanf("%s",&b);
    while (((b[0]<'a' || b[0]>'o')&&(b[0]<'A' || b[0]>'O'))||(b[1]!=0))
    {
        b[1]=0;
        printf("Por favor digite um caractere entre A e O: ");
        scanf("%s",&b);
    }
    switch(b[0])
    {
        case 'A':
            j=1;
            break;
        case 'B':
            j=2;
            break;
        case 'C':
            j=3;
            break;
        case 'D':
            j=4;
            break;
        case 'E':
            j=5;
            break;
        case 'F':
            j=6;
            break;
        case 'G':
            j=7;
            break;
        case 'H':
            j=8;
            break;
        case 'I':
            j=9;
            break;
        case 'J':
            j=10;
            break;
        case 'K':
            j=11;
            break;
        case 'L':
            j=12;
            break;
        case 'M':
            j=13;
            break;
        case 'N':
            j=14;
            break;
        case 'O':
            j=15;
            break;
        case 'a':
            j=1;
            break;
        case 'b':
            j=2;
            break;
        case 'c':
            j=3;
            break;
        case 'd':
            j=4;
            break;
        case 'e':
            j=5;
            break;
        case 'f':
            j=6;
            break;
        case 'g':
            j=7;
            break;
        case 'h':
            j=8;
            break;
        case 'i':
            j=9;
            break;
        case 'j':
            j=10;
            break;
        case 'k':
            j=11;
            break;
        case 'l':
            j=12;
            break;
        case 'm':
            j=13;
            break;
        case 'n':
            j=14;
            break;
        case 'o':
            j=15;
            break;
        default:
            break;
    }
}
void TiroCerto (void)
{                               // PISCA A TELA EM BRANCO E FAZ SOM
    ////Beep(500,50);
    system("color f0");
    system("color f");
    system("color f0");
    system("color f");
    system("color f0");
    system("color f");
}

int
VerificaTiro (void)
{                             // VERIFICA SE O TIRO DO JOGADOR JA FOI DADO NO LOCAL
    if(tabPL[i][j]!='~')
    {                    // VERIFICA SE O TIRO JA FOI DADO NO LOCAL
        printf("Voce ja atirou nesse local!\n");
        return 1;
    }
    return 0;
}

int
VerificaAcerto (void)
{                           // VERIFICA SE ACERTOU ALGUM NAVIO
    if(basePL[i][j] == N1)
    {                     // SE ACERTAR O NAVIO DE 1
        TiroCerto();
        TiroCerto();
        tabPL[i][j] = 'x';
        ImprimeMapas();
        printf("Jogador: ");
        printf("Acertou o tiro!\n");
        printf("Destruiu um Submarino!\n");
        PLc1++;
    }
    if(basePL[i][j] == N2)
    {                     // SE ACERTAR O NAVIO DE 2
        TiroCerto();
        TiroCerto();
        tabPL[i][j] = '*';
        ImprimeMapas();
        printf("\nTurno de JOGADOR\n");
        printf("Jogador: ");
        printf("Acertou o tiro!\n");
        if(tabPL[i+1][j]=='*'||tabPL[i][j+1]=='*'||tabPL[i-1][j]=='*'||tabPL[i][j-1]=='*')
        {
            tabPL[i][j]='x';
            if(tabPL[i+1][j]=='*')
            {
                tabPL[i+1][j]='x';
            }
            if(tabPL[i-1][j]=='*')
            {
                tabPL[i-1][j]='x';
            }
            if(tabPL[i][j+1]=='*')
            {
                tabPL[i][j+1]='x';
            }
            if(tabPL[i][j-1]=='*')
            {
                tabPL[i][j-1]='x';
            }
            PLc2++;
            TiroCerto();
            TiroCerto();
            ImprimeMapas();
            printf("\nTurno de JOGADOR\n");
            printf("Jogador: ");
            printf("Acertou o tiro!\n");
            printf("Destruiu uma Corveta!\n");
        }
    }
    if(basePL[i][j] == N3)
    {                     // SE ACERTAR O NAVIO DE 3
        TiroCerto();
        TiroCerto();
        tabPL[i][j] = '*';
        ImprimeMapas();
        printf("\nTurno de JOGADOR\n");
        printf("Jogador: ");
        printf("Acertou o tiro!\n");
        if ((tabPL[i+1][j]=='*'&& tabPL[i+2][j]=='*')||(tabPL[i-1][j]=='*'&& tabPL[i-2][j]=='*')||
            (tabPL[i][j+1]=='*'&& tabPL[i][j+2]=='*')||(tabPL[i][j-1]=='*'&& tabPL[i][j-2]=='*'))
            {
            tabPL[i][j]='x';
            if(tabPL[i+1][j]=='*'&& tabPL[i+2][j]=='*')
            {
                tabPL[i+1][j]='x', tabPL[i+2][j]='x';
            }
            if(tabPL[i-1][j]=='*'&& tabPL[i-2][j]=='*')
            {
                tabPL[i-1][j]='x', tabPL[i-2][j]='x';
            }
            if(tabPL[i][j+1]=='*'&& tabPL[i][j+2]=='*')
            {
                tabPL[i][j+1]='x', tabPL[i][j+2]='x';
            }
            if(tabPL[i][j-1]=='*'&& tabPL[i][j-2]=='*')
            {
                tabPL[i][j-1]='x', tabPL[i][j-2]='x';
            }
            PLc3++;
            TiroCerto();
            TiroCerto();
            ImprimeMapas();
            printf("\nTurno de JOGADOR\n");
            printf("Jogador: ");
            printf("Acertou o tiro!\n");
            printf("Afundou um Cruzador!\n");
        }
    }
    if(basePL[i][j] == N4)
    {                     // SE ACERTAR O NAVIO DE 4
        TiroCerto();
        TiroCerto();
        tabPL[i][j] = '*';
        ImprimeMapas();
        printf("\nTurno de JOGADOR\n");
        printf("Jogador: ");
        printf("Acertou o tiro!\n");
        if ((tabPL[i+1][j]=='*'&&tabPL[i+2][j]=='*'&&tabPL[i+3][j]=='*')||(tabPL[i-1][j]=='*'&&tabPL[i-2][j]=='*'&&tabPL[i-3][j]=='*')||
            (tabPL[i][j+1]=='*'&&tabPL[i][j+2]=='*'&&tabPL[i][j+3]=='*')||(tabPL[i][j-1]=='*'&&tabPL[i][j-2]=='*'&&tabPL[i][j-3]=='*'))
            {
            tabPL[i][j]='x';
            if(tabPL[i+1][j]=='*'&&tabPL[i+2][j]=='*'&&tabPL[i+3][j]=='*')
            {
                tabPL[i+1][j]='x',tabPL[i+2][j]='x',tabPL[i+3][j]='x';
            }
            if(tabPL[i-1][j]=='*'&&tabPL[i-2][j]=='*'&&tabPL[i-3][j]=='*')
            {
                tabPL[i-1][j]='x',tabPL[i-2][j]='x',tabPL[i-3][j]='x';
            }
            if(tabPL[i][j+1]=='*'&&tabPL[i][j+2]=='*'&&tabPL[i][j+3]=='*')
            {
                tabPL[i][j+1]='x',tabPL[i][j+2]='x',tabPL[i][j+3]='x';
            }
            if(tabPL[i][j-1]=='*'&&tabPL[i][j-2]=='*'&&tabPL[i][j-3]=='*')
            {
                tabPL[i][j-1]='x',tabPL[i][j-2]='x',tabPL[i][j-3]='x';
            }
            PLc4++;
            TiroCerto();
            TiroCerto();
            ImprimeMapas();
            printf("\nTurno de JOGADOR\n");
            printf("Jogador: ");
            printf("Acertou o tiro!\n");
            printf("Afundou um Porta-Avioes!\n");
        }
    }
    if(basePL[i][j] == WATER)
    {                  // SE ERRAR O TIRO
        tabPL[i][j] = ' ';
        ImprimeMapas();
        printf("\nTurno de JOGADOR\n");
        printf("Jogador: ");
        printf("Acertou na agua\n");
        return 1;
    }
    return 0;
}

void
ImprimeMapa (void)
{                             // IMPRIME OS MAPA DO PLAYER
    int i,j;
    for(i=0; i<LIN; i++)
    {
        for(j=0; j<COL; j++)
        {
            if(i<10&&j==0)
            {
                printf(" ");
            }
            if((i>=10&&i<LIN-1)&&j==0)
            {
                printf("1");
            }
            if(j==COL-1&&(i>=10&&i<LIN-1))
            {
                printf("1");
            }
            if(i==COL-1&&j==0)
            {
                printf(" ");
            }
            printf("%c ", tabPL[i][j]);
        }
        printf("\n");
    }
}

void
ImprimeMapas (void)
{                            // IMPRIME AMBOS OS MAPAS J� FORMATADOS
    system("clear");
    printf("\t      JOGADOR\n");
    ImprimeMapa();
    printf("\n\n\t    OPONENTE IA\n");
    ImprimeMapaIA();
}

void
ZeraBase (void)
{                                // ZERA A MATRIZ BASE DO JOGADOR
    int i,j;
    for(i=0;i<LIN;i++)
    {                 // ZERANDO AS BASES
        for(j=0;j<COL;j++)
        {
            basePL[i][j]=WATER;
        }
    }
}

void
BordaBase (void)
{                               // NUMERA AS BORDAS DA MATRIZ DE BASE(INT)
    int i,j;
    for(i=0;i<LIN;i++)
    {                 // ZERANDO AS BASES
        for(j=0;j<COL;j++)
        {
            if((i==0||j==0)||(i==LIN-1||j==COL-1))
            {
                basePL[i][j]=EDGE;
                continue;
            }
        }
    }
}

void
GeraNavios (int base[][COL])
{               // GERA OS NAVIOS AUTOMATICAMENTE
    int v, c, i, j;
    for(c=0;c<4;c++)
    {               // GERA SUBMARINOS(NAVIO DE 1)
            do{
                i=(rand()%(LIN-2))+1;
                j=(rand()%(COL-2))+1;
            }while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||
            base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||
            base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0);  // EVITA NAVIOS ENCIMA DE NAVIOS

            base[i][j]=N1;
    }
    for(c=0;c<3;c++)
    {               // GERA CORVETAS(NAVIO DE 2)
        v=rand()%2;                     // RANDOMIZA SE O BARCO VAI FICAR NA HORIZONTAL OU VERTICAL (0=horizontal,1=vertical)
        if(v==0)
        {                       // SE FOR HORIZONTAL
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
    for(c=0;c<2;c++)
    {               // GERA FRAGATAS(NAVIO DE 3)
        v=rand()%2;
        if(v==0)
        {
            do{
                i=(rand()%(LIN-2))+1;
                j=(rand()%(COL-4))+1;
            }while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||base[i][j+3]!=0|| // EVITA REPETI��ES
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
            base[i][j-1]!=0||base[i-1][j-1]!=0||base[i+1][j-1]!=0||base[i+2][j-1]!=0||base[i+3][j-1]!=0);  // EVITAR REPETI��ES

            base[i][j]=N3;
            base[i+1][j]=N3;
            base[i+2][j]=N3;
        }
    }
    for(c=0;c<1;c++)
    {               // GERA PORTA-AVIOES(NAVIO DE 4)
        v=rand()%2;
        if(v==0)
        {
            do{
                i=(rand()%(LIN-2))+1;
                j=(rand()%(COL-5))+1;
            }while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||base[i][j+3]!=0||base[i][j+4]!=0|| // EVITA REPETI��ES
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

void
FormaMapa (char tab[][COL])
{                // DA FORMATO AOS MAPAS
    int i,j,v,c;
    for(i=1,v=49,c=65;i<LIN; i++)
    {
        for(j=1; j<COL; j++)
        {
            tab[i][j] = '~';
        }
    }
    for(i=0,j=0,v=49;i<LIN-1;i++,v++)
    {
        tab[i+1][j]=v;
        if(v==57)
        {
            v=47;
        }
    }
    for(i=0,j=COL-1,v=49;i<LIN-1;i++,v++)
    {
        tab[i+1][j]=v;
        if(v==57)
        {
            v=47;
        }
    }
    for(i=0,j=0,c=65;j<COL-1;j++,c++)
    {
        tab[i][j+1]=c;
    }
    for(i=LIN-1,j=0,c=65;j<COL-1;j++,c++)
    {
        tab[i][j+1]=c;
    }
    tab[0][0]=' ';
    tab[0][COL-1]=' ';
    tab[LIN-1][0]=' ';
    tab[LIN-1][COL-1]=' ';
}

/* FUN��ES USADAS QUANDO O JOGADOR ESCOLHE A POSI��O DOS NAVIOS */
int
VH (void)
{                               // ESCOLHE SE O NAVIO FICA NA HORIZONTAL OU VERTICAL
    char s[2]={0,0};
    do{
        s[1]=0;
        printf("Navio na vertical ou horizontal(V/H): ");
        scanf("%s",&s);
    }while((s[0]!='v'&&s[0]!='V'&&s[0]!='h'&&s[0]!='H')||s[1]!=0); //S� VAI SAIR DA CONDI��O QUANDO FOR DIGITADO V,v,H OU h
    if(s[0]=='v'||s[0]=='V')
    {
        return 1;
    }
    else{
        return 0;
    }
}

int
LinhaEscolherNavio (int tam)
{        // ESCOLHE A LINHA DO NAVIO
    char a[3]={0,0,0};
    printf("Informe a Linha (1 a %i): ",tam);
    scanf("%s",&a);
    while((a[0]<='0'||a[0]>'9')||(a[0]=='1'&&a[1]>tam+38)||(a[0]!='1'&&a[1]!=0)||a[2]!=0)
    {
        printf("Digite um valor entre 1 e %i: ",tam);
        a[2]=0;
        scanf("%s",&a);
    }
    if(a[1]==0)
    {
        switch(a[0])
        {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            break;
        }
    }
    else{
        switch(a[1])
        {
            case '0':
                return 10;
            case '1':
                return 11;
            case '2':
                return 12;
            case '3':
                return 13;
            case '4':
                return 14;
            case '5':
                return 15;
            default:
                break;
        }
    }
    return 0;
}

int
ColunaEscolherNavio (int tam)
{       // ESCOLHE A COLUNA DO NAVIO
    char b[2]={0,0};
    do{
        b[1]=0;
        printf("Informe a Coluna (A a %c): ",tam+64);
        scanf("%s",&b);
    }while(((b[0]<'a' || b[0]>tam+96)&&(b[0]<'A' || b[0]>tam+64))||(b[1]!=0));
    switch(b[0])
    {
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'C':
            return 3;
        case 'D':
            return 4;
        case 'E':
            return 5;
        case 'F':
            return 6;
        case 'G':
            return 7;
        case 'H':
            return 8;
        case 'I':
            return 9;
        case 'J':
            return 10;
        case 'K':
            return 11;
        case 'L':
            return 12;
        case 'M':
            return 13;
        case 'N':
            return 14;
        case 'O':
            return 15;
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'c':
            return 3;
        case 'd':
            return 4;
        case 'e':
            return 5;
        case 'f':
            return 6;
        case 'g':
            return 7;
        case 'h':
            return 8;
        case 'i':
            return 9;
        case 'j':
            return 10;
        case 'k':
            return 11;
        case 'l':
            return 12;
        case 'm':
            return 13;
        case 'n':
            return 14;
        case 'o':
            return 15;
        default:
            break;
    }
    return 0;
}

void
ImprimeEscolheNavio (void)
{             // IMPRIME OS NAVIOS QUE FORAM ESCOLHIDOS
    int i,j,v,c;
    printf("!INFORME ONDE DEVEM FICAR OS NAVIOS!\n");
    for(i=0,j=0,v=49;i<LIN-1;i++,v++)
    {
        tabPL[i+1][j]=v;
        if(v==57)
        {
            v=47;
        }
    }
    for(i=0,j=COL-1,v=49;i<LIN-1;i++,v++)
    {
        tabPL[i+1][j]=v;
        if(v==57)
        {
            v=47;
        }
    }
    for(i=0,j=0,c=65;j<COL-1;j++,c++)
    {
        tabPL[i][j+1]=c;
    }
    for(i=LIN-1,j=0,c=65;j<COL-1;j++,c++)
    {
        tabPL[i][j+1]=c;
    }
    tabPL[0][0]=' ';
    tabPL[0][COL-1]=' ';
    tabPL[LIN-1][0]=' ';
    tabPL[LIN-1][COL-1]=' ';
    for(i=0; i<LIN; i++)
    {
        for(j=0; j<COL; j++)
        {
            if(i<10&&j==0)
            {
                printf(" ");
            }
            if((i>=10&&i<LIN-1)&&j==0)
            {
                printf("1");
            }
            if(j==COL-1&&(i>=10&&i<LIN-1))
            {
                printf("1");
            }
            if(i==COL-1&&j==0)
            {
                printf(" ");
            }
            printf("%c ", tabPL[i][j]);
        }
        printf("\n");
    }
}

void
EscolheNavios (int base[][COL])
{    // P�E OS NAVIOS NA MATRIZ DE BASE(INT), E TABULEIRO(CHAR) (USA A MESMA L�GICA DA FUN��O GeraNavios)
    int v,c,i,j;
    for(c=1;c;c--)
    {               // ESCOLHE PORTA-AVIOES(NAVIO DE 4)
        system("clear");
        ImprimeEscolheNavio();
        printf("Navio: Porta-avioes - Tamanho 4 (Restam 1)\n");
        v=VH();
        if(v==0)
        {                    //HORIZONTAL
            i=LinhaEscolherNavio(LIN-2);
            j=ColunaEscolherNavio(COL-5);
            while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||base[i][j+3]!=0||base[i][j+4]!=0|| // EVITA REPETI��ES
            base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0||base[i-1][j+2]!=0||base[i-1][j+3]!=0||base[i-1][j+4]!=0||
            base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||base[i+1][j+2]!=0||base[i+1][j+3]!=0||base[i+1][j+4]!=0)
            {
                printf("O navio esta sobreposto!\n");
                i=LinhaEscolherNavio(LIN-2);
                j=ColunaEscolherNavio(COL-5);
            }
            base[i][j]=N4,base[i][j+1]=N4,base[i][j+2]=N4,base[i][j+3]=N4;
            tabPL[i][j]='*'  ,tabPL[i][j+1]='*'  ,tabPL[i][j+2]='*'  ,tabPL[i][j+3]='*'  ,tabPL[i][j-1]='-'  ,tabPL[i][j+4]='-';
            tabPL[i-1][j]='-',tabPL[i-1][j+1]='-',tabPL[i-1][j+2]='-',tabPL[i-1][j+3]='-',tabPL[i-1][j-1]='-',tabPL[i-1][j+4]='-';
            tabPL[i+1][j]='-',tabPL[i+1][j+1]='-',tabPL[i+1][j+2]='-',tabPL[i+1][j+3]='-',tabPL[i+1][j-1]='-',tabPL[i+1][j+4]='-';
        }
        else{                        //VERTICAL
            i=LinhaEscolherNavio(LIN-5);
            j=ColunaEscolherNavio(COL-2);
            while(base[i][j]!=0||base[i-1][j]!=0||base[i+1][j]!=0||base[i+2][j]!=0||base[i+3][j]!=0||base[i+4][j]!=0||
                  base[i][j+1]!=0||base[i-1][j+1]!=0||base[i+1][j+1]!=0||base[i+2][j+1]!=0||base[i+3][j+1]!=0||base[i+4][j+1]!=0||
                  base[i][j-1]!=0||base[i-1][j-1]!=0||base[i+1][j-1]!=0||base[i+2][j-1]!=0||base[i+3][j-1]!=0||base[i+4][j-1]!=0)
                  {  // evitar repeti�oes
                printf("O navio est� sobreposto!\n");
                i=LinhaEscolherNavio(LIN-5);
                j=ColunaEscolherNavio(COL-2);
            }
            base[i][j]=N4,base[i+1][j]=N4,base[i+2][j]=N4,base[i+3][j]=N4;
            tabPL[i][j]='*',tabPL[i+1][j]='*',tabPL[i+2][j]='*',tabPL[i+3][j]='*',tabPL[i-1][j]='-',tabPL[i+4][j]='-';
            tabPL[i][j-1]='-',tabPL[i+1][j-1]='-',tabPL[i+2][j-1]='-',tabPL[i+3][j-1]='-',tabPL[i+4][j-1]='-',tabPL[i-1][j-1]='-';
            tabPL[i][j+1]='-',tabPL[i+1][j+1]='-',tabPL[i+2][j+1]='-',tabPL[i+3][j+1]='-',tabPL[i+4][j+1]='-',tabPL[i-1][j+1]='-';
        }
    }
    for(c=2;c;c--)
    {               // ESCOLHE FRAGATAS(NAVIO DE 3)
        system("clear");
        ImprimeEscolheNavio();
        printf("Navio: Fragata - Tamanho 3 (Restam %i)\n",c);
        v=VH();
        if(v==0)
        {
            i=LinhaEscolherNavio(LIN-2);
            j=ColunaEscolherNavio(COL-4);
            while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||base[i][j+3]!=0|| // EVITA REPETI��ES
                  base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0||base[i-1][j+2]!=0||base[i-1][j+3]!=0||
                  base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||base[i+1][j+2]!=0||base[i+1][j+3]!=0)
                  {
                printf("O navio esta sobreposto!\n");
                i=LinhaEscolherNavio(LIN-2);
                j=ColunaEscolherNavio(COL-4);
            }
            base[i][j]=N3,base[i][j+1]=N3,base[i][j+2]=N3;
            tabPL[i][j]='*',tabPL[i][j+1]='*',tabPL[i][j+2]='*',tabPL[i][j-1]='-',tabPL[i][j+3]='-';
            tabPL[i-1][j]='-',tabPL[i-1][j+1]='-',tabPL[i-1][j+2]='-',tabPL[i-1][j+3]='-',tabPL[i-1][j-1]='-';
            tabPL[i+1][j]='-',tabPL[i+1][j+1]='-',tabPL[i+1][j+2]='-',tabPL[i+1][j+3]='-',tabPL[i+1][j-1]='-';
        }
        else{
            i=LinhaEscolherNavio(LIN-4);
            j=ColunaEscolherNavio(COL-2);
            while(base[i][j]!=0||base[i-1][j]!=0||base[i+1][j]!=0||base[i+2][j]!=0||base[i+3][j]!=0||
                  base[i][j+1]!=0||base[i-1][j+1]!=0||base[i+1][j+1]!=0||base[i+2][j+1]!=0||base[i+3][j+1]!=0||
                  base[i][j-1]!=0||base[i-1][j-1]!=0||base[i+1][j-1]!=0||base[i+2][j-1]!=0||base[i+3][j-1]!=0)
                  {  // EVITAR REPETI��ES
                printf("O navio esta sobreposto!\n");
                i=LinhaEscolherNavio(LIN-4);
                j=ColunaEscolherNavio(COL-2);
            }
            base[i][j]=N3,base[i+1][j]=N3,base[i+2][j]=N3;
            tabPL[i][j]='*',tabPL[i+1][j]='*',tabPL[i+2][j]='*',tabPL[i-1][j]='-',tabPL[i+3][j]='-';
            tabPL[i][j-1]='-',tabPL[i+1][j-1]='-',tabPL[i+2][j-1]='-',tabPL[i+3][j-1]='-',tabPL[i-1][j-1]='-';
            tabPL[i][j+1]='-',tabPL[i+1][j+1]='-',tabPL[i+2][j+1]='-',tabPL[i+3][j+1]='-',tabPL[i-1][j+1]='-';
        }
    }
    for(c=3;c;c--)
    {               // ESCOLHE CORVETAS(NAVIO DE 2)
        system("clear");
        ImprimeEscolheNavio();
        printf("Navio: Corveta - Tamanho 2 (Restam %i)\n",c);
        v=VH();                    // ESCOLHE SE O BARCO VAI SER NA HORIZONTAL OU VERTICAL
        if(v==0)
        {                       // SE FOR HORIZONTAL
            i=LinhaEscolherNavio(LIN-2);
            j=ColunaEscolherNavio(COL-3);
            while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||base[i][j+2]!=0||
            base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||base[i+1][j+2]!=0||
            base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0||base[i-1][j+2]!=0)
            {  // EVITA NAVIOS ENCIMA DE NAVIOS
                printf("O navio esta sobreposto!\n");
                i=LinhaEscolherNavio(LIN-2);
                j=ColunaEscolherNavio(COL-3);
            }
            base[i][j]=N2,base[i][j+1]=N2;
            tabPL[i][j]='*',tabPL[i][j+1]='*',tabPL[i][j-1]='-',tabPL[i][j+2]='-';
            tabPL[i-1][j]='-',tabPL[i-1][j+1]='-',tabPL[i-1][j+2]='-',tabPL[i-1][j-1]='-';
            tabPL[i+1][j]='-',tabPL[i+1][j+1]='-',tabPL[i+1][j+2]='-',tabPL[i+1][j-1]='-';
        }
        else{                           // VERTICAL
            i=LinhaEscolherNavio(LIN-3);
            j=ColunaEscolherNavio(COL-2);
            while(base[i][j]!=0||base[i-1][j]!=0||base[i+1][j]!=0||base[i+2][j]!=0||
            base[i][j+1]!=0||base[i-1][j+1]!=0||base[i+1][j+1]!=0||base[i+2][j+1]!=0||
            base[i][j-1]!=0||base[i-1][j-1]!=0||base[i+1][j-1]!=0||base[i+2][j-1]!=0)
            {  // evitar repeti�oes
                printf("O navio esta sobreposto!\n");
                i=LinhaEscolherNavio(LIN-3);
                j=ColunaEscolherNavio(COL-2);
            }
            base[i][j]=N2,base[i+1][j]=N2;
            tabPL[i][j]='*',tabPL[i+1][j]='*',tabPL[i-1][j]='-',tabPL[i+2][j]='-';
            tabPL[i][j-1]='-',tabPL[i+1][j-1]='-',tabPL[i+2][j-1]='-',tabPL[i-1][j-1]='-';
            tabPL[i][j+1]='-',tabPL[i+1][j+1]='-',tabPL[i+2][j+1]='-',tabPL[i-1][j+1]='-';
        }
    }
    for(c=4;c;c--)
    {               // ESCOLHE SUBMARINOS(NAVIO DE 1)
        system("clear");
        ImprimeEscolheNavio();
        printf("Navio: Submarino - tamanho 1 (restam %i)\n",c);
        i=LinhaEscolherNavio(LIN-2);
        j=ColunaEscolherNavio(COL-2);
        while(base[i][j]!=0||base[i][j-1]!=0||base[i][j+1]!=0||
        base[i+1][j]!=0||base[i+1][j-1]!=0||base[i+1][j+1]!=0||
        base[i-1][j]!=0||base[i-1][j-1]!=0||base[i-1][j+1]!=0)
        { // EVITA NAVIOS ENCIMA DE NAVIOS
            printf("O navio esta sobreposto!\n");
            i=LinhaEscolherNavio(LIN-2);
            j=ColunaEscolherNavio(COL-2);
        }
        base[i][j]=N1;
        tabPL[i][j]='*',tabPL[i][j+1]='-',tabPL[i][j-1]='-';
        tabPL[i-1][j]='-',tabPL[i-1][j+1]='-',tabPL[i-1][j-1]='-';
        tabPL[i+1][j]='-',tabPL[i+1][j+1]='-',tabPL[i+1][j-1]='-';
    }
}

void
SalvaJogo (void)
{
    int i, j;
    FILE *arq;
    arq = fopen("data.txt","w");
    for (i = 0; i < LIN; i++)
    {             // SALVA A MATRIZ BASE DO PLAYER
        for (j = 0; j < COL; j++)
        {
            fprintf(arq,"%i ",basePL[i][j]);
        }
        fprintf(arq,"\n");
    }
    for (i = 0; i < LIN; i++)
    {             // SALVA A MATRIZ BASE DA IA
        for (j = 0; j < COL; j++)
        {
            fprintf(arq,"%i ",baseIA[i][j]);
        }
        fprintf(arq,"\n");
    }
    for(i = 1; i < LIN - 1; i++)
    {           // SALVA A MATRIZ CHAR DO PLAYER
        for(j = 1; j < COL - 1; j++)
        {
            if(tabPL[i][j]==' ')
            {
                fprintf(arq,"-");       // O TIRO DADO NA �GUA � SALVO COMO - PARA N�O HAVER PROBLEMA NA HORA DE DAR FSCANF ESPA�OS(� CONVERTIDO DE VOLTA PARA ESPA�O QUANDO L�)
                continue;
            }
            fprintf(arq,"%c",tabPL[i][j]);
        }
        fprintf(arq,"\n");
    }
    for(i=1;i<LIN-1;i++)
    {           // SALVA A MATRIZ CHAR DO PLAYER
        for(j=1;j<COL-1;j++)
        {
            if(tabIA[i][j]==' ')
            {
                fprintf(arq,"-");       // O TIRO DADO NA �GUA � SALVO COMO - PARA N�O HAVER PROBLEMA NA HORA DE DAR FSCANF ESPA�OS(� CONVERTIDO DE VOLTA PARA ESPA�O QUANDO L�)
                continue;
            }
            fprintf(arq,"%c",tabIA[i][j]);
        }
        fprintf(arq,"\n");
    }
    fprintf(arq,"%i %i %i %i %i %i %i %i %i %i %i %i %i",PLc1,PLc2,PLc3,PLc4,IAc1,IAc2,IAc3,IAc4,x,y,z,I,J); // SALVA OS CONTADORES E AS POSI�OES DOS TIROS DA IA
    fclose(arq);
}

void
CarregaJogo (void)
{
    int i,j;
    FILE *arq;
    arq=fopen("data.txt","r");
    for(i=0;i<LIN;i++)
    {             // CARREGA A MATRIZ BASE DO PLAYER
        for(j=0;j<COL;j++)
        {
            fscanf(arq,"%i",&basePL[i][j]);
        }
        fscanf(arq,"\n");
    }
    for(i=0;i<LIN;i++)
    {             // CARREGA A MATRIZ BASE DA IA
        for(j=0;j<COL;j++)
        {
            fscanf(arq,"%i",&baseIA[i][j]);
        }
        fscanf(arq,"\n");
    }
    for(i=1;i<LIN-1;i++)
    {           // CARREGA A MATRIZ CHAR DO PLAYER
        for(j=1;j<COL-1;j++)
        {
            fscanf(arq,"%c",&tabPL[i][j]);
            if(tabPL[i][j]=='-')
            {           // CONVERS�O DE - PARA ESPA�O
                tabPL[i][j]=' ';
            }
        }
        fscanf(arq,"\n");
    }
    for(i=1;i<LIN-1;i++)
    {           // CARREGA A MATRIZ CHAR DO PLAYER
        for(j=1;j<COL-1;j++)
        {
            fscanf(arq,"%c",&tabIA[i][j]);
            if(tabIA[i][j]=='-')
            {           // CONVERS�O DE - PARA ESPA�O
                tabIA[i][j]=' ';
            }
        }
        fscanf(arq,"\n");
    }
    fscanf(arq,"%i%i%i%i%i%i%i%i%i%i%i%i%i",&PLc1,&PLc2,&PLc3,&PLc4,&IAc1,&IAc2,&IAc3,&IAc4,&x,&y,&z,&I,&J); // CARREGA OS CONTADORES E AS POSI�OES DOS TIROS DA IA
    fclose(arq);
}

void
VerificaVencedor (int winner)
{
    if(winner==0)
    {
        printf(" FIM DE JOGO \n PARABENS!!!!! \n VOCE VENCEU \n");
        SomVitoria();
    }
    else{
        printf(" FIM DE JOGO \n VOCE FOI DERROTADO! \n TENTE NOVAMENTE...\n");
        SomDerrota();
    }
}

void
SomDerrota (void)
{
    //Beep (207,400);
    //Beep (196,400);
    //Beep (185,400);
    //Beep (174,1500);
}

void
SomVitoria (void)
{
    //Beep (196,200);
    //Beep (262,200);
    //Beep (330,200);
    //Beep (392,200);
    //Beep (523,200);
    //Beep (660,200);
    //Beep (784,600);
    //Beep (660,600);
    //Beep (207,200);
    //Beep (262,200);
    //Beep (311,200);
    //Beep (415,200);
    //Beep (523,200);
    //Beep (622,200);
    //Beep (830,600);
    //Beep (622,600);
    //Beep (233,200);
    //Beep (294,200);
    //Beep (349,200);
    //Beep (466,200);
    //Beep (587,200);
    //Beep (698,200);
    //Beep (932,600);
    //Beep (932,200);
    //Beep (932,200);
    //Beep (932,200);
    //Beep (1046,900);
}

void
ApagaSave (void)
{
    FILE *arq;
    arq=fopen("data.txt","w");
    fclose(arq);
    PLc1 = 0,PLc2 = 0,PLc3 = 0,PLc4 = 0,winPL = 0; // ZERA OS CONTADORES
    IAc1 = 0,IAc2 = 0,IAc3 = 0,IAc4 = 0,winIA = 0;
}

int
JogarNovamente (void)
{
    char s[2]={0,0};
    do{
        s[1]=0;
        printf("Deseja jogar novamente?(S/N)\n");
        scanf("%s",s);
    }while((s[0]!='n'&&s[0]!='s'&&s[0]!='N'&&s[0]!='S')||s[1]!=0);     // S� SAI DA CONDI��O QUANDO FOR DIGITADO S,s,N ou n
    switch(s[0])
    {
        case 's':
            return 1;
        case 'S':
            return 1;
        case 'n':
            return 0;
        case 'N':
            return 0;
        default:
            break;
    }
    return 0;
}
