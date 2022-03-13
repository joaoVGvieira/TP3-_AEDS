#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int vetor[],int inicio,int fim)
  {
    int aux,i,j;
    for(i=1;i<fim+1;i++)
    {
      aux = vetor[i] ;
      j = i;
    while (j>inicio && vetor[j-1]>aux)
      {
        vetor[j]= vetor[j-1] ;
        j-= 1;
    }
    vetor[j]= aux ;
    }
 
}
int particao(int vetor[],int inicio, int fim){
   
   int pivo, aux, i, j;

   j = inicio;

   pivo = vetor[fim];
   
   for (i = inicio; i < fim; i++)
     {
      if(vetor[i]<pivo)
      {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
        j += 1;
      }
    }
    aux = vetor[j];
    vetor[j] = vetor[fim];
    vetor[fim] = aux;
 
  return j;
}

void Quicksort_Insercao(int vetor[], int inicio, int fim)
{
  while (inicio < fim)
    {
        // colocar 100 para m=100;
    if (fim-inicio + 1 < 2)
      {
        insertion_sort(vetor,inicio, fim);
      break;
    }
 
    else
        { // encontrar pivor para comer usar o quicksort 
          int pivo = particao(vetor,inicio,fim) ;
          if (pivo-inicio<fim-pivo)
        {
          Quicksort_Insercao(vetor, inicio, pivo - 1);
          inicio = pivo + 1;
       }
      else
        {
        Quicksort_Insercao(vetor, pivo + 1, fim);
        fim = pivo-1;
        }
 
     }
 
   }
}

int main(){
    int vet[] = {3,1,2,5} ;
    size_t N = sizeof(vet)/sizeof(vet[0]);
    Quicksort_Insercao(vet,0,N-1);
    int i;
    for ( i = 0; i < N; i++)
    {
        printf("%d ,",vet[i]);
    }
    
}