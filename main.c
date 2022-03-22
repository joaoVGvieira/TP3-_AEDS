#include <stdio.h>
#include <stdlib.h>
#include "Quicksort_lib.h"
#include "Libs/arquivos.h"
int main(int argc, char *argv[]) {
        int comp=0,mov=0;
        clock_t tempo_execu;
        int N,semente;
        semente = atoi(argv[1]);
        printf("Inserir o valor de N da semente %d:",semente);
        scanf("%d",&N);
        int vet[N];
        srand(time(NULL));
        for ( int i = 0; i < N; i++)
        {
            vet[i] = rand() % N;
        }
        tempo_execu = clock();
        Quicksort_Recursivo(vet,0,N-1,&comp,&mov);
        tempo_execu =  clock()- tempo_execu;
        escreve_arquivo_tempo(vet,tempo_execu,N,comp,mov,argv[2]);
        printf("\n %d %d \n",comp,mov);
}