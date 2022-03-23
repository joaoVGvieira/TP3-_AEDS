/*Quicksorts e funções subsequentes*/
void QuickSort_Inteligente(int vet[], int inicio,int fim,int *comp, int *mov);

void Quicksort_Insercao10(int vetor[], int inicio, int fim,int *comp, int *mov);
int Particao_Insercao10(int vetor[],int inicio, int fim,int *comp, int *mov);
void Ordena_Insercao10(int vetor[],int inicio,int fim,int *comp, int *mov);

void Quicksort_Insercao100(int vetor[], int inicio, int fim,int *comp, int *mov);
int Particao_Insercao100(int vetor[],int inicio, int fim,int *comp, int *mov);
void Ordena_Insercao100(int vetor[],int inicio,int fim,int *comp, int *mov);

void Particao_Mediana3(int Esq, int Dir, int *i, int *j, int *A,int *comp, int *mov);
void Ordena_Mediana3(int Esq, int Dir, int *A,int *comp, int *mov);

void Particao_Mediana5(int Esq, int Dir, int *i, int *j, int *A,int *comp, int *mov);
void Ordena_Mediana5(int Esq, int Dir, int *A,int *comp, int *mov);

void Quicksort_Recursivo(int vetor[], int inicio, int fim, int *comp, int *mov);

void QuickSort_Iterativo(int arr[], int l, int h,int *comp, int *mov);
int Particao_Iterativo(int arr[], int l, int h,int *comp, int *mov);
void Troca_Iterativo(int* a, int* b);
