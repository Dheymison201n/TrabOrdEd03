#include <iostream>

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
}

No *search(No *ref, int ini)
{
    No *aux = ref;
    int i = 1;
    do
    {
        if (i == ini)
            return aux;
        aux = aux->next;
        i++;
    } while (aux != ref);
    return aux;
}
