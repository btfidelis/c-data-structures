#include<stdlib.h>
#include<stdio.h>

// Binary Tree
typedef struct Arvore
{
    int valor;
    struct Arvore* esq;
    struct Arvore* dir;
}arv;

arv* new_arv(int valor);
void inserir(arv* a, arv** raiz);
void erd_arv(arv* raiz);

int main()
{
    arv* r = new_arv(5);
    inserir(new_arv(2), &r);
    inserir(new_arv(7), &r);
    inserir(new_arv(100), &r);
    inserir(new_arv(50), &r);
    inserir(new_arv(3), &r);

    printf("-- In-order: first left then center then right -- \n");
    erd_arv(r);

    printf("\n-- Post-order: first left then right then center -- \n");
    edr_arv(r);

    printf("\n-- Pre-order: first center then left then right -- \n");
    red_arv(r);

    return 0;
}

arv* new_arv(int valor)
{
    arv* a = (arv*) malloc(sizeof(arv));
    a->valor = valor;
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

void inserir(arv* a, arv** raiz)
{
    if (!(*raiz)) {
        *raiz = a;
        return;
    } else {
        if ((*raiz)->valor <= a->valor) {
            inserir(a, &(*raiz)->dir);
        } else {
            inserir(a, &(*raiz)->esq);
        }
    }
}

void erd_arv(arv* raiz)
{
    if (raiz != NULL) {
        erd_arv(raiz->esq);
        printf("%d, ", raiz->valor);
        erd_arv(raiz->dir);
    }
}

void red_arv(arv* raiz)
{
    if (raiz != NULL) {
        printf("%d, ", raiz->valor);
        erd_arv(raiz->esq);
        erd_arv(raiz->dir);
    }
}

void edr_arv(arv* raiz)
{
    if (raiz != NULL) {
        edr_arv(raiz->esq);
        edr_arv(raiz->dir);
        printf("%d, ", raiz->valor);
    }
}
