#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
    int cont_esq;
    int cont_dir;
}tamanho;
 
void Ordena(int inicio, int fim, int *vet, int cont)
{
    int i,j,k=0,m;
    tamanho teste;    
    if (cont==0)
    {
        compara(inicio,fim,vet,&teste);
    }
    if (teste.cont_esq <= teste.cont_dir)
    {
        printf("esquerda\n");
    }
    else if (teste.cont_dir < teste.cont_esq )
    {
        printf("direita menor\n");
       
    }
     
}
void QuickSort(int *vet, int n)
{
    Ordena(0, n-1, vet, 0);
}
void compara(int inicio, int fim, int *vet, tamanho *teste){
    int pivo,i,j,cont_esq=0,cont_dir=0,media=0;
    i = inicio;
    j = fim;
    media=(i + j)/2;
    pivo = vet[media];
    for ( int k = 0; k < media; k++)
    {
        cont_esq++;
 
    }
 
    for ( int h = fim; h > media; h--)
    {
        cont_dir++;
 
    }
    teste->cont_esq= cont_esq;
    teste->cont_dir = cont_dir;
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
    int vet[] = {8,3,15,6,7,4};
    size_t N = sizeof(vet)/sizeof(vet[0]);
    QuickSort(&vet,N);
    
    int i;
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
   
}