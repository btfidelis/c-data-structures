#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int id;
    struct List* next;
}list;

void enqueue(list** init, list* element);
list* dequeue(list** init);
void print_list(list* init);
list* new_element(int id);

int main()
{
    list* init = NULL;

    enqueue(&init, new_element(21));
    enqueue(&init, new_element(39));
    enqueue(&init, new_element(7));
    enqueue(&init, new_element(90));

    print_list(init);

    list* removed = dequeue(&init);
    printf("\nREMOVED ELEMENT: %d", removed->id);
    free(removed);

    removed = dequeue(&init);
    printf("\nREMOVED ELEMENT: %d", removed->id);
    free(removed);

    return 0;
}

void enqueue(list** init, list* element)
{
    list* it = *init;

    if (!(*init)) {
        *init = element;
    } else {
        while(it->next) {
            it = it->next;
        }
        it->next = element;
    }
}

void print_list(list* init)
{
    list* it = init;

    while(it) {
        printf("| id: %d | -> ", it->id);
        it = it->next;
    }
}

list* new_element(int id)
{
    list* new_list = (list*) malloc(sizeof(list));
    new_list->id = id;
    new_list->next = NULL;

    return new_list;
}

list* dequeue(list** init)
{
    if (*init) {
        list* aux = *init;
        *init = aux->next;
        return aux;
    }

    return *init;
}
