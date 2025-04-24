#include <stdlib.h>
#include <stdio.h>

#define LINHAS_TABULEIRO 10
#define COLUNAS_TABULEIRO 10

char tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO] = {};

char navio1[3] = {'1', '1', '1'};
char navio2[3] = {'2', '2', '2'};

int linha_navio1 = 1;
int coluna_navio1 = 5;
int tamanho_navio1 = 3;

int linha_navio2 = 1;
int coluna_navio2 = 4;
int tamanho_navio2 = 3;

// void criar_navios(){
//     printf("Digite a linha que você deseja inserir o navio: ")
//     scanf(" %d", &linha_navio1)
//     printf("Digite a coluna que você deseja inserir o navio: ")
//     scanf(" %d", &coluna_navio1)

//     printf("Digite a linha que você deseja inserir o navio: ")
//     scanf(" %d", &linha_navio2)
//     printf("Digite a coluna que você deseja inserir o navio: ")
//     scanf(" %d", &coluna_navio2)

// }

// Função que cria o tabuleiro e insere 0 em todas as posições
// para representar a água do oceano

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
    printf("\n\n------------------------------\n");
    for (int i = 0; i < LINHAS_TABULEIRO; i++)
    {
        for (int j = 0; j < COLUNAS_TABULEIRO; j++)
        {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------\n\n");
}

// Função para colocar navio na horizontal passando a casa mais a esquerda
void colocar_navio_H(char navio[], int tamanho, int lin, int col)
{
    // Verifica se o navio cabe horizontalmente no tabuleiro
    if (col + tamanho > COLUNAS_TABULEIRO)
    {
        printf("\nO navio não pode ser colocado nessa orientação (horizontal) nessa posição\n");
        return;
    }

    // Verifica se o espaço está livre
    for (int i = 0; i < tamanho; i++)
    {
        if (tabuleiro[lin][col + i] != '0')
        {
            printf("\nEspaço ocupado por outro navio\n");
            return;
        }
    }

    // Coloca o navio no tabuleiro
    for (int i = 0; i < tamanho; i++)
    {
        tabuleiro[lin][col + i] = navio[i];
    }
}

// Função para colocar navio na horizontal passando a casa mais em cima
void colocar_navio_V(char navio[], int tamanho, int lin, int col)
{
    // Verifica se o navio cabe verticalmente no tabuleiro
    if (lin + tamanho > LINHAS_TABULEIRO)
    {
        printf("\nO navio não pode ser colocado nessa orientação (vertical) nessa posição\n");
        return;
    }

    // Verifica se o espaço está livre
    for (int i = 0; i < tamanho; i++)
    {
        if (tabuleiro[lin + i][col] != '0')
        {
            printf("\nEspaço ocupado por outro navio\n");
            return;
        }
    }

    // Coloca o navio no tabuleiro
    for (int i = 0; i < tamanho; i++)
    {
        tabuleiro[lin + i][col] = navio[i];
    }
}

int main()
{
    criar_tabuleiro();

    colocar_navio_H(navio1, tamanho_navio1, linha_navio1, coluna_navio1);
    colocar_navio_V(navio2, tamanho_navio2, linha_navio2, coluna_navio2);

    imprimir_tabuleiro();
}
