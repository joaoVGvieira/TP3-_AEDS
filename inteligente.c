#include <stdio.h>
#include <stdlib.h>
 
void Ordena(int inicio, int fim, int *vet,int esq, int dir)
{
    int i,j;
    Particao(inicio, fim, &i, &j, vet);
    compara(inicio,fim,&esq,&dir);
    if (esq < dir)
    {
        esq++;
        if (esq < dir) Ordena(inicio, j, vet,esq,dir);        
    }
    if (dir > esq)
    {
        dir--;
        if (dir > esq) Ordena(i, fim, vet,esq,dir);
    }
    if(esq==dir)
    {
        if (inicio < j) Ordena(inicio, j, vet,esq,dir);
        if (i < fim) Ordena(i, fim, vet,esq,dir);      
    }
}
void QuickSort(int *vet, int n)
{
    Ordena(0, n-1, vet,0,0);
}

// ESSA FUNÇAO VAI COMPARAR O MENOR LADO ANTES OU DEPOIS DO PIVO
void compara(int inicio, int fim, int *esq, int *dir){
    int pivo,i,j,media;
    i = inicio;
    j = fim;
    media=(i + j)/2;
    for ( int k = i; k < media; k++)
    {
        *esq+=1;
    }
    for ( int h = j; h > media; h--)
    {
        *dir+=1;
 
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
    int vet[]={2,1,3,5,5,8,7,4,6};
    size_t N = sizeof(vet)/sizeof(vet[0]);
    printf("\nN=%d\n",N);
    QuickSort(&vet,N);
    printf("\nVetor ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
   
}