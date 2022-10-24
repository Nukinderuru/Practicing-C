#ifndef STACK_H
#define STACK_H

#define MAX 5

struct stack {
    int *p;
    int *tos;
    int *bos;
};
struct stack *init(int i, int *p);
int push(int i, struct stack *s);
int pop(struct stack *s);
void destroy(struct stack *s);

#endif