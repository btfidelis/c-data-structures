#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct Arvore
{
    int valor;
    struct Arvore* esq;
    struct Arvore* dir;
}arv;

typedef struct ListaAleatoria
{
    int valor;
    struct ListaAleatoria* prox;
}random_list;

arv* new_arv(int valor);
void inserir(arv* a, arv** raiz);
void erd_arv(arv* raiz);
random_list* gerar_lista_aleatoria(int n, random_list** r);
random_list* new_random(int n);
void inserir_lista(random_list** init, random_list* element);
void print_list(random_list* init);
int valor_aleatorio(int n);

int main()
{
    arv* r = new_arv(5);
    random_list* lista_aleatoria = NULL;

    inserir(new_arv(2), &r);
    inserir(new_arv(7), &r);
    inserir(new_arv(100), &r);
    inserir(new_arv(50), &r);
    inserir(new_arv(3), &r);

    erd_arv(r);
    printf("\n");

    gerar_lista_aleatoria(150, &lista_aleatoria);
    print_list(lista_aleatoria);
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


void edr_arv(arv* raiz)
{
    if (!raiz) {
        return;
    } else {
        edr_arv(raiz->esq);
        printf("%d", raiz->valor);
        edr_arv(raiz->dir);
    }
}

random_list* gerar_lista_aleatoria(int n, random_list** l)
{
    int i;

    for(i = 0; i < n; i++)
    {
        inserir_lista(l, new_random(valor_aleatorio(n)));
    }
}

int valor_aleatorio(int n)
{
    int b = RAND_MAX / n;
    int limite = b * n;
    int r;

    do
    {
        r = rand();
    }
    while(r >= limite);

    return r / b;
}

random_list* new_random(int n)
{
    random_list* novo = (random_list*) malloc(sizeof(random_list));
    novo->valor = n;
    novo->prox = NULL;

    return novo;
}

void inserir_lista(random_list** init, random_list* element)
{
    random_list* it = *init;

    if (!(*init)) {
        *init = element;
    } else {
        while(it->prox) {
            it = it->prox;
        }
        it->prox = element;
    }
}

void print_list(random_list* init)
{
    random_list* it = init;

    while(it) {
        printf("| id: %d | -> ", it->valor);
        it = it->prox;
    }
}
// @todo red, nivel da arv, se é folha
