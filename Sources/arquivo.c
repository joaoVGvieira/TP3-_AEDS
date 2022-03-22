#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "../Libs/arquivos.h"

void escreve_arquivo_tempo(int vet[], clock_t tempo_execu, int tamanho, int comp, int mov, char nome[]){
    int i;
    char tempo[20];
    FILE *saida = fopen(nome, "w");
    if(saida) {
        sprintf(tempo, "%f ", ((float)tempo_execu)/(float)CLOCKS_PER_SEC);
        fputs(tempo, saida);
        fprintf(saida,"segundos\n");
        fprintf(saida, "Comp = %d mov = %d ",comp,mov);
        fclose(saida);
        printf("\nARQUIVO DE SAIDA FOI ATUALIZADO!!!\n");
    } else
        printf("\nERRO ao abrir arquivo de saida!\n");
}
