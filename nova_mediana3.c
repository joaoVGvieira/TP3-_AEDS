#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int comp = 0, mov = 0;


void Particao(int Esq, int Dir, int *i, int *j, int *A){

    int pivo, aux;

    *i = Esq;
    *j = Dir;

    int k=3;
    int num = *i - *j;
    int mediana;

    // ENCONTRA A MEDIANA ENTRE 3 ELEMENTOS 
    if(num >= k){
        comp++;
        int posicao[k];
        // GERA 3 POSIÇÕES ALEATÓRIAS PARA CALCULAR MEDIANA
        for(int i=0; i<k; i++){
            posicao[i] = rand() % num;  
        }

        int primeiro = posicao[0];
        int segundo = posicao[1];
        int terceiro = posicao[2];
        
        if (A[primeiro] < A[segundo]) {
            comp++;
            if (A[segundo] < A[terceiro]) {
                mediana = segundo;
                comp++;

            } else {
                if (A[primeiro] < A[terceiro]) {
                    comp++;
                    mediana = terceiro;

                } else {
                    mediana = primeiro;

                }
            }
        } else {
            if (A[terceiro] < A[segundo]) {
                comp++;
                mediana = segundo;
                
            } else {
                if (A[terceiro] < A[primeiro]) {
                    comp++;
                    mediana = terceiro;

                } else {
                    mediana = primeiro;

                }
            }
        }
    }
    if(num < k){
        comp++;
        mediana = *i;
    }
    pivo = A[mediana];

    //ORDENA A PARTIÇÃO DO VETOR
    do{
        while(pivo > A[*i]){
            comp++;
            (*i)++;
        }
        while(pivo < A[*j]){
            comp++;
            (*j)--;
        }
        if(*i <= *j){
            comp++;
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;
            mov++;

            (*i)++;
            (*j)--;
        }
        comp++;
    }while(*i <= *j);
}

// CHAMA RECURSIVAMENTE O QUICKSORT
void Ordena(int Esq, int Dir, int *A){
    
    int i, j;
    Particao(Esq, Dir, &i, &j, A);

    if(Esq < j){
        comp++;
        Ordena(Esq, j, A);
    }
    if(i < Dir){
        comp++;
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
    printf("\n");
    printf("MOVIMENTACOES: %d\n COMPARACOES:%d\n");

    return 0;
}