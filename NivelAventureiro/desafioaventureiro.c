#include <stdlib.h>
#include <stdio.h>

#define LINHAS_TABULEIRO 10
#define COLUNAS_TABULEIRO 10
#define ESPACO "                     "
#define NAVIOS 4
#define TAMANHO_NAVIOS 3

char tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];

char navio1[TAMANHO_NAVIOS] = {'1', '1', '1'};
char navio2[TAMANHO_NAVIOS] = {'2', '2', '2'};

char navio3[TAMANHO_NAVIOS] = {'3', '3', '3'};
char navio4[TAMANHO_NAVIOS] = {'4', '4', '4'};

// char navios[NAVIOS][TAMANHO_NAVIOS];

int linha_navio1 = 1;
int coluna_navio1 = 5;

int linha_navio2 = 0;
int coluna_navio2 = 4;

int linha_navio3 = 2;
int coluna_navio3 = 3;

int linha_navio4 = 5;
int coluna_navio4 = 8;

void linhas()
// distancia = ((colunas+1)*3) + (colunas + 1 ) + (1)
//( colunas do jogo * 3)
// quantidades de "|"
// espaço  da coluna de numeração de linha

// d = 3(c + 1) + c + 3
// d = 3c + 3 + c + 3
// d = 4c + 6
{
    printf("\n");
    for (int j = 0; j < (4 * COLUNAS_TABULEIRO + 6); j++)
    {
        printf("-");
    }
}

void criar_tabuleiro()
{
    for (int i = 0; i < LINHAS_TABULEIRO; i++)
    {
        for (int j = 0; j < COLUNAS_TABULEIRO; j++)
        {
            tabuleiro[i][j] = '0';
        }
    }
}

// Função responsável pela impressão do tabuleiro
void imprimir_tabuleiro()
{
    printf("\n");
    //  Cria a numeração das colunas
    printf("     |");
    for (int j = 0; j < COLUNAS_TABULEIRO; j++)
    {
        printf(" %d |", j);
    }

    linhas();

    for (int i = 0; i < LINHAS_TABULEIRO; i++)
    {
        printf("\n");
        printf("| %d  |", i); // Numeração da linha

        for (int j = 0; j < COLUNAS_TABULEIRO; j++)
        {
            printf(" %c |", tabuleiro[i][j]);
        }
    }
    linhas();
}
// Função para colocar navio passando como argumento a casa mais a esquerda e mais em cima
void colocar_navio(char navio[], int tamanho, int lin, int col, char direcao)
{
    int dx, dy;

    switch (direcao)
    {
    case 'H':
        dx = 1;
        dy = 0;
        break;

    case 'V':
        dx = 0;
        dy = 1;
        break;
    }

    for (int i = 0; i < tamanho; i++)
    {
        int nova_linha = lin + i * dy;
        int nova_coluna = col + i * dx;

        // Verifica se o navio cabe na horizontal e na vertical no tabuleiro
        if (nova_linha >= LINHAS_TABULEIRO || nova_coluna >= COLUNAS_TABULEIRO)
        {
            printf("\nO navio não pode ser colocado nessa orientação (horizontal) nessa posição\n\nFora dos Limites\n");
            return;
        }

        // Verifica se o espaço está livre
        if (tabuleiro[nova_linha][nova_coluna] != '0')
        {
            printf("\nEspaço ocupado por outro navio\n");
            return;
        }
    }

    // Coloca o navio no tabuleiro
    for (int i = 0; i < tamanho; i++)
    {
        int nova_linha = lin + i * dy;
        int nova_coluna = col + i * dx;
        tabuleiro[nova_linha][nova_coluna] = navio[i];
    }
}

// Função para colocar navio na diagonal
void colocar_navio_DIAGONAL(char navio[], int tamanho, int lin, int col, int direcao) // direção será 1 para crescente e - 1 para decrescente
                                                                                      //   crescente              decrescente
                                                                                      //  #                                   #
                                                                                      //       #                        #
                                                                                      //             #            #
{
    // Verifica se o navio cabe na diagonal do tabuleiro
    if (lin + tamanho > LINHAS_TABULEIRO || col + tamanho > COLUNAS_TABULEIRO || col - tamanho < 0)
    {
        printf("\n O navio não pode ser colocado nessa orientação nesssa posição\nFora dos Limites\n");
        return;
    }

    // Verifica se o espaço está livre
    for (int i = 0; i < tamanho; i++)
    {
        if (tabuleiro[lin + i][col + i * direcao] != '0')
        {
            printf("\nEspaço ocupado por outro navio\n");
            return;
        }
    }

    for (int i = 0; i < tamanho; i++)
    {
        tabuleiro[lin + i][col + i * direcao] = navio[i];
    }
}

int main()
{
    criar_tabuleiro();

    colocar_navio_HORIZONTAL(navio1, TAMANHO_NAVIOS, linha_navio1, coluna_navio1);
    colocar_navio_HORIZONTAL(navio2, TAMANHO_NAVIOS, linha_navio2, coluna_navio2);

    colocar_navio_DIAGONAL(navio3, TAMANHO_NAVIOS, linha_navio3, coluna_navio3, 1);
    colocar_navio_DIAGONAL(navio4, TAMANHO_NAVIOS, linha_navio4, coluna_navio4, -1);

    imprimir_tabuleiro();
}
