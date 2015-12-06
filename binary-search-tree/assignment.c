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
random_list* ordenar_lista(random_list** init_rand, arv** raiz);
void free_list(random_list** init);
random_list* dequeue(random_list** init);
void lista_para_arvore(random_list* init, arv** raiz);
void print_list(random_list* init);
int valor_aleatorio(int n);

int main()
{
    arv* r = NULL;
    random_list* lista_aleatoria = NULL;
    random_list* ord_list = NULL;
    gerar_lista_aleatoria(150, &lista_aleatoria);

    //lista_para_arvore(lista_aleatoria, &r);
    ord_list = ordenar_lista(&lista_aleatoria, &r);
    print_list(ord_list);

    //free_list(&lista_aleatoria);

    //erd_arv(r);
    printf("\n");

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

void arv_para_lista(arv* raiz, random_list** init)
{
    if (raiz != NULL) {
        arv_para_lista(raiz->esq, init);
        inserir_lista(init, new_random(raiz->valor));
        arv_para_lista(raiz->dir, init);
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

void lista_para_arvore(random_list* init, arv** raiz)
{
    random_list* it = init;

    while(it)
    {
        inserir(new_arv(it->valor), raiz);
        it = it->prox;
    }
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

random_list* dequeue(random_list** init)
{
    if (*init)
    {
        random_list* aux = *init;
        *init = aux->prox;
        return aux;
    }
}

random_list* ordenar_lista(random_list** init_rand, arv** raiz)
{
    random_list* ordenada = NULL;
    lista_para_arvore(*init_rand, raiz);

    // libera area de memória da lista aleatória
    free_list(init_rand);

    arv_para_lista(*raiz, &ordenada);

    return ordenada;
}

void free_list(random_list** init)
{
    while(*init)
    {
        free(dequeue(init));
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
