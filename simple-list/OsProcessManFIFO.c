#include<stdio.h>
#include<stdlib.h>
#include "ProcessControl.h"
#include "../util.h"

typedef struct Process
{
    char* name;
    int   cpu_cycles;

    struct Process* next;
}process;

process* new_process(char* name, int cpu_cycles);
void print_processes(process* init);
void execute(process* p);

int main()
{
    p_control* processControlBlock = new_process_control_block();
    process* curr;

    curr = new_process("process-1", 12);
    processControlBlock->initial = curr;
    processControlBlock->many++;

    curr->next = new_process("process-2", 5);
    curr = curr->next;

    processControlBlock->end_p = curr;
    processControlBlock->many++;

    curr->next = new_process("process-3", 16);
    curr = curr->next;

    processControlBlock->end_p = curr;
    processControlBlock->many++;

    curr->next = new_process("process-4", 3);
    curr = curr->next;

    processControlBlock->end_p = curr;
    processControlBlock->many++;


    print_processes(processControlBlock->initial);
    clear_screen();

    printf("%d PROCESSES ON QUEUE \n", processControlBlock->many);
    curr = processControlBlock->initial;

    while(curr) {

        execute(curr);
        printf("\n");

        curr = curr->next;
    }



    return 0;
}

process* new_process(char* name, int cpu_cycles)
{
    process* ps = (process*) malloc(sizeof(process));

    ps->name = name;
    ps->cpu_cycles = cpu_cycles;

    ps->next = NULL;
}

void print_processes(process* init)
{
    process* it = init;

    while(it) {
        printf("process name: %s \n", it->name);
        printf("process cycles: %d \n", it->cpu_cycles);

        it = it->next;
    }
}

void execute(struct Process* p)
{
    int i;

    printf("Executing %s\n", p->name);

    for (i = 0; i < p->cpu_cycles * 100; i++) {
        printf(".");
    }

    printf("\n");
}
