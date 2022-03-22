#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 int comp = 0, mov = 0;
//funçao abaixor vai ver qual lado é menor do vetor 
void Ordena(int inicio, int fim, int vet[],int esq, int dir)
{
    int i,j;
    //dividir o vetor no meio selecionando o pivo
    Particao(inicio, fim, &i, &j, vet);
    //chama funçao compara para contar o lado esq e dir do pivo.
    compara(inicio,fim,&esq,&dir);
    // ifs abaixo vai compara todos os casos possivei esquerda menor, direita menor ou igual os numeros do contador
    if (esq < dir)
    {   
        comp++;
        esq++;
        if (esq < dir){
            comp++;
            Ordena(inicio, j, vet,esq,dir);
        }        
    }
    if (dir < esq)
    {           
        comp++;
        dir--;
        if (dir > esq) {
            comp++;
            Ordena(i, fim, vet,esq,dir);
        }
    }
    if(esq==dir)
    {
        comp++;
        if (inicio < j){
            comp++;
            Ordena(inicio, j, vet,esq,dir);
        } 
        if (i < fim) {
            comp++;
            Ordena(i, fim, vet,esq,dir);
        }      
    }
}
void QuickSort(int vet[], int n)
{
    Ordena(0, n-1, vet,0,0);
}

// Essa funçao vai conta o lado direito e esquerdo vetor 
void compara(int inicio, int fim, int *esq, int *dir){
    int i,j,meio;
    i = inicio;
    j = fim;
    meio=(i + j)/2;
    for ( int k = i; k < meio; k++)
    {
        *esq+=1;
    }
    for ( int h = j; h > meio; h--)
    {
        *dir+=1;
 
    } 
}
 // partiçao é normal como todos os casos do partiçao do quicksort
void Particao(int inicio, int fim,int *i, int *j, int *vet){
    int pivo, aux;
    *i = inicio;
    *j = fim;
    pivo = vet[(*i + *j)/2];
    do
    {
        comp++;
        while (pivo > vet[*i]){
            comp++;
            (*i)++;
        }
        while (pivo < vet[*j]) {
            comp++;
            (*j)--;
        }
        if (*i <= *j)
        {
            comp++;
            aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            mov++;
            (*i)++;
            (*j)--;
        }
    }while (*i <= *j);
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
    QuickSort(&vet,N);
    printf("\nVetor ordenado:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\nComp = %d Mov=%d ", mov, comp);
    printf("\n");
   
}