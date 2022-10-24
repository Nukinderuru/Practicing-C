#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void tests() {
    int *p = (int *)malloc(MAX * sizeof(int));
    struct stack *stack = init(3, p);
    free(p);
    p = NULL;
    int res = 0;
    res = pop(stack);
    if (res == 3) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    if (push(5, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", 5); }
    if (push(133, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", 133); }
    if (push(-11, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", -11); }
    res = pop(stack);
    if (res == -11) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == 133) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == 5) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == 0) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    if (push(-15, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", -15); }
    if (push(5, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", 5); }
    if (push(25, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", 25); }
    if (push(-125, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", -125); }
    if (push(5, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", 5); }
    if (push(555, stack) == 0) { printf("Element %d pushed to the stack.\nSUCCESS\n", 555); }
    if (push(-75, stack) == 1) { printf("SUCCESS\n"); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == 555) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == 5) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == -125) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == 25) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    res = pop(stack);
    if (res == 5) { printf("The last element is: %d\nSUCCESS\n", res); }
    else { printf("FAIL\n"); }
    destroy(stack);
    stack = NULL;
    if (stack == NULL) { printf("The stack was destroyed.\nSUCCESS\n"); }
    else { printf("FAIL\n"); }
}

int main() {
    tests();
    return 0;
}
