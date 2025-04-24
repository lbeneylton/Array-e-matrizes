#include <stdio.h>
#include <stdlib.h>

int matriz1[3][3] = {
    {2, 4, -5},
    {3, -5, 0},
    {7, 5, -6}

};

int matriz2[3][3] = {
    {4, 8, 6},
    {-4, -6, 9},
    {0, 5, -5}

};

int result[3][3];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            printf(" %d", result[i][j]);
        }
        printf(" |\n");
    }
}