#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arquivo.h"
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

int main(){
    clock_t tempo_execu;
    tempo_execu = clock();
    int i,N;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&N);
    int vet[N];
    srand(time(NULL));
    for ( i = 0; i < N; i++)
    {
        vet[i] = rand() % 30;
    }
    printf("\nVetor nao ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    tempo_execu = clock();
    Quick(vet,0,N-1);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet,tempo_execu,N,comp,mov);
    /*printf("\nVetor ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }*/
    printf("\nComp = %d Mov=%d ", comp, mov);
    printf("\n");
    
}