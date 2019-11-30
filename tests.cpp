#include <iostream>
#include <time.h> /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h> /* sqrt */
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    srand(1);
    clock_t t;
    int size = 20000;
    int vector[size];
    int vector2[size];

    for (int i = 0; i < size; i++)
    {
        int num = rand() % 191 + 10;
        vector[i] = num;
        vector2[i] = num;
    }

    // Dheymison
    t = clock();
    rec_bubbleSort(vector, size);
    t = clock() - t;

    cout << "rec = " << ((float)t) / CLOCKS_PER_SEC << endl;

    t = clock();
    ite_bubbleSort(vector2, size);
    t = clock() - t;

    cout << "ite = " << ((float)t) / CLOCKS_PER_SEC << endl;
    return 0;
}