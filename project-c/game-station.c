#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#define TAMANHO 5 // Valor referente ao tamanho do tabuleiro da batalha naval.

//Aluno : Guilherme Fonseca, Ricardo Henrique.

void cadastrarjogador(char jogador1[], char jogador2[]) { // Função para cadastrar jogador 1 e jogador 2.
    printf("Jogador 1. Infome seu nome:\n");
    scanf("%s", jogador1);
    printf("Jogador 2. Informe seu nome:\n");
    scanf("%s", jogador2);
}

void jogodavelha(char jogador1[], char jogador2[], int * jogadorp1, int * jogadorp2) { // Função para jogodavelha.
    char tabuleiro[9] = {'1','2','3','4','5','6','7','8','9'}; // Vetor de 9 posição na qual foi atribuido valores de 1 a 9.
    int jogador = 1, movimento, status = 0; // jogador controla o turno do jogo; status indica o estado do jogo.
    int opcao, jogadas = 0; // opcao para o minimenu jogodavelha, jogadas conta o número total de movimentos.

    printf("---JOGO DA VELHA---\n"); //Minimenu do jogodavelha.
    printf("1-Iniciar o Jogo\n");
    printf("2-Sair\n");
    printf("Informe a opção abaixo:\n");
    scanf("%d", & opcao);

    while (opcao > 2) {
        printf("Por favor. Informe um número de 1 a 2\n\n"); //loop enquanto opcao for maior que 2.
        printf("---JOGO DA VELHA---\n");
        printf("1-Iniciar o Jogo\n");
        printf("2-Sair\n");
        printf("Informe a opção abaixo:\n");
        scanf("%d", & opcao);
    }

    switch (opcao) { //Ler a opcao e executa os casos a partir dos switch-case.
    case 1:
        printf("Jogo Iniciando...\n\n");
        // Loop principal do jogo.
        while (status == 0) {

            printf(" %c | %c | %c \n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);

            if (jogador == 1) { // Solicita ao jogador o número da posição que deseja jogar.
                printf("Jogador %s, escolha um número: ", jogador1);
                scanf("%d", & movimento);
                movimento--; // Decrementa para ajustar ao índice do vetores (0 a 8).
            } else {
                printf("Jogador %s, escolha um número: ", jogador2);
                scanf("%d", & movimento);
                movimento--;
            }
            // Validação do movimento no tabuleiro.
            if (movimento < 0 || movimento > 8 || tabuleiro[movimento] == 'X' || tabuleiro[movimento] == 'O') {
                continue; // Ignora a entrada errada e solicita outra.
            }
            // Atualiza o tabuleiro com o símbolo do jogador atual. jogador 1 ou jogador2.
            if (jogador == 1) {
                tabuleiro[movimento] = 'X';
            } else {
                tabuleiro[movimento] = 'O';
            }
            jogadas++; // Incrementa o contador de jogadas.

            for (int i = 0; i < 3; i++) { // Verifica condições de vitória (linhas e colunas).
                if ((tabuleiro[i * 3] == tabuleiro[i * 3 + 1] && tabuleiro[i * 3 + 1] == tabuleiro[i * 3 + 2]) ||
                    (tabuleiro[i] == tabuleiro[i + 3] && tabuleiro[i + 3] == tabuleiro[i + 6])) {
                    status = 1; // Indica que há um vencedor.
                    break;
                }
            }
            // Verifica condições de vitória (diagonais).
            if ((tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8]) ||
                (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6])) {
                status = 1; // Indica que há um vencedor.
            }
            // Verifica se todas as posições estão preenchidas e o jogo terminou empatado.
            if (status == 0 && jogadas == 9) {
                status = -1;
            }
            // Alterna entre os jogadores caso o jogo continue.
            if (status == 0) {
                if (jogador == 1) {
                    jogador = 2;
                } else {
                    jogador = 1;
                }
            }
        }
        // Exibe o estado final do tabuleiro
        printf(" %c | %c | %c \n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);

        if (status == 1) { // Condição para verificar que ganhou e acrescenta 3 ponto.
            if (jogador == 1) {
                printf("Jogador %s venceu!\n", jogador1);
                * jogadorp1 += 3;
            } else {
                printf("Jogador %s venceu!\n", jogador2);
                * jogadorp2 += 3;
            }

        } else { // Condição para verificar empate e acrescenta 1 ponto.
            printf("O jogo terminou em empate!\n");
            * jogadorp1 += 1;
            * jogadorp2 += 1;
        }
        break;

    default: // Se nao for nenhum dos casos o jogo fechar.
        printf("Saindo...\n\n");
    }
}

void jogodaforca(char jogador1[], char jogador2[], int * jogadorp1, int * jogadorp2) { //Função do jogodaforca.
    int opcao, tentativas, acertou; //Variaveis para controle do codigo.
    char palavra_secreta[20] = ""; // Palavra secreta a ser adivinhada.
    char palavra[20]; // Palavra visível para o jogador.
    char chute; // Letra chutada pelo jogador.
    int jogadorforca; // Indica qual jogador está jogando.

    do {
        printf("----JOGO DA FORCA---\n"); //Minimenu do jogodaforca.
        printf("1-Iniciar Jogo\n");
        printf("2-Configurar Palavra e Tentativas\n");
        printf("3-Sair\n");
        printf("Informe a Abaixo:\n");
        scanf("%d", & opcao);

        switch (opcao) { //Ler a opcao e executa os casos a partir dos switch-case.
        case 2: // Configura a palavra secreta e o número de tentativas.
            printf("Digite a Palavra:\n");
            scanf("%s", palavra_secreta);
            printf("Digite o numero maximo de tentativas:\n"); // Ler o nuemros de tentativas.
            scanf("%d", & tentativas);
            printf("Informe qual jogador vai jogar:\n"); // Escolhe o jogador que irá jogar.
            printf("1- Jogador 1 -- %s\n", jogador1);
            printf("2- Jogador 2 -- %s\n", jogador2);
            printf("Informe abaixo:\n");
            scanf("%d", & jogadorforca);
            printf("Palavra e numero de tentativas configurados com sucesso!\n\n");
            break;

        case 1: //Iniciar jogo.
            if (strlen(palavra_secreta) == 0 || tentativas == 0) { // Verifica se a palavra ou as tentativas foram configuradas
                printf("Por favor, configure a palavra e o número de tentativas antes de iniciar o jogo!\n\n");
                break;
            }
            for (int i = 0; i < strlen(palavra_secreta); i++) {
                palavra[i] = '_'; // Inicializa a palavra visível com barras _.
            }
            palavra[strlen(palavra_secreta)] = '\0'; // Adiciona o caractere nulo ao final da string para evitar erros.
            while (tentativas > 0 && strcmp(palavra, palavra_secreta) != 0) { // Loop principal do jogo (enquanto houver tentativas ou a palavra não foi adivinhada).
                printf("Palavra: %s\n", palavra);
                printf("Digite uma letra: ");
                scanf(" %c", & chute); //ler o chute do jogador.

                acertou = 0; //variável usada para saber o progresso do jogador ao tentar adivinhar as letras da palavra secreta.
                for (int i = 0; i < strlen(palavra_secreta); i++) {
                    if (palavra_secreta[i] == chute) {
                        palavra[i] = chute; // Atualiza a palavra visível com a letra correta.
                        acertou = 1; // Marca que o jogador acertou.
                    }
                }
                if (!acertou) {
                    tentativas--; // Diminui o numero de tentativas caso jogador erre.
                    printf("Errou! Tentativas restantes: %d\n", tentativas);
                }
            }
            //verificar o resultado do jogo e verificar qual jogador ganhou. E acrescenta 3 pontos ao ganhador.
            if (strcmp(palavra, palavra_secreta) == 0) {
                printf("Parabens Voce acertou a palavra: %s\n\n", palavra_secreta);
                if (jogadorforca == 1) {
                    * jogadorp1 += 3;
                    printf("Jogador %s acertou!\n", jogador1);
                } else {
                    * jogadorp2 += 3;
                    printf("Jogador %s acertou!\n", jogador2);
                }
            } else { //Codição que  Jogador não acertou a palavra.
                printf("Voce perdeu! A palavra era: %s\n\n", palavra_secreta);
            }

        }
    }
    while (opcao != 3); // Fechar do jogo quando a opção for 3.
}

void batalhanaval(char jogador1[], char jogador2[], int * jogadorp1, int * jogadorp2) { //Função para batalhanaval.
    char tabuleiro1[TAMANHO][TAMANHO], tabuleiro2[TAMANHO][TAMANHO]; //Matriz do tabuleiro 1 e tabuleiro2.
    int x, y; //Leitura dos valores x e y para a matriz.
    int opcao; //Leitura dos valores inseridos minimenu do jogo.

    printf("----BATALHA NAVAL----\n"); //Minimenu do jogo batalha naval
    printf("1- Iniciar o Jogo\n");
    printf("2- Sair\n");
    printf("Informe a abaixo:\n");
    scanf("%d", & opcao);
    printf("\n");

    while (opcao > 2) {
        printf("Por favor. Informe numero de 1 a 2:\n\n"); //Loop enquanto opcao for maior que 2.
        printf("----BATALHA NAVAL----\n");
        printf("1- Iniciar o Jogo\n");
        printf("2- Sair\n");
        printf("Informe a abaixo:\n");
        scanf("%d", & opcao);
        printf("\n");
    }

    switch (opcao) { //Ler a opcao e executa os casos a partir dos switch-case.
    case 1:
        // Inicializa os tabuleiros com água ('~').
        for (int linha = 0; linha < TAMANHO; linha++) {
            for (int coluna = 0; coluna < TAMANHO; coluna++) {
                tabuleiro1[linha][coluna] = '~';
                tabuleiro2[linha][coluna] = '~';
            }
        }

        //Essa parte e responsavel por Jogador 1 posiciona o navio.
        printf("Jogador 1 - %s, posicione seu navio:\n", jogador1);
        do {
            printf("Digite as coordenadas para posicionar o navio (x y): ");
            scanf("%d %d", & x, & y); //Ler os valores para posicionar o navio.

            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && tabuleiro1[x][y] == '~') {
                tabuleiro1[x][y] = 'N'; // Coloca o navio na posição correta no tabuleiro.
                printf("Navio posicionado em %d, %d.\n", x, y);
                break;
            } else {
                printf("Posição inválida ou já ocupada. Tente novamente.\n");
            }
        } while (1);

        //Essa parte e responsavel por Jogador 2 posiciona o navio.
        printf("Jogador 2 - %s, posicione seu navio:\n", jogador2);
        do {
            printf("Digite as coordenadas para posicionar o navio (x y): ");
            scanf("%d %d", & x, & y); //Ler os valores para posicionar o navio.

            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && tabuleiro2[x][y] == '~') {
                tabuleiro2[x][y] = 'N'; // Coloca o navio na posição correta no tabuleiro.
                printf("Navio posicionado em %d, %d.\n", x, y);
                break;
            } else {
                printf("Posição inválida ou já ocupada. Tente novamente.\n");
            }
        } while (1);

        int turno = 1; // Jogador 1 começa jogando.
        int acertos1 = 0, acertos2 = 0;

        // Começa o jogo
        while (acertos1 < 1 && acertos2 < 1) {
            if (turno == 1) {
                printf("\nTurno do Jogador 1 / %s \n", jogador1);
                printf("Tabuleiro do Jogador 2 / %s :\n", jogador2);
                printf("  ");
                for (int i = 0; i < TAMANHO; i++) {
                    printf("%d ", i); // Exibe as colunas do tabuleiro.
                }
                printf("\n");

                for (int i = 0; i < TAMANHO; i++) {
                    printf("%d ", i); // Exibe as linhas do tabuleiro.
                    for (int j = 0; j < TAMANHO; j++) {
                        if (tabuleiro2[i][j] == 'N') {
                            printf("~ "); // Exibe ~ no lugar de 'N' para esconder navios
                        } else {
                            printf("%c ", tabuleiro2[i][j]); // Exibe o conteúdo do tabuleiro
                        }
                    }
                    printf("\n");
                }

                printf("Digite as coordenadas para atacar (x y): ");
                scanf("%d %d", & x, & y);

                if (tabuleiro2[x][y] == 'N') {
                    tabuleiro2[x][y] = 'X'; // Marca um navio atingido
                    printf("Acertou!\n");
                    acertos1++;
                } else {
                    tabuleiro2[x][y] = 'O'; // Marca a água
                    printf("Água!\n");
                }
            } else {
                printf("\nTurno do Jogador 2 / %s \n", jogador2);
                printf("Tabuleiro do Jogador 1 /%s :\n", jogador1);
                printf("  ");
                for (int i = 0; i < TAMANHO; i++) {
                    printf("%d ", i); // Exibe as colunas
                }
                printf("\n");

                for (int i = 0; i < TAMANHO; i++) {
                    printf("%d ", i); // Exibe as linhas
                    for (int j = 0; j < TAMANHO; j++) {
                        if (tabuleiro1[i][j] == 'N') {
                            printf("~ "); // Exibe ~ no lugar de 'N' para esconder navios
                        } else {
                            printf("%c ", tabuleiro1[i][j]); // Exibe o conteúdo do tabuleiro
                        }
                    }
                    printf("\n");
                }

                printf("Digite as coordenadas para atacar (x y): ");
                scanf("%d %d", & x, & y);

                if (tabuleiro1[x][y] == 'N') {
                    tabuleiro1[x][y] = 'X'; // Marca um navio atingido
                    printf("Acertou!\n");
                    acertos2++;
                } else {
                    tabuleiro1[x][y] = 'O'; // Marca a água
                    printf("Água!\n");
                }
            }
            // Alterna entre os jogadores caso o jogo continue.
            if (turno == 1) {
                turno = 2;
            } else {
                turno = 1;
            }
        }

        if (acertos1 == 1) { // Condição que analisa se jogador 1 acertou.
            printf("\nJogador 1 / %s venceu!\n", jogador1);
            * jogadorp1 += 3; // Acrescenta o valor 3 em caso de vitoria do jogador 1.
        } else { // Senao executa o jagador 2 ganhou.
            printf("\nJogador 2 / %s venceu!\n", jogador2);
            * jogadorp2 += 3; // Acrescenta o valor 3 em caso de vitoria do jogador 2.
        }
        break;

    default: // Se nao for nenhum dos casos o jogo fechar.
        printf("Saindo...\n\n");

    }
}

void pontucaojogadores(char jogador1[], char jogador2[], int jogadorp1, int jogadorp2) { // Função para exibir a pontuação dos jogador 1 e jogador 2.
    printf("----PONTUAÇÃO DOS JOGADORES----\n");
    printf("Rank:\n"); //Exibir a pontuação geral dos jogadores 1 e jogadores 2.
    printf("Jogador 1 | %s | PONTUAÇÃO = %d\n", jogador1, jogadorp1);
    printf("Jogador 2 | %s | PONTUAÇÃO = %d\n", jogador2, jogadorp2);
    printf("----------------------------------\n");
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil"); // Bibloteca para acentuação em c.
    int opcao; // Leitura do valor inseridos no menu principal.
    char jogador1[50] = "", jogador2[50] = ""; // Variaveis para ler nome dos jogador 1 e jogador 2.
    int jogadorp1 = 0, jogadorp2 = 0; // Variaveis para Acrescenta os valores de pontuação dos jogador 1 e jogador 2.

    do {
        printf("\n"); // Menu Principal. 
        printf("----GAME STATION----\n");
        printf("1 - Cadastrar Jogadores\n");
        printf("-------------------------------\n");
        printf("2 - Jogo da Velha -- 2 Player\n");
        printf("3 - Jogo da Forca -- 1 Player\n");
        printf("4 - Batalha Naval -- 2 Player\n");
        printf("5 - Pontuação - Placa \n");
        printf("-------------------------------\n");
        printf("6 - Sair\n");
        printf("Informe a opção abaixo:\n");
        scanf("%d", & opcao);
        printf("\n");

        if (opcao < 1 || opcao > 6) {
            printf("Opção inválida. Tente novamente.\n"); // Condição para numeros maiores que 6 e menos que 1 em caso de respota no menu principal.
            continue;
        }

        switch (opcao) { // Verificar o valor informado na variavel opção. E executa os casos.
        case 1:
            cadastrarjogador(jogador1, jogador2);
            printf("Jogadores cadastrados com sucesso!\n"); //Chamar a Função cadastrarjogador.
            printf("Jogador 1: %s\n", jogador1);
            printf("Jogador 2: %s\n", jogador2);
            break;
        case 2:
            if (strlen(jogador1) == 0 || strlen(jogador2) == 0) { // Condição que verificar comprimeiro da palavra se for = 0. Indica que o usuario nao cadastrou nenhum nome de jogador. 
                printf("Você precisa cadastrar os jogadores antes de jogar!\n");
            } else {
                jogodavelha(jogador1, jogador2, & jogadorp1, & jogadorp2); // Depois de verificar chamar a função jogodavelha.
            }
            break;
        case 3:
            if (strlen(jogador1) == 0 || strlen(jogador2) == 0) { // Condição que verificar comprimeiro da palavra se for = 0. Indica que o usuario nao cadastrou nenhum nome de jogador. 
                printf("Você precisa cadastrar os jogadores antes de jogar!\n");
            } else {
                jogodaforca(jogador1, jogador2, & jogadorp1, & jogadorp2); // Depois de verificar chamar a função jogodaforca.
            }
            break;
        case 4:
            if (strlen(jogador1) == 0 || strlen(jogador2) == 0) { // Condição que verificar comprimeiro da palavra se for = 0. Indica que o usuario nao cadastrou nenhum nome de jogador.
                printf("Você precisa cadastrar os jogadores antes de jogar!\n");
            } else {
                batalhanaval(jogador1, jogador2, & jogadorp1, & jogadorp2); // Depois de verificar chamar a função batalhanaval.
            }
            break;
        case 5:
            if (strlen(jogador1) == 0 || strlen(jogador2) == 0) { // Condição que verificar comprimeiro da palavra se for = 0. Indica que o usuario nao cadastrou nenhum nome de jogador.
                printf("Você precisa cadastrar os jogadores antes para ver pontuação!\n");
            } else {
                pontucaojogadores(jogador1, jogador2, jogadorp1, jogadorp2); // Depois de verificar chamar a função pontucaojogadores.
            }
            break;
        default:
            printf("Saindo...\n"); // Caso nenhum das opção for executada.
        }
    } while (opcao != 6); // Fechar loop do-while ao informe valor 6.

    return 0;
}