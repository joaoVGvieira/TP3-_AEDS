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
/* funçao partição do quick sort que vai retorna j que é o numero inicio mais as alterações feitas quando 
vetor[i] é menor que o pivo; 
*/
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
    // caso (fim - inicio) mais um for menor que 10, ira usar insertion_sort caso o contrario ira usar quicksort,
    if (fim-inicio + 1 < 100)
      {
        insertion_sort(vetor,inicio, fim);
      break;
    }
 
    else
        { // encontrar pivor para usar o quicksort 
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
    //chama o quicksort
    Quicksort_Insercao(vet,0,N-1);
    printf("\nVetor ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
    
    
}