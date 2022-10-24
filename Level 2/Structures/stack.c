#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack *init(int i, int *p) {
    struct stack *s = malloc(sizeof(struct stack));
    if (!s) {
        printf("Failed to allocate memory.\n");
        return NULL;
    }
    s->p = p;
    s->tos = p;
    s->bos = p + MAX - 1;
    push(i, s);
    return s;
}

int push(int i, struct stack *s) {
    if (s->p > s->bos) {
        printf("The stack is full.\n");
        return 1;
    }
    *s->p = i;
    s->p++;
    return 0;
}

int pop(struct stack *s) {
    s->p--;
    if (s->p < s->tos) {
        printf("The stack is empty.\n");
        return 0;
    }
    return *s->p;
}

void destroy(struct stack *s) {
    s->p = NULL;
    s->bos = NULL;
    s->tos = NULL;
    free(s);
    s = NULL;
}
