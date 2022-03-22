#include <stdio.h>
#include <stdlib.h>
#include "Libs/Quicksort_lib.h"
#include "Libs/arquivos.h"
void resetar_vetor(int *vet, int N, int semente){
    srand(semente);
    for ( int i = 0; i < N; i++){
         vet[i] = rand() % N;
    }
}
int main(int argc, char *argv[]) {
        
    int comp = 0, mov = 0,i,cont=0;
    clock_t tempo_execu;
    int semente;
    int N;
    N=atoi(argv[2]);
    int vet[N];
    semente = atoi(argv[1]);
    printf("Semente: %d\n", semente);
    printf("N: %d\n", N);
    printf("Nome arquivo: %s\n", argv[3]);

    srand(semente);
    resetar_vetor(vet,N,semente);
    
    tempo_execu =  clock();
    Quicksort_Recursivo(vet, 0, N-1, &comp, &mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3],cont);

    cont++;
    resetar_vetor(vet,N,semente);
    tempo_execu =  clock();
    QuickSort_Inteligente(vet,N,&comp,&mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3],cont);

    cont++;
    resetar_vetor(vet,N,semente);
    tempo_execu =  clock();
    Quicksort_Insercao10(vet,0,N-1,&comp,&mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3],cont);


    cont++;
    resetar_vetor(vet,N,semente);
    tempo_execu =  clock();
    Quicksort_Insercao100(vet,0,N-1,&comp,&mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3],cont);

    cont++;
    resetar_vetor(vet,N,semente);
    tempo_execu =  clock();
    QuickSort_Iterativo(vet, 0, N-1, &comp, &mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3],cont);
    
    cont++;
    resetar_vetor(vet,N,semente);
    tempo_execu =  clock();
    Ordena_Mediana3(0,N,vet,&comp,&mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3],cont);
    
    cont++;
    resetar_vetor(vet,N,semente);
    tempo_execu =  clock();
    Ordena_Mediana5(0, N, vet, &comp, &mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3],cont);
    
    return 0;
}
