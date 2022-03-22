/*Quicksorts e funções subsequentes*/
void QuickSort_Inteligente(int vet[], int n);
void Compara_Inteligente(int inicio, int fim, int *esq, int *dir);
void Ordena_Inteligente(int inicio, int fim, int vet[],int esq, int dir);
void Particao_Inteligente(int inicio, int fim,int *i, int *j, int *vet);

void Quicksort_Insercao10(int vetor[], int inicio, int fim);
int Particao_Insercao10(int vetor[],int inicio, int fim);
void Ordena_Insercao10(int vetor[],int inicio,int fim);

void Quicksort_Insercao100(int vetor[], int inicio, int fim);
int Particao_Insercao100(int vetor[],int inicio, int fim);
void Ordena_Insercao100(int vetor[],int inicio,int fim);

void Particao_Mediana3(int Esq, int Dir, int *i, int *j, int *A);
void Ordena_Mediana3(int Esq, int Dir, int *A);

void Particao_Mediana5(int Esq, int Dir, int *i, int *j, int *A);
void Ordena_Mediana5(int Esq, int Dir, int *A);

void Quicksort_Recursivo(int vetor[], int inicio, int fim, int *comp, int *mov);

void QuickSort_Iterativo(int arr[], int l, int h);
int Particao_Iterativo(int arr[], int l, int h);
void Troca_Iterativo(int* a, int* b);