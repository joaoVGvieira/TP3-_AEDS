#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10



void Particao(int Esq, int Dir, int *i, int *j, int *A){

    int pivo, aux;

    *i = Esq;
    *j = Dir;

    int k=3;
    int num = *i - *j;
    int mediana;

    if(num >= k){
        int posicao[k];
        for(int i=0; i<k; i++){
            posicao[i] = rand() % num;  
        }

        int primeiro = posicao[0];
        int segundo = posicao[1];
        int terceiro = posicao[2];
        
        if (A[primeiro] < A[segundo]) {
            if (A[segundo] < A[terceiro]) {
                mediana = segundo;

            } else {
                if (A[primeiro] < A[terceiro]) {
                    mediana = terceiro;

                } else {
                    mediana = primeiro;

                }
            }
        } else {
            if (A[terceiro] < A[segundo]) {
                mediana = segundo;
                
            } else {
                if (A[terceiro] < A[primeiro]) {
                    mediana = terceiro;

                } else {
                    mediana = primeiro;

                }
            }
        }
    }
    if(num < k){
        mediana = *i;
    }
    pivo = A[mediana];

    do{
        while(pivo > A[*i]){
            (*i)++;
        }
        while(pivo < A[*j]){
            (*j)--;
        }
        if(*i <= *j){
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;

            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void Ordena(int Esq, int Dir, int *A){
    
    int i, j;
    Particao(Esq, Dir, &i, &j, A);

    if(Esq < j){
        Ordena(Esq, j, A);
    }
    if(i < Dir){
        Ordena(i, Dir, A);
    }
}

int main(){
    

    int v[N];
    srand(time(NULL));
    for(int i=0 ; i<N ; i++){
        v[i] = rand() % 100;
    }
    
    for(int i=0 ; i<N ; i++){
        printf(" %d - ", v[i]);
    }
    printf("\n");
    
    Ordena(0, N, v);

    for(int i=0; i<N; i++){
        printf("%d. ", v[i]);
    }

    return 0;
}