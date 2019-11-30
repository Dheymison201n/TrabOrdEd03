#include <iostream>
#include <limits.h>

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

void remove(No *ref)
{
    ref->prev->next = ref->next;
    ref->next->prev = ref->prev;
    delete ref;
}

void ite_bubble(No *start)
{
    int swapped, i;
    struct No *ptr1;
    struct No *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
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

void rec_bubbleSortList()
{
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_insertionSortList()
{
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_selectionSortList()
{
}

/*----------------------------------------------------------------------------------------------------------------*/

void merge()
{
}

void rec_mergeSortList()
{
}

/*----------------------------------------------------------------------------------------------------------------*/

void ite_heapSortList()
{
}

/*----------------------------------------------------------------------------------------------------------------*/

void rec_quickSortList()
{
}

/*----------------------------------------------------------------------------------------------------------------*/

bool Ordenado()
{
}

// Gerando permutação do vetor
void embaralhar()
{
}

// Ordena o vetor Vet[0..n-1] usando Bogosort
void bogoSortList()
{
}