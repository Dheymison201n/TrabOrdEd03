#include <iostream>

#include <bits/stdc++.h>

using namespace std;

/*----------------------------------------------------------------------------------------------------------------*/

void ite_bubbleSort(int Vet[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (Vet[j] > Vet[j + 1])
            {
                swap(Vet[j], Vet[j + 1]);
            }
        }
    }
}

void rec_bubbleSort(int Vet[], int n)
{
    // Caso base
    if (n == 1) // se o tamanho do vetor for 1, retorne.
        return;

    for (int i = 0; i < n - 1; i++)
        if (Vet[i] > Vet[i + 1])
            swap(Vet[i], Vet[i + 1]);

    // O maior elemento é fixo,
    // recorrente para o vetor restante
    rec_bubbleSort(Vet, n - 1);
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_insertionSort(int Vet[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        int aux = Vet[i];
        for (j = i; j > 0 && aux < Vet[j - 1]; j--)
        {
            Vet[j] = Vet[j - 1];
        }
        Vet[j] = aux;
    }
}

void rec_insertionSort(int Vet[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    rec_insertionSort(Vet, n - 1);

    // Insert last element at its correct position
    // in sorted Vetay.
    int last = Vet[n - 1];
    int j = n - 2;

    /* Move elements of Vet[0..i-1], that are 
      greater than key, to one position ahead 
      of their current position */
    while (j >= 0 && Vet[j] > last)
    {
        Vet[j + 1] = Vet[j];
        j--;
    }
    Vet[j + 1] = last;
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_selectionSort(int Vet[], int n)
{
    int i, j, min;
    for (i = 0; i < (n - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < n; j++)
        {
            if (Vet[j] < Vet[min])
                min = j;
        }
        swap(Vet[i], Vet[min]);
    }
}

int mini(int a[], int i, int j)
{
    if (i == j)
        return i;

    // Find minimum of remaining elements
    int k = mini(a, i + 1, j);

    // Return minimum of current and remaining.
    return (a[i] < a[k]) ? i : k;
}

void rec_selectionSort(int Vet[], int n, int i = 0)
{
    // Return when starting and size are same
    if (i == n)
        return;

    // calling minimum i function for minimum i
    int k = mini(Vet, i, n - 1);

    // Swapping when i nd minimum i are not same
    if (k != i)
        swap(Vet[k], Vet[i]);

    // Recursively calling selection sort function
    rec_selectionSort(Vet, n, i + 1);
}

/*----------------------------------------------------------------------------------------------------------------*/

void merge(int Vet[], int inicio, int meio, int fim)
{
    int *temp, p1, p2, tam, i, j, k;
    int fim1 = 0, fim2 = 0;
    tam = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *)malloc(tam * sizeof(int));
    if (temp != NULL)
    {
        for (i = 0; i < tam; i++)
        {
            if (!fim1 && !fim2)
            {
                if (Vet[p1] < Vet[p2])
                    temp[i] = Vet[p1++];
                else
                    temp[i] = Vet[p2++];
                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                {
                    temp[i] = Vet[p1++];
                }
                else
                {
                    temp[i] = Vet[p2++];
                }
            }
        }
        for (j = 0, k = inicio; j < tam; j++, k++)
            Vet[k] = temp[j];
    }
    free(temp);
}

void rec_mergeSort(int Vet[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        rec_mergeSort(Vet, inicio, meio);  // Chama a função
        rec_mergeSort(Vet, meio + 1, fim); // para as 2 metades
        merge(Vet, inicio, meio, fim);     // Combina as duas metades de forma ordenada
    }
}

void ite_mergeSort(int Vet[], int n)
{
    int b = 1;
    while (b < n)
    {
        int p = 0;
        while (p + b < n)
        {
            int r = p + 2 * b;
            if (r > n)
                r = n;
            merge(Vet, p, (p + b), r);
            p = p + 2 * b;
        }
        b = 2 * b;
    }
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_heapSort()
{
}

/*----------------------------------------------------------------------------------------------------------------*/

int partition(int Vet[], int inicio, int final)
{
    int pivot = Vet[final]; // pivot
    int i = (inicio - 1);   // i of smaller element

    for (int j = inicio; j <= final - 1; j++)
    {
        // If current element is smaller than the pivot
        if (Vet[j] < pivot)
        {
            i++; // increment i of smaller element
            swap(Vet[i], Vet[j]);
        }
    }
    swap(Vet[i + 1], Vet[final]);
    return (i + 1);
}

void rec_quickSort(int Vet[], int inicio, int final)
{
    if (inicio < final)
    {
        int pi = partition(Vet, inicio, final);
        rec_quickSort(Vet, inicio, pi - 1);
        rec_quickSort(Vet, pi + 1, final);
    }
}

void ite_quickSort(int Vet[], int inicio, int final)
{
    // Create an auxiliary stack
    int stack[final - inicio + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = inicio;
    stack[++top] = final;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        final = stack[top--];
        inicio = stack[top--];

        // Set pivot element at its correct position
        // in sorted Vetay
        int p = partition(Vet, inicio, final);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > inicio)
        {
            stack[++top] = inicio;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < final)
        {
            stack[++top] = p + 1;
            stack[++top] = final;
        }
    }
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
void embaralhar(int Vet[], int n)
{
    // for (int i = 0; i < n; i++)
    // swap(Vet[i], a[rand() % n]);
}

// Ordena o vetor Vet[0..n-1] usando Bogosort
void bogoSort(int Vet[], int n)
{
    // while (!Ordenado(a, n)) // Se o vetor não for ordenado, embaralhe
    // embaralhar(a, n);   // o vetor novemente
}

void show(int Vet[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << Vet[i] << " ";
    }
    cout << "]";
}

int main()
{
    srand(1);
    clock_t t;

    int size = 0;

    cin >> size;

    int vector[size];
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 191 + 10;
        vector[i] = num;
    }

    // show(vector, size);

    t = clock();
    // ite_bubbleSort(vector, size);
    // rec_bubbleSort(vector, size);
    // ite_insertionSort(vector, size);
    // rec_insertionSort(vector, size);
    // ite_selectionSort(vector, size);
    // rec_selectionSort(vector, size);
    // rec_mergeSort(vector, 0, size - 1);
    // ite_mergeSort(vector, size);
    // rec_quickSort(vector, 0, size);
    // ite_quickSort(vector, 0, size);

    t = clock() - t;

    cout << "Tempo = " << ((float)t) / CLOCKS_PER_SEC << endl;

    show(vector, size);

    return 0;
}