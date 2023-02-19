#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
  char data[2];
  struct nodo* next;
};

typedef struct nodo Nodo;

Nodo* inserisci(Nodo* head, Nodo* p)
{
  if(head == NULL)
  {
    p->next = head;
    head = p;
  }
  else
  {
    p->next = head;
    head = p;
  }
  
  return head;
}

Nodo* ripulisci(Nodo* head)
{
  Nodo* prec = head;
  Nodo* succ;
  
  while(prec != NULL)
  {
    if((prec->next != NULL) && (strcmp(prec->data, prec->next->data) == 0))
    {
      succ = prec->next;
      prec->next = succ->next;
      free(succ);
    }
    else prec = prec->next;
  }
  
  return head;
}

int main() {
  
  Nodo* head = NULL;
  
  for(int i = 0; i < 3; i++)
  {
    Nodo* p = (Nodo*)malloc(sizeof(Nodo));
    char out[] = "ciao";
    strncpy(p->data, out, 2);
    head = inserisci(head, p);
  }
  
  Nodo* p = (Nodo*)malloc(sizeof(Nodo));
  char out[] = "hello";
  strncpy(p->data, out, 2);
  head = inserisci(head, p);
  
  head = ripulisci(head);
  
  return 0;
}
