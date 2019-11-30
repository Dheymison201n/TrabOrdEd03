#include<iostream>

void ite_bubbleSort(int Vet[], int n){
    for(int i = 0; i < n; i++)
        for(int j = n-1; > i; --j)
            if(Vet[j] < Vet[j-1])
                swap(Vet[j], Vet[j-1])
}

void rec_bubbleSort(int Vet[], int n){
    // Caso base
    if (n == 1) // se o tamanho do vetor for 1, retorne.
        return; 

    for (int i=0; i<n-1; i++) 
        if (Vet[i] > Vet[i+1]) 
            swap(Vet[i], Vet[i+1]);
    
    // O maior elemento é fixo,
    // recorrente para o vetor restante
    bubbleSort(Vet, n-1); 
  
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_insertionSort(int Vet[], int n){
    for(int i = 1; i < n; i++){
        int aux = Vet[i]
            for(int j = i; j > 0 && aux < Vet[j-1]; j--)
                Vet[j] = Vet[j-1];
                Vet[j] = aux;
    }
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_selectionSort(int Vet[], int n){
    for(int i = 0, j, menor; i < n-1; i++){
        for( j = i+1, menor = i; j < n; j++)
            if (Vet[j] < Vet[menor])
                menor = j;
                swap(Vet[menor],Vet[i]);
    }   
}

/*----------------------------------------------------------------------------------------------------------------*/

void merge(int Vet[], int inicio, int meio, int fim){
    int *aux, 
}

void rec_mergeSort(int Vet[], int inicio, int fim){
    int meio;
        if(inicio < fim){
            meio = floor((inicio+fim)/2);
            rec_mergeSort(Vet, incio, meio);  // Chama a função
            rec_mergeSort(Vet, meio, fim);    // para as 2 metades
            merge(V, inicio, meio, fim);        // Combina as duas metades de forma ordenada
        }
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_heapSort(){

}

/*----------------------------------------------------------------------------------------------------------------*/

void rec_quickSort(int Vet[], int n){
    if(n < 2)
        return;
    for(int i = 1, max = 0; i < n; i++) // encontra o maior elemento
        if(Vet[max] < Vet[i])           // e coloque-o
            max = i;                    // no final de Vet[]
    swap(Vet[n-1], Vet[max]);   // O maior elemento está agora em sua
    rec_quicksort(Vet,0,n-2);   // posição final
}

/*----------------------------------------------------------------------------------------------------------------*/

bool Ordenado(int a[], int n) 
{ 
    while (--n > 1) 
        if (a[n] < a[n - 1]) 
            return false; 
    return true; 
} 
  
// Gerando permutação do vetor
void embaralhar(int Vet[], int n) { 
    for (int i = 0; i < n; i++) 
        swap(Vet[i], a[rand() % n]); 
} 

// Ordena o vetor Vet[0..n-1] usando Bogosort 
void bogoSort(int Vet[], int n) { 
    while (!Ordenado(a, n)) // Se o vetor não for ordenado, embaralhe
        embaralhar(a, n);   // o vetor novemente
}