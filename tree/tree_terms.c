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
void print_degree(arv* raiz);
void get_node_level(arv* node, int level);
int get_node_degree(arv* node);

int main()
{
    arv* r = new_arv(23);
    inserir(new_arv(12), &r);
    inserir(new_arv(5), &r);
    inserir(new_arv(54), &r);
    inserir(new_arv(7), &r);
    inserir(new_arv(1), &r);
    inserir(new_arv(56), &r);

    printf("\nNode's degree:\n");
    print_degree(r);

    printf("\nNode's level:\n");
    get_node_level(r, 0);

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

void print_degree(arv* raiz)
{
    if (raiz) {
        printf("Node %d, has a degree of: %d\n", raiz->valor, get_node_degree(raiz));
        print_degree(raiz->esq);
        print_degree(raiz->dir);
    }
}

int get_node_degree(arv* node)
{
    int degree = 0;

    if (node->dir) degree++;
    if (node->esq) degree++;

    return degree;
}

void get_node_level(arv* node, int level)
{
    if (node) {
        get_node_level(node->esq, level+1);
        printf("\nNode %d, has a level of: %d", node->valor, level);
        get_node_level(node->dir, level+1);
    }
}














