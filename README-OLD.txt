Foram utilizados:
	Arranjos, Registros, Enums e Typedef, Passagem Referência, Leitura/Escrita Arquivos, Estruturas e comandos de controle básico;
	Modularização, Padronização, Documentação;
	Modelagem dos Dados, Impressão de Menu Inicial, Novo Jogo, Inicialização do tabuleiro Jogador e Computador, Impressão do Tabuleiro Inicial;
	Leitura da jogada, Validação da Jogada, Verificação da condição de vitória do jogo, Salvar partida, Alternância de turno e atualização do tabuleiro, Continuar, Sair;
	IA do computador Inteligente, Integração com API.

Não foi utilizado:
	IA Inteligente +;
	Interface Gráfica, Jogo em rede, Alocação Dinâmica do Tabuleiro, Recursão nas operações de alocação de navios;
	Créditos.

O que seria feito diferentemente:
	Usaria um typedef struct com todos os dados da IA e do Jogador(Coordenadas,contadores,Matrizes,etc).

Como compilar o projeto:
	Foram utilizadas as bibliotecas time.h(gerar valores aleartorios), windows.h e dos.h(beeps);
	Testado no codeblocks(windows).

Dupla:
	Giordano Rodrigues(Lógica):
		Lógica da IA;
		Loops dos turnos/jogo;
		Gerar navios automaticamente/manualmente;
		Modularização.
		
		
	Gabriel Barbosa(Gráfica/Interface):
		Salvar/Carregar;
		Gráficos(tabuleiros impressos);
		Sons/Pisca tela;
		Menu de opções.