#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *value;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    size_t size;
} Stack;

Stack *init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack *s, void *value) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = value;
    new->next = s->top;
    s->top = new;
    s->size++;
}

void *pop(Stack *s) {
    if (s->size == 0) {
        return NULL;
    }
    void *top = s->top;
    void *value = s->top->value;
    s->top = s->top->next;
    free(top);
    s->size--;
    return value;
}

int main(void) {
    Stack* s = init();
    int a = 1;
    int b = 2;
    int c = 3;
    printf("Pushing 1\n");
    push(s, &a);
    printf("Pushing 2\n");
    push(s, &b);
    printf("Pushing 3\n");
    push(s, &c);
    int *result = (int *)pop(s);
    while(result != NULL) {
        printf("%i\n", *result);
        result = (int *)pop(s);
    }
}
