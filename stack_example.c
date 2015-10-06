#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int id;
    struct Stack* prox;
}stack;

stack* pop(stack** init);
void push(stack** init, stack* element);
stack* new_element(int id);
void print_elements(stack* init);

int main()
{
    stack* init = NULL;
    stack* removed = NULL;

    // In a stack you must insert on one side of the list....
    push(&init, new_element(20));
    push(&init, new_element(10));
    push(&init, new_element(46));
    push(&init, new_element(87));

    print_elements(init);

    printf("------------------\n");

    // ...and pop from the same side you inserted, returning the element
    removed = pop(&init);
    print_elements(init);
    printf("\nRemoved element: %d", removed->id);

    return 0;
}

stack* new_element(int id)
{
    stack* element = (stack*) malloc(sizeof(stack));
    element->id = id;
    element->prox = NULL;

    return element;
}

void print_elements(stack* init)
{
    stack* it = init;

    while(it) {
        printf(" ----\n");
        printf("| %d |\n", it->id);
        printf(" ----\n");
        it = it->prox;
    }
}

void push(stack** init, stack* element)
{
    if (!(*init)) {
        *init = element;
    } else {
        stack* aux = *init;
        *init = element;
        element->prox = aux;
    }
}

stack* pop(stack** init)
{
    stack* aux = *init;
    *init = aux->prox;
    aux->prox = NULL;

    return aux;
}
