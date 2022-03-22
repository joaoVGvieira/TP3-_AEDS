#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "../Libs/arquivos.h"
// Vai ler o arquivo de teste
/*void ler(char nome[1000]){
    FILE *file = fopen(nome,"r");
    if(file==NULL){
        printf("Erro para abrir o arquivo de leitura!!!!");
        exit(1);
    }
     //Número numeros para sem lidos
    int NL;
    // Tamanho do vetor para cursores
    int N;
    if (file)
    {
        fscanf(file,"%d\n",&NL);
        fscanf(file,"%d\n",&N);
    }
    for (int i = 0; i < NL; i++)
    {
        fscanf(file,"%d\n",N);
    }
    fclose(file);
}*/
// vai escrever o arquivo de saida
void escreve_arquivo_tempo(int vet[], clock_t tempo_execu, int tamanho, int comp, int mov, char nome_saida[]){
    int i;
    char nome[100];
    //printf("\nDigite o nome do arquivo de saida:");
    //scanf(" %[^\n]s ",nome);
    char tempo[20];
    FILE *saida = fopen(nome_saida, "w");
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
