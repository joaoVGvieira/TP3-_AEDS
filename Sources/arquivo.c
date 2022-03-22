#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "../Libs/arquivos.h"
void escreve_arquivo_tempo(int vet[], clock_t tempo_execu, int tamanho, int comp, int mov, char nome_saida[],int cont){
    int i;
    char nome[100];
    char tempo[20];
    char meses[7][20] = {"Rercusivo","inteligente","Insercao10","Insercao100","Iterativo","Mediana3","Mediana5"};
    FILE *saida = fopen(nome_saida, "a");
    if (cont==0)
    {
        fprintf(saida,"N=%d\n",tamanho);
    }
    if(saida) {
        fprintf(saida,"%s: ",meses[cont]);
        sprintf(tempo, "Tempo = %f ", ((float)tempo_execu)/(float)CLOCKS_PER_SEC);
        fputs(tempo, saida);
        fprintf(saida,"segundos,");
        fprintf(saida, " Comparaçoes = %d, Movimentaçoes = %d\n",comp,mov);

        fclose(saida);
    } else
        printf("\nERRO ao abrir arquivo de saida!\n");
    
        
}
