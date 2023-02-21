/* input interi da tastiera e creare la lista dnamica con gli n interi 
stampare i numeri crescente e decrescente */
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int data;
    struct nodo* next;
};

typedef struct nodo nodo;

nodo* inserisci(nodo* head, nodo* p) {
    p->next = head;
    head = p;
}

void stampacrescente(nodo* head) {
    nodo* p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void main(void) {
    nodo * head = NULL;

    puts("y/n ?");
    char d = 'n';
    scanf("%c", &d);

    while (d == 'y')
    {
        nodo * p = (nodo*)malloc(sizeof(nodo));
        puts("intero");
        int i;
        scanf("%d", &i);
        p->data = i;
        head = inserisci(head, p);
        puts("y/n ?");
        scanf(" %c", &d);
    }

    stampacrescente(head);
}