#include <stdio.h>
#include <stdlib.h>
 
void Ordena(int inicio, int fim, int *vet)
{
    int i,j,menor;    
    Particao(inicio, fim, &i, &j, vet);
    menor=compara(inicio,fim,vet); 
    printf("menor==%d\n",menor);
    if (menor==0)
    {
        if (inicio < j) Ordena(inicio, j, vet);
    }
    if (menor==1)
    {
        if (i < fim) Ordena(i, fim, vet); 
    }
}
void QuickSort(int *vet, int n)
{
    Ordena(0, n-1, vet);
}

// ESSA FUNÇAO VAI COMPARAR O MENOR LADO ANTES OU DEPOIS DO PIVO
int compara(int inicio, int fim, int *vet){
    int pivo,i,j,cont_esq=0,cont_dir=0,media=0;
    i = inicio;
    j = fim;
    media=(i + j)/2;
    pivo = vet[media];
    //printf("pivor==%d\n",media);
    for ( int k = 0; k < media; k++)
    {
        cont_esq++;

    }
    for ( int h = fim; h > media; h--)
    {
        cont_dir++;
 
    }
    if (cont_esq <= cont_dir)
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
    int vet[] = {8,3,15,6,7,4};
    size_t N = sizeof(vet)/sizeof(vet[0]);
    QuickSort(&vet,N);
    printf("\nVetor ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
   
}