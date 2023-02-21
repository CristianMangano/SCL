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
    int temp;
    for (nodo* prec = head; prec != NULL; prec = prec->next)
    {
        for (nodo* succ = prec->next; succ != NULL; succ = succ->next)
        {
            if ((succ != NULL) && (prec->data > succ->data))
            {
                temp = prec->data;
                prec->data = succ->data;
                succ->data = temp;
            }
        }
    }
    puts("stampa ordinata...");
    nodo* q = head;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
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
