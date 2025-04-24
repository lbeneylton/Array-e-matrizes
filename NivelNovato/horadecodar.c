#include <stdlib.h>
#include <stdio.h>

int main(){
    int index;
    
    char *alunos[3][3] = {
        {"Aluno 0", "Pt: 10", "Mt: 90"},
        {"Aluno 1", "Pt: 20", "Mt: 80"},
        {"Aluno 2", "Pt: 30", "Mt: 70"}
    };

    printf("\n\nDigite o nome do aluno que você quer ver as notas:\n\n");
    printf("Para o aluno 0, digite 0\n");
    printf("Para o aluno 1, digite 1\n");
    printf("Para o aluno 2, digite 2\n");
    scanf(" %d", &index);

    printf("As notas do %s são: %s  , %s.\n", alunos[index][0], alunos[index][1], alunos[index][2]);

}