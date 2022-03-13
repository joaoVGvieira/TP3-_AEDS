#include <stdio.h>
#include <stdlib.h>
 
void Ordena(int inicio, int fim, int *vet, int cont)
{
    int i,j,menor=0;    
    Particao(inicio, fim, &i, &j, vet);
    if (cont==0){
        menor=compara(inicio,fim,vet); 
    }
    if (menor==0)
    {
        if (inicio < j) 
        {
            Ordena(inicio, j, vet,1);
        }
        menor++;
    }
    if(menor==1)
    {
        if (i < fim) 
        {
            Ordena(i, fim, vet,1); 
        }
    }
}
void QuickSort(int *vet, int n)
{
    Ordena(0, n-1, vet,0);
}

// ESSA FUNÇAO VAI COMPARAR O MENOR LADO ANTES OU DEPOIS DO PIVO
int compara(int inicio, int fim, int *vet){
    int pivo,i,j,cont_esq=0,cont_dir=0,media=0;
    i = inicio;
    j = fim;
    media=(i + j)/2;
    pivo = vet[media];
    for ( int k = 0; k < media; k++)
    {
        cont_esq+=1;

    }
    for ( int h = fim; h > media; h--)
    {
        cont_dir+=1;
    }
    printf("esq=%d\ndir=%d\n",cont_esq,cont_dir);
   if (cont_esq <= cont_dir )
   {
       return 0;
   }
   else
   {
       return 1;
   }
   
   
}
 
void Particao(int inicio, int fim,int *i, int *j, int *vet){
    int pivo, aux;
    *i = inicio;
    *j = fim;
    pivo = vet[(*i + *j)/2];
    do
    {
        while (pivo > vet[*i]){
            (*i)++;
        }
        while (pivo < vet[*j]) {
            (*j)--;
        }
        if (*i <= *j)
        {
            aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }while (*i <= *j);
}
int main(){
    int i;
    int vet[] = {8,3,15,6,7,4,2,1};
    size_t N = sizeof(vet)/sizeof(vet[0]);
    QuickSort(&vet,N);
    printf("\nVetor ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
   
}