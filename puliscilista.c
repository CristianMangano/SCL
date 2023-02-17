/* Scrivere un programma che prende stringhe come parametri di input,
inserisce le stringhe in una lista ordinata e poi richiama una funzione
che elimina i duplicati e ritorna il puntatore alla lista così ripulita */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo
{
    char nome[30];
    struct Nodo* next;
};

struct Nodo* inserisci(struct Nodo* head, struct Nodo* p) {
    if (head == NULL)
    {
        p->next = head;
        head = p;
    }
    else
    {
        struct Nodo* q = head;
        struct Nodo* r = head;
        while (q != NULL)
        {
            r = q;
            q = q->next;
        }
        r->next = p;
        p->next = q;
    }
    return head;
}

void stampa(struct Nodo* head) {
    struct Nodo* q = head;
    while (q != NULL)
    {
        puts(q->nome);
        q = q->next;
    }
}

struct Nodo* pulisciLista(struct Nodo* head) {
    struct Nodo* t = head;
    struct Nodo* r;
    while (t != NULL)
    {
        if((strcmp(t->nome, t->next->nome) == 0) && (t->next != NULL))
        {
            r = t->next;
            t->next = r->next;
            free(r);
        }
        else t = t->next;
    }
    return head;
}

/*struct Nodo* pulisciLista(struct Nodo* head) {
    struct Nodo* t = head;
    struct Nodo* r = head;
    while (t != NULL)
    {
        t = t->next;
        if((strcmp(r->nome, t->nome) == 0) && (t != NULL))
        {
            r->next = t->next;
            free(t);
            t = r;
        }
        else r = t;
    }
    return head;
}*/

void main(void) {
    struct Nodo* head = NULL;
    
    for (int i = 0; i < 3; i++)
    {
        struct Nodo* p = (struct Nodo*)malloc(sizeof(struct Nodo));
        // puts("iserisci un testo");
        char message[] = "inserisci un testo";
        puts(message);
        char input[30];
        gets(input);
        strncpy(p->nome, input, 30);
        head = inserisci(head, p);
    }
    stampa(head);
    head = pulisciLista(head);
    stampa(head);
}
