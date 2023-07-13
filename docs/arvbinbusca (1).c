#include <stdio.h>
#include <stdlib.h>

struct arv
{
  int info;
  struct arv *esq;
  struct arv *dir;
};

typedef struct arv Arv;

Arv *busca(Arv *r, int v)
{
  if (r == NULL)
    return NULL;
  else if (r->info > v)
    return busca(r->esq, v);
  else if (r->info < v)
    return busca(r->dir, v);
  else
    return r;
}

Arv *insere(Arv *a, int v)
{
  if (a == NULL)
  {
    a = (Arv *)malloc(sizeof(Arv));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info)
    a->esq = insere(a->esq, v);
  else /* v < a->info */
    a->dir = insere(a->dir, v);
  return a;
}

Arv *libera(Arv *a)
{
  if (!vazia(a))
  {
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a);        /* libera raiz */
  }
  return NULL;
}

void imprime_in(Arv *r)
{
  if (!vazia(r))
  {
    printf("%d ", r->info);
    imprime_in(r->esq);
    printf("%d ", r->info);
    imprime_in(r->dir);
  }
}

int vazia(Arv *a)
{
  return a = NULL;
}

void main(void)
{
  Arv *a;
  insere(a, 1);
  imprime_in(a);
  insere(a, 2);
  imprime_in(a);
  insere(a, 3);
  imprime_in(a);
  insere(a, 5);
  imprime_in(a);
  insere(a, 15);
  imprime_in(a);
  insere(a, 7);
  imprime_in(a);
  if (busca(a, 2))
  {
    printf("O elemento 2 foi encontrado");
  }
  if (busca(a, 8))
  {
    printf("O elemento 8 foi encontrado");
  }
  libera(a);
}
