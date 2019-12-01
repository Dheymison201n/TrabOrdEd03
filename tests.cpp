#include <iostream>
#include <time.h> /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h> /* sqrt */
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

struct No
{
    int value;
    No *next;
    No *prev;
    No(int value)
    {
        this->value = value;
        this->next = this;
        this->prev = this;
    }
};

void insert(No *ref, int value)
{
    No *no = new No(value);
    no->next = ref->next;
    no->prev = ref;
    ref->next = no;
    no->next->prev = no;
}

void ite_bubble_vector(int Vet[], int n)
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

void rec_bubble_vector(int Vet[], int n)
{
    // Caso base
    if (n == 1) // se o tamanho do vetor for 1, retorne.
        return;

    for (int i = 0; i < n - 1; i++)
        if (Vet[i] > Vet[i + 1])
            swap(Vet[i], Vet[i + 1]);

    // O maior elemento é fixo,
    // recorrente para o vetor restante
    rec_bubble_vector(Vet, n - 1);
}

void ite_bubble_list(No *start)
{
    int swapped;
    struct No *ptr1;
    struct No *lptr = start;

    if (start == nullptr)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            {
                swap(ptr1->value, ptr1->next->value);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void rec_bubble_list(No *start)
{
    if (start == nullptr || start->next == start)
        return;
}

void show(No *lista)
{
    cout << "[ ";
    No *node = lista;
    do
    {
        cout << lista->value << " ";
        lista = lista->next;
    } while (lista != node);
    cout << "]\n";
}

int main()
{
    srand(1);
    clock_t t;
    int size = 10;
    No *lista = nullptr;

    for (int i = 0; i < size; i++)
    {
        int num = rand() % 191 + 10;
        if (lista == nullptr)
        {
            lista = new No(num);
        }
        else
        {
            insert(lista->prev, num);
        }
    }

    show(lista);

    t = clock();
    ite_bubble_list(lista);
    t = clock() - t;

    cout << "ite = " << ((float)t) / CLOCKS_PER_SEC << endl;

    show(lista);

    return 0;
}