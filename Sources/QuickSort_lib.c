#include "../Libs/Quicksort_lib.h"
#include <stdio.h>
#include <stdlib.h>
void QuickSort_Inteligente(int vet[],int inicio, int fim,int *comp, int *mov)
{
   int pivo, aux, i, j, meio;
   i = inicio;
   j = fim;
   
   meio = ((i + j) / 2);
   pivo = vet[meio];
   do{ 
      while (vet[i] < pivo){
         (*comp)++;  
         i+= 1;
      }
      while (vet[j] > pivo){
          (*comp)++;
          j-= 1;
      }
      if(i <= j){
         (*comp)++; 
         (*mov)++;
         aux = vet[i];
         (*mov)++;
         vet[i] = vet[j];
        (*mov)++;
         vet[j] = aux;
         i+= 1;
         j-= 1;
      }
      else
      {
          (*comp)++;
      }
      (*comp)++;
   }while(j > i);

   if (fim-j < inicio-i)
   {
       (*comp)++;
       if (j > inicio)
       {
           (*comp)++;
           QuickSort_Inteligente(vet, inicio, j,comp,mov);
       }
       (*comp)++;
       if (i < fim)
       {   (*comp)++; 
           QuickSort_Inteligente(vet, i, fim,comp,mov);
       }
       
   }
   else
   {   
       (*comp)++; 
       if (i < fim)
       {    (*comp)++;
           QuickSort_Inteligente(vet, i, fim,comp,mov);
       }
       (*comp)++;
       if (j > inicio)
       {
           (*comp)++;
           QuickSort_Inteligente(vet, inicio, j,comp,mov);
       }
   }
}

//Inserçao 10
void Quicksort_Insercao10(int vetor[], int inicio, int fim,int *comp, int *mov){
    while (inicio < fim)
    {
    (*comp)++;
    // caso (fim - inicio) mais um for menor que 10, ira usar Ordena_Insercao10 caso o contrario ira usar quicksort,
    if (fim-inicio + 1 <= 10)
    { 
      (*comp)++;  
      Ordena_Insercao10(vetor,inicio, fim,comp,mov);
      break;
    }
 
    else
        { // encontrar pivor para usar o quicksort 
          (*comp)++;
          int pivo = Particao_Insercao10(vetor,inicio,fim,comp,mov) ;
          if (pivo-inicio<fim-pivo)
        { 
          (*comp)++;
          Quicksort_Insercao10(vetor, inicio, pivo - 1,comp,mov);
          inicio = pivo + 1;
       }
      else
        {
        (*comp)++;
        Quicksort_Insercao10(vetor, pivo + 1, fim,comp,mov);
        fim = pivo-1;
        }
 
     }
 
   }
}
int Particao_Insercao10(int vetor[],int inicio, int fim,int *comp, int *mov){
    int pivo, aux, i, j;

   j = inicio;

   pivo = vetor[fim];
   
   for (i = inicio; i < fim; i++)
     {
      if(vetor[i]<pivo)
      {
        (*comp)++; 
        (*mov)++; 
        aux = vetor[i];
        (*mov)++;
        vetor[i] = vetor[j];
        (*mov)++;
        vetor[j] = aux;
        j += 1;
      }
      else
      {
          (*comp)++;
      }
      
    }
    (*mov)++;
    aux = vetor[j];
    (*mov)++;
    vetor[j] = vetor[fim];
    (*mov)++;
    vetor[fim] = aux;
 
  return j;
}
void Ordena_Insercao10(int vetor[],int inicio,int fim,int *comp, int *mov){
    int aux,i,j;
    for(i=1;i<fim+1;i++)
    {
      aux = vetor[i] ;
      j = i;
    while (j>inicio && vetor[j-1]>aux)
      {
        (*comp)++;
        (*mov)++;
        vetor[j]= vetor[j-1] ;
        j-= 1;
    }
    vetor[j]= aux ;
    }
}
void Quicksort_Insercao100(int vetor[], int inicio, int fim, int *comp, int *mov){
    while (inicio < fim)
  {
    (*comp)++;
    // caso (fim - inicio) mais um for menor que 10, ira usar Ordena_Insercao100 caso o contrario ira usar quicksort,
    if (fim-inicio + 1 <= 100){
      (*comp)++;
      Ordena_Insercao100(vetor,inicio, fim, comp, mov);
      break;
    }
 
    else
        { // encontrar pivor para usar o quicksort 
          int pivo = Particao_Insercao100(vetor, inicio, fim, comp, mov) ;
        if (pivo-inicio<fim-pivo)
        { (*comp)++; 
          Quicksort_Insercao100(vetor, inicio, pivo - 1, comp, mov);
          inicio = pivo + 1;
        }
      else
        {
        Quicksort_Insercao100(vetor, pivo + 1, fim, comp, mov);
        fim = pivo-1;
        }
 
     }
 
   }
}
int Particao_Insercao100(int vetor[],int inicio, int fim, int *comp, int *mov){
    int pivo, aux, i, j;
    j = inicio;
    pivo = vetor[fim];
   
    for (i = inicio; i < fim; i++){
        if(vetor[i]<pivo){
            (*comp)++;
            aux = vetor[i];
            (*mov)++;
            vetor[i] = vetor[j];
            (*mov)++;
            vetor[j] = aux;
            (*mov)++;
            j += 1;
        }
  }
  aux = vetor[j];
  (*mov)++;
  vetor[j] = vetor[fim];
  (*mov)++;
  vetor[fim] = aux;
  (*mov)++;
 
  return j;
}
void Ordena_Insercao100(int vetor[],int inicio,int fim, int * comp, int * mov){
    int aux,i,j;
    for(i=1;i<fim+1;i++){
    (*mov)++;    
    aux = vetor[i];
    j = i;
    while (j>inicio && vetor[j-1]>aux){
      (*comp)++;
      (*mov)++;
      vetor[j]= vetor[j-1] ;
      j-= 1;
    }
    (*mov)++;
    vetor[j]= aux ;
  }
}

void Particao_Mediana3(int Esq, int Dir, int *i, int *j, int *A, int *comp, int *mov){
    int pivo, aux;
    *i = Esq;
    *j = Dir;
    int k=3;
    int num = *i - *j;
    int mediana;
    // ENCONTRA A MEDIANA ENTRE 3 ELEMENTOS 
    if(num >= k){
        (*comp)++;
        int posicao[k];
        // GERA 3 POSIÇÕES ALEATÓRIAS PARA CALCULAR MEDIANA
        for(int i=0; i<k; i++){
            posicao[i] = rand() % num;  
        }
        int primeiro = posicao[0];
        int segundo = posicao[1];
        int terceiro = posicao[2];
        
        if (A[primeiro] < A[segundo]) {
            (*comp)++;
            if (A[segundo] < A[terceiro]) {
                (*comp)++;
                mediana = segundo;
                comp++;
            } else {
                (*comp)++;
                if (A[primeiro] < A[terceiro]) {
                    (*comp)++;
                    mediana = terceiro;
                } else {
                    (*comp)++;
                    mediana = primeiro;
                }
            }
        } else {
            if (A[terceiro] < A[segundo]) {
                (*comp)++;
                mediana = segundo;
            } else {
                    (*comp)++;
                if (A[terceiro] < A[primeiro]) {
                    (*comp)++;
                    mediana = terceiro;
                } else {
                    (*comp)++;
                    mediana = primeiro;
                }
            }
        }
    }
    if(num < k){
        (*comp)++;
        mediana = *i;
    }
    else
    {
        (*comp)++;
    }
    pivo = A[mediana];
    //ORDENA A PARTIÇÃO DO VETOR
    do{
        (*comp)++;
        while(pivo > A[*i]){
            (*comp)++;
            (*i)++;
        }
        (*comp)++;
        while(pivo < A[*j]){
            (*comp)++;
            (*j)--;
        }
        if(*i <= *j){
            (*comp)++;
            aux = A[*i];
            (*mov)++;
            A[*i] = A[*j];
            (*mov)++;
            A[*j] = aux;
            (*mov)++;
            (*i)++;
            (*j)--;
        }
        (*comp)++;
    }while(*i <= *j);
}
void Ordena_Mediana3(int Esq, int Dir, int *A, int *comp, int *mov){
    int i, j;
    Particao_Mediana3(Esq, Dir, &i, &j, A, comp, mov);
    if(Esq < j){
        (*comp)++;
        Ordena_Mediana3(Esq, j, A, comp, mov);
    }
    else
    {
        (*comp)++;
    }
    if(i < Dir){
        (*comp)++;
        Ordena_Mediana3(i, Dir, A, comp, mov);
    }
    else
    {
        (*comp)++;
    }
    
}

void Particao_Mediana5(int Esq, int Dir, int *i, int *j, int *A, int *comp, int *mov){
    int pivo, aux;
    *i = Esq;
    *j = Dir;
    int k=5;
    int num = *i - *j;
    int mediana;
    // ENCONTRA A MEDIANA ENTRE 3 ELEMENTOS
    if(num >= k){
        (*comp)++;
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
        if (A[primeiro] < A[terceiro]){
            (*comp)++;
            if (A[terceiro] < A[quinto]){
                (*comp)++;
                if(A[segundo] < A[terceiro]){
                    (*comp)++;
                    if(A[terceiro] < A[quarto]){
                        (*comp)++;
                        mediana = terceiro;
                    }else{
                        (*comp)++;
                        mediana = quarto;
                    }
                }else{
                    if(A[terceiro] < A[quarto]){
                        (*comp)++;
                        mediana = quarto;
                    }else{
                        (*comp)++;
                        mediana = terceiro;
                    }
                }      
            }else{
                if(A[primeiro] < A[quinto]){
                    (*comp)++;
                    if(A[segundo] < A[quinto]){
                        (*comp)++;
                        if(A[quinto] < A[quarto]){
                            (*comp)++;
                            mediana = quinto;
                        }else{
                            (*comp)++;
                            mediana = quarto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            (*comp)++;
                            mediana = segundo;
                        }else{
                            (*comp)++;
                            mediana = quarto;
                        }
                    }   
                        
                }else{
                    if(A[segundo] < A[quinto]){
                        (*comp)++;
                        if(A[quinto] < A[quarto]){
                            (*comp)++;
                            mediana = primeiro;
                        }else{
                            (*comp)++;
                            mediana = quinto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            (*comp)++;
                            mediana = segundo;
                        }else{
                            (*comp)++;
                            mediana = quarto;
                        }
                    }
                }
            }
        }
        else
        {
            if (A[terceiro] < A[quinto]){
                (*comp)++;
                if(A[segundo] < A[terceiro]){
                    (*comp)++;
                    if(A[terceiro] < A[quarto]){
                        (*comp)++;
                        mediana = quinto;
                    }else{
                        (*comp)++;
                        mediana = terceiro;
                    }
                }else{
                    if(A[terceiro] < A[quarto]){
                        (*comp)++;
                        mediana = segundo;
                    }else{
                        (*comp)++;
                        mediana = quinto;
                    }
                }      
            }else{
                if(A[primeiro] < A[quinto]){
                    (*comp)++;
                    if(A[segundo] < A[quinto]){
                        (*comp)++;
                        if(A[quinto] < A[quarto]){
                            (*comp)++;
                            mediana = primeiro;
                        }else{
                            (*comp)++;
                            mediana = quarto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            (*comp)++;
                            mediana = quarto;
                        }else{
                            (*comp)++;
                            mediana = segundo;
                        }
                    }   
                        
                }else{
                    if(A[segundo] < A[quinto]){
                        (*comp)++;
                        if(A[quinto] < A[quarto]){
                            (*comp)++;
                            mediana = quarto;
                        }else{
                            (*comp)++;
                            mediana = quinto;
                        }
                    }else{
                        if(A[quarto] < A[segundo]){
                            (*comp)++;
                            mediana = segundo;
                        }else{
                            (*comp)++;
                            mediana = primeiro;
                        }
                    }
                }
            }
    }
    }
    if(num < k){
        (*comp)++;
        mediana = *i;
    }
    else
    {
        (*comp)++;
    }
    
    pivo = A[mediana];
    //ORDENA A PARTIÇÃO DO VETOR
    do{
        while(pivo > A[*i]){
            (*comp)++;
            (*i)++;
        }
        while(pivo < A[*j]){
            (*comp)++;
            (*j)--;
        }
        if(*i <= *j){
            (*comp)++;
            aux = A[*i];
            (*mov)++;
            A[*i] = A[*j];
            (*mov)++;
            A[*j] = aux;
            (*mov)++;
            (*i)++;
            (*j)--;
        }
        else
        {
            (*comp)++;
        }
        (*comp)++;
    }while(*i <= *j);
}
void Ordena_Mediana5(int Esq, int Dir, int *A, int *comp, int *mov){
    int i, j;
    Particao_Mediana5(Esq, Dir, &i, &j, A,comp,mov);
    if(Esq < j){
        (*comp)++;
        Ordena_Mediana5(Esq, j, A, comp, mov);
    }
    if(i < Dir){
        (*comp)++;
        Ordena_Mediana5(i, Dir, A, comp, mov);
    }
}

void Quicksort_Recursivo(int vetor[], int inicio, int fim,int *comp, int *mov){
    int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   do{
       (*comp)++;
      while (vetor[i] < pivo){
         (*comp)++;
         i+= 1;
      }
      (*comp)++; 
      while (vetor[j] > pivo){
          (*comp)++;
          j-= 1;
      }
      (*comp)++; 
      if(i <= j){
         (*comp)++; 
         aux = vetor[i];
         (*mov)++;
         vetor[i] = vetor[j];
         (*mov)++;
         vetor[j] = aux;
         (*mov)++;
         i+= 1;
         j-= 1;
      }
   }while(j > i);
   if(inicio < j){
       (*comp)++;
       Quicksort_Recursivo(vetor, inicio, j, comp,mov);
   }else
   {
       (*comp)++;
   }
   if(i < fim) {
       (*comp)++;  
       Quicksort_Recursivo(vetor, i, fim,comp,mov);
   }else
   {
       (*comp)++;
   }
   
}
void QuickSort_Iterativo(int arr[], int l, int h, int * comp, int * mov){
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
        int p = Particao_Iterativo(arr, l, h, comp, mov);
 
        // Se existem elementos na parte esquerda do pivô,
        // então desloca a parte esquerda para a lista auxiliar
        if (p - 1 > l) {
            (*comp)++;
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        else
        {
            (*comp)++;

        }        
        // Se existem elementos na parte direita do pivô,
        // então desloca a parte direita para a lista auxiliar
        if (p + 1 < h) {
            (*comp)++;
            stack[++top] = p + 1;
            stack[++top] = h;
        }else
        {
            (*comp)++;
        }
        
    }
}
int Particao_Iterativo(int arr[], int l, int h, int * comp, int * mov){
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            (*comp)++;
            i++;
            Troca_Iterativo(&arr[i], &arr[j]);
            (*mov)++;
        }else
        {
            (*comp)++;
        }
        
    }
    Troca_Iterativo(&arr[i + 1], &arr[h]);
    (*mov)++;
    return (i + 1);
}
void Troca_Iterativo(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
