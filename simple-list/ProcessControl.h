typedef struct ProcessControl
{
    struct Process* initial;
    struct Process* end_p;
    int many;

}p_control;


p_control* new_process_control_block()
{
    p_control* p = (p_control*) malloc(sizeof(p_control));

    p->initial = NULL;
    p->end_p = NULL;
    p->many = 0;

    return p;
}


