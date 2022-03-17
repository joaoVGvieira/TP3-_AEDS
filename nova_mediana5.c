#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10



void Particao(int Esq, int Dir, int *i, int *j, int *A){

    int pivo, aux;

    *i = Esq;
    *j = Dir;

    int k=5;
    int num = *i - *j;
    int mediana;

    // ENCONTRA A MEDIANA ENTRE 3 ELEMENTOS
    if(num >= k){
        int posicao[k];
        // GERA 3 POSIÇÕES ALEATÓRIAS PARA CALCULAR MEDIANA
        for(int i=0; i<k; i++){
            posicao[i] = rand() % num;  
        }

        int primeiro = posicao[0];
        int segundo = posicao[1];
        int terceiro = posicao[2];
        int quarto = posicao[3];
        int quinto = posicao[4];
        int mediana;

        if (A[primeiro] < A[terceiro])
        {
            if (A[terceiro] < A[quinto]) {
                if(A[segundo] < A[terceiro]){
                    if(A[terceiro] < A[quarto]){
                        mediana = terceiro;

                    }else{
                        mediana = quarto;
                    }

                }else{
                    if(A[terceiro] < A[quarto]){
                        mediana = quarto;

                    }else{
                        mediana = terceiro;
                    }
                }      

            }else{
                if(A[primeiro] < A[quinto]){
                    if(A[segundo] < A[quinto]){
                        if(A[quinto] < A[quarto]){
                            mediana = quinto;

                        }else{
                            mediana = quarto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            mediana = segundo;

                        }else{
                            mediana = quarto;
                        }
                    }   
                        

                }else{
                    if(A[segundo] < A[quinto]){
                        if(A[quinto] < A[quarto]){
                            mediana = primeiro;

                        }else{
                            mediana = quinto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            mediana = segundo;

                        }else{
                            mediana = quarto;
                        }
                    }

                }
            }
        }
        else
        {
            if (A[terceiro] < A[quinto]) {
                if(A[segundo] < A[terceiro]){
                    if(A[terceiro] < A[quarto]){
                        mediana = quinto;

                    }else{
                        mediana = terceiro;
                    }

                }else{
                    if(A[terceiro] < A[quarto]){
                        mediana = segundo;

                    }else{
                        mediana = quinto;
                    }
                }      

            }else{
                if(A[primeiro] < A[quinto]){
                    if(A[segundo] < A[quinto]){
                        if(A[quinto] < A[quarto]){
                            mediana = primeiro;

                        }else{
                            mediana = quarto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            mediana = quarto;

                        }else{
                            mediana = segundo;
                        }
                    }   
                        

                }else{
                    if(A[segundo] < A[quinto]){
                        if(A[quinto] < A[quarto]){
                            mediana = quarto;

                        }else{
                            mediana = quinto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            mediana = segundo;

                        }else{
                            mediana = primeiro;
                        }
                    }

                }
            }
    }
    }
    if(num < k){
        mediana = *i;
    }

    pivo = A[mediana];

    //ORDENA A PARTIÇÃO DO VETOR
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

// CHAMA RECURSIVAMENTE O QUICKSORT
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