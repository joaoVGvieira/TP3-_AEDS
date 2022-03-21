#include <stdio.h>
#include <time.h>

int comp = 0, mov = 0;

// Troca dois elementos
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            comp++;
            i++;
            swap(&arr[i], &arr[j]);
            mov++;
        }
    }
    swap(&arr[i + 1], &arr[h]);
    mov++;
    return (i + 1);
}
 
/* A[] --> Lista sendo ordenada,
   l  --> Posição Inicial,
   h  --> Posição Final */
void quickSortIterativo(int arr[], int l, int h)
{
    // Criando lista auxiliar, que armazenará índices
    int stack[h - l + 1];
 
    // Inicializa o topo da lista auxiliar
    int top = -1;
 
    // Coloca os valores iniciais de l e h na lista auxiliar
    stack[++top] = l;
    stack[++top] = h;
 
    // Remove elementos da lista enquanto não está vazia
    while (top >= 0) {
        // Remove h e l
        h = stack[top--];
        l = stack[top--];
        
        // Define elemento pivô em sua posição correta
        // na lista ordenada
        int p = partition(arr, l, h);
 
        // Se existem elementos na parte esquerda do pivô,
        // então desloca a parte esquerda para a lista auxiliar
        if (p - 1 > l) {
            comp++;
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        // Se existem elementos na parte direita do pivô,
        // então desloca a parte direita para a lista auxiliar
        if (p + 1 < h) {
            comp++;
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
 
// Escreve a lista no terminal
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
 
// Função Main
int main()
{
    clock_t tempo_execu;
    char tempo[20];
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
    int n = sizeof(arr) / sizeof(*arr);
    tempo_execu = clock();
    quickSortIterativo(arr, 0, n - 1);
    tempo_execu =  clock()- tempo_execu;
    printf("\n%f ", ((float)tempo_execu)/(float)CLOCKS_PER_SEC);
    printf("%d %d ", mov, comp);
    printf("\n");
    printArr(arr, n);
    return 0;
}
