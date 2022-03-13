#include <stdio.h>
#include <stdlib.h>
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
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}

int main(){
    int vet[] = {3,1,2,5} ;
    size_t N = sizeof(vet)/sizeof(vet[0]);
    Quick(vet,0,N-1);
    int i;
    for ( i = 0; i < N; i++)
    {
        printf("%d ,",vet[i]);
    }
    
}