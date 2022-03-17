#include <stdio.h>
#include <stdlib.h>
//chama o quick normal para achar o pivo e ordernar o vetor
void Quick(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   do{
      while (vetor[i] < pivo) i+= 1;
      while (vetor[j] > pivo) j-= 1;
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i+= 1;
         j-= 1;
      }
   }while(j > i);
   //chama recursivamente o quick
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}

int main(){
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
    Quick(vet,0,N-1);
    printf("\nVetor ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
    
}