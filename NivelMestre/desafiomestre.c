#include <stdlib.h>
#include <stdio.h>

#define LINHAS_TABULEIRO 10 // Dados para criação do tabuleiro
#define COLUNAS_TABULEIRO 10
#define ESPACO "                                                                     "

#define AGUA '0'
#define PARTE_NAVIO '3'
#define ATINGIDO '5'

#define LINHAS_HABILIDADE 3 // Dados para criação das habilidades
#define COLUNAS_HABILIDADE 5

#define TAMANHO_NAVIOS 3 // Dados para criação dos navios
#define NAVIOS 4

char tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];

// Habilidades
int cone[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1}};

int cruz[3][5] = {
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0}};

int octa[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}};

// navios guardados em linha na ma
char navios[NAVIOS][TAMANHO_NAVIOS];

int linha_navio1 = 1;
int coluna_navio1 = 5;

int linha_navio2 = 0;
int coluna_navio2 = 4;

int linha_navio3 = 2;
int coluna_navio3 = 3;

int linha_navio4 = 5;
int coluna_navio4 = 5;

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
    printf(ESPACO);
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
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para criar qt navios
void criar_navios()
{
    for (int i = 0; i < NAVIOS; i++)
    {
        for (int j = 0; j < TAMANHO_NAVIOS; j++)
        {
            navios[i][j] = PARTE_NAVIO;
        }
    }
}

// Função responsável pela impressão do tabuleiro
void imprimir_tabuleiro()
{
    // system("cls");
    printf("\n");
    //  Cria a numeração das colunas
    printf(ESPACO);
    printf("     |");
    for (int j = 0; j < COLUNAS_TABULEIRO; j++)
    {
        printf(" %d |", j);
    }

    linhas();

    for (int i = 0; i < LINHAS_TABULEIRO; i++)
    {
        printf("\n");
        printf(ESPACO);
        printf("| %d  |", i); // Numeração da linha

        for (int j = 0; j < COLUNAS_TABULEIRO; j++)
        {
            printf(" %c |", tabuleiro[i][j]);
        }
    }
    linhas();
}

// Função para colocar navio, passando como argumento a casa mais a esquerda e mais em cima
// H = HORIZONTAL
// V = VERTICAL
// D = DIAGONAL
// I = DIAGONAL INVERTIDA
void colocar_navio(char navio[], int tamanho, int lin, int col, char direcao)
{
    int dx = 0, dy = 0; // Variações na linha e na coluna respectivamente

    switch (direcao)
    {
    case 'H':
    case 'h':
        dx = 1;
        dy = 0;
        break;

    case 'V':
    case 'v':
        dx = 0;
        dy = 1;
        break;

    case 'D':
    case 'd':
        dx = 1;
        dy = 1;
        break;

    case 'I':
    case 'i':
        dx = -1;
        dy = 1;
        break;
    }

    for (int i = 0; i < tamanho; i++)
    {
        int nova_linha = lin + i * dy;
        int nova_coluna = col + i * dx;

        // Verifica se o navio cabe na horizontal e na vertical no tabuleiro
        if (nova_linha >= LINHAS_TABULEIRO || nova_coluna >= COLUNAS_TABULEIRO || nova_linha < 0 || nova_coluna < 0) // Verifica se a posição está dentro do tabuleiro
        {
            printf("\nO navio não pode ser colocado nessa posição\n\nFora dos Limites\n");
            return;
        }

        // Verifica se o espaço está livre
        if (tabuleiro[nova_linha][nova_coluna] != AGUA)
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

void habilidade_cone(int y, int x)
{
    for (int i = 0; i < LINHAS_HABILIDADE; i++)
    {
        for (int j = 0; j < COLUNAS_HABILIDADE; j++)
        {
            if (tabuleiro[i + y][j + x - 2] != 0 && cone[i][j] == 1) // -2 para alinhar o topo do cone no ponto de origem
            {
                tabuleiro[i + y][j + x - 2] = ATINGIDO;
            }
        }
    }
}

int main()
{
    criar_navios(3);
    criar_tabuleiro();

    colocar_navio(navios[0], TAMANHO_NAVIOS, linha_navio1, coluna_navio1, 'h');
    colocar_navio(navios[1], TAMANHO_NAVIOS, linha_navio2, coluna_navio2, 'H');

    colocar_navio(navios[2], TAMANHO_NAVIOS, linha_navio3, coluna_navio3, 'D');
    colocar_navio(navios[3], TAMANHO_NAVIOS, linha_navio4, coluna_navio4, 'I');
    // habilidade_cone(1, 5);

    imprimir_tabuleiro();
}
