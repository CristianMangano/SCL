/* Una lista di studenti ordinata */

#include <stdio.h>
#include <stdlib.h>

struct nodo
{
  int data;
  struct nodo* next;
};

typedef struct nodo Nodo;

Nodo* inserisci(Nodo* head, Nodo* p)
{
  Nodo* prec = head;
  Nodo* succ = head;
  while((succ != NULL) && (p->data > succ->data))
  {
    prec = succ;
    succ = succ->next;
  }
  
  if ((prec != succ) && succ != NULL)
  {
    prec->next = p;
    p->next = succ;
  }
  else if ((prec != succ) && (succ == NULL))
  {
    p->next = succ;
    prec->next = p;
  }
  else if(prec == succ)
  {
    head = p;
    p->next = prec;
  }
  
  return head;
}

int main() {
  
  Nodo* head = NULL;
  
  for(int i = 0; i < 3; i++)
  {
    Nodo* p = (Nodo*)malloc(sizeof(Nodo));
    int matricola = 10 - i;
    p->data = matricola;
    head = inserisci(head, p);
  } 

  return 0;
}
