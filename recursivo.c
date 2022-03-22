#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "Libs/arquivos.h"
void escreve_arquivo_tempo(int vet[], clock_t tempo_execu, int tamanho, int comp, int mov, char *nome_saida){
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


int comp = 0, mov = 0;
//chama o quick normal para achar o pivo e ordernar o vetor
void Quick(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   do{
      while (vetor[i] < pivo){
         comp++;
         i+= 1;
      } 
      while (vetor[j] > pivo){
          comp++;
          j-= 1;
      } 
      if(i <= j){
         comp++; 
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         mov++;
         i+= 1;
         j-= 1;
      }
   }while(j > i);
   //chama recursivamente o quick
   if(inicio < j){
       Quick(vetor, inicio, j);
       comp++;
   } 
   if(i < fim) {
       Quick(vetor, i, fim);
       comp++;  
   }

}

int main(int argc, char *argv[]){
    clock_t tempo_execu;
   
    printf("Numeros argumentos: %d\n", argc);
    for(int h=0; h<argc; h++){
        printf("Argumento %d: %s\n", h, argv[h]);
    }
    int semente = atoi(argv[1]);
    printf("Semente: %d", semente);

    int i,N;
    printf("Digite o tamanho do vetor:");
    scanf("%d", &N);
    int vet[N];
    srand(semente);
    for ( i = 0; i < N; i++)
    {
        vet[i] = rand() % N;
    }
    printf("\nVetor nao ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    tempo_execu = clock();
    Quick(vet,0,N-1);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[2]);
    
    printf("\nComp = %d Mov=%d ", comp, mov);
    printf("\n");
    
}