#include <stdlib.h>
#include <stdio.h>

// Dados para criação do tabuleiro
#define LINHAS_TABULEIRO 10
#define COLUNAS_TABULEIRO 10

// Smbolos utilizados para representação no tabuleiro
#define AGUA '-'
#define PARTE_NAVIO '3'
#define ATINGIDO 'X'
#define VAZIO '~'

// Dados para criação das matrizes das habilidades
#define LINHAS_HABILIDADE 3
#define COLUNAS_HABILIDADE 5

// Dados para criação dos navios
#define TAMANHO_NAVIOS 3
#define NAVIOS 4

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

// Inicialização das variaveis globais para o tabuleiro e os navios e suas posições
char tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];
char navios[NAVIOS][TAMANHO_NAVIOS];
int posicao_navios[NAVIOS][2] = {
    {1, 5},
    {0, 4},
    {2, 3},
    {5, 5}};
;

// Habilidades
int posicao_central_habilidades[3][2] = {
    {0, 2}, //  CONE
    {1, 2}, // CRUZ
    {1, 2}  // OCTA
};

int habilidades[3] = {
    cone, cruz, octa};

//
// FUNÇÕES DE DESENHO
//
void espaco()
{
    for (int i = 0; i < 70; i++)
    {
        printf(" ");
    }
}

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
    espaco();
    for (int j = 0; j < (4 * COLUNAS_TABULEIRO + 6); j++)
    {
        printf("-");
    }
}

// Função responsável pela impressão do tabuleiro, utiliza função linhas() e espaco()
void imprimir_tabuleiro()
{

    printf("\n");
    //  Cria a numeração das colunas
    espaco();
    printf("     |");
    for (int j = 0; j < COLUNAS_TABULEIRO; j++)
    {
        printf(" %d |", j);
    }

    linhas();

    for (int i = 0; i < LINHAS_TABULEIRO; i++)
    {
        printf("\n");
        espaco();
        printf("| %d  |", i); // Numeração da linha

        for (int j = 0; j < COLUNAS_TABULEIRO; j++)
        {
            printf(" %c |", tabuleiro[i][j]);
        }
    }
    linhas();
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

// Função para colocar navio, passando como argumento a casa mais a esquerda e mais em cima
// H = HORIZONTAL
// V = VERTICAL
// D = DIAGONAL
// I = DIAGONAL INVERTIDA
void colocar_navio(char navio[], int pos[], char direcao)
{
    int lin = pos[0];
    int col = pos[1];
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

    for (int i = 0; i < TAMANHO_NAVIOS; i++)
    {
        int nova_linha = lin + i * dy;
        int nova_coluna = col + i * dx;

        // Verifica se a posição do navio está dentro dos limites e se o espaço está livre
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
    for (int i = 0; i < TAMANHO_NAVIOS; i++)
    {
        int nova_linha = lin + i * dy;
        int nova_coluna = col + i * dx;
        tabuleiro[nova_linha][nova_coluna] = navio[i];
    }
}

void habilidade_cone(int x, int y) // coluna, linha
{
    for (int i = 0; i < LINHAS_HABILIDADE; i++)
    {
        for (int j = 0; j < COLUNAS_HABILIDADE; j++) // loops para iterar sobre a matriz de habilidade
        {
            int lin = y + i;     // Valores para relacionar matriz habilidade a matriz tabuleiro  (x,y) valores onde  inicia ataque   (lin,col) matriz do tabuleiro
            int col = x + j - 2; // -2 para alinhar o topo do cone no ponto de origem             (i,j) matriz da habilidade

            if (lin >= 0 && lin < LINHAS_TABULEIRO && // Verifica se a posição atacada está dentro do tabuleiro
                col >= 0 && col < COLUNAS_TABULEIRO)
            {
                if (cone[i][j])
                {
                    tabuleiro[lin][col] = tabuleiro[lin][col] == PARTE_NAVIO ? ATINGIDO : VAZIO;
                }
            }
        }
    }
}

void habilidade_octa(int x, int y) // coluna, linha

{
    for (int i = 0; i < LINHAS_HABILIDADE; i++)
    {
        for (int j = 0; j < COLUNAS_HABILIDADE; j++)
        {
            int lin = y + i - 1;
            int col = x + j - 2;

            if (lin >= 0 && lin < LINHAS_TABULEIRO &&
                col >= 0 && col < COLUNAS_TABULEIRO)
            {
                if (octa[i][j])
                {
                    tabuleiro[lin][col] = tabuleiro[lin][col] == PARTE_NAVIO ? ATINGIDO : VAZIO;
                }
            }
        }
    }
}

void habilidade_cruz(int x, int y) // coluna, linha
{
    for (int i = 0; i < LINHAS_HABILIDADE; i++)
    {
        for (int j = 0; j < COLUNAS_HABILIDADE; j++)
        {
            int lin = y + i - 1;
            int col = x + j - 2;

            if (lin >= 0 && lin < LINHAS_TABULEIRO &&
                col >= 0 && col < COLUNAS_TABULEIRO)
            {
                if (cruz[i][j])
                {
                    tabuleiro[lin][col] = tabuleiro[lin][col] == PARTE_NAVIO ? ATINGIDO : VAZIO;
                }
            }
        }
    }
}

int main()
{
    criar_navios();
    criar_tabuleiro();

    colocar_navio(navios[0], posicao_navios[0], 'h');
    colocar_navio(navios[1], posicao_navios[1], 'H');

    colocar_navio(navios[2], posicao_navios[2], 'D');
    colocar_navio(navios[3], posicao_navios[3], 'I');

    habilidade_octa(5, 1);

    imprimir_tabuleiro();
}
