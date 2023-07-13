#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
  return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
{
  Arv* p=(Arv*)malloc(sizeof(Arv));
  p->info = c;
  p->esq = sae;
  p->dir = sad;
  return p;
}

int vazia(Arv* a)
{
  return a==NULL;
}

Arv* libera (Arv* a){
  if (!vazia(a)){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}

void imprime_pre (Arv* a)
{
  if (!vazia(a)){
  printf("%d ", a->info);
  imprime_pre(a->esq);
  imprime_pre(a->dir);
  }
}

void imprime_in (Arv* a)
{
  if (!vazia(a)){
  imprime_in(a->esq);
  printf("%d ", a->info);
  imprime_in(a->dir);
  }
}

void imprime_pos (Arv* a)
{
  if (!vazia(a)){
  imprime_pos(a->esq);
  imprime_pos(a->dir);
  printf("%d ", a->info);
  }
}

int main()
{
	Arv* a;
  a = inicializa();
  a = cria(45, cria(5,cria(12,inicializa(),inicializa()),cria(34,inicializa(),cria(67,inicializa(),inicializa()))), cria(80,inicializa(),cria(40,inicializa(),inicializa())));
  imprime_pre(a);
  imprime_in(a);
  imprime_pos(a);
  a->dir->esq = cria(3,cria(66,inicializa(),inicializa()),cria(31,inicializa(),inicializa()));
  printf("\n");
  imprime_pre(a);
  imprime_in(a);
  imprime_pos(a);
  a->esq->dir->dir = libera(a->esq->dir->dir);
  printf("\n");
  imprime_pre(a);
  imprime_in(a);
  imprime_pos(a);
  libera(a);
}
