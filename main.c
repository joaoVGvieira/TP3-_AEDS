#include <stdio.h>
#include <stdlib.h>
#include "Libs/Quicksort_lib.h"
#include "Libs/arquivos.h"

int main(int argc, char *argv[]) {
        
    int comp = 0, mov = 0,i;
    clock_t tempo_execu;
    int semente;
    int N=atoi(argv[2]);
    int vet[N];
    semente = atoi(argv[1]);
    
    printf("Semente: %d\n", semente);
    printf("N: %d\n", N);
    printf("Nome arquivo: %s\n", argv[3]);
    
    srand(semente);
    for ( i = 0; i < N; i++){
        vet[i] = rand() % N;
    }
    
    
    
    //Quicksort_Recursivo(vet, 0, N-1, &comp, &mov);
    //QuickSort_Inteligente(vet,N,&comp,&mov);
    //Quicksort_Insercao10(vet,0,N-1,&comp,&mov);
    //Quicksort_Insercao100(vet,0,N-1,&comp,&mov);
    //QuickSort_Iterativo(vet, 0, N-1, &comp, &mov);
    //Ordena_Mediana3(0,N,vet,&comp,&mov);
    //Ordena_Mediana5(0, N, vet, &comp, &mov);
    tempo_execu =  clock()- tempo_execu;
    escreve_arquivo_tempo(vet, tempo_execu, N, comp, mov, argv[3]);
    for ( i = 0; i < N; i++){
        printf("%d ",vet[i]);
    }
    return 0;
}
