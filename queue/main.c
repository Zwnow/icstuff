#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* value;
    struct node* next;
} Node;

typedef struct queue {
    Node* first;
    Node* last;
    size_t size;
} Queue;

Queue* init() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        exit(1);
    }
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, void* value) {
    Node *new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        exit(1);
    }
    new->value = value;
    new->next = NULL;
    if (q->first == NULL) {
        q->first = new;
        q->last = new;
    } else {
        q->last->next = new;
        q->last = new;
    }
    q->size++;
    return;
}

void* dequeue(Queue* q) {
    if (q->size == 0) {
        return NULL;
    }

    Node* first = q->first;
    void* val = q->first->value;
    q->first = q->first->next;

    free(first);

    if (q->first == NULL) {
        q->last = NULL;
    }
    q->size--;
    return val;
}

int main(void) {
    Queue* q = init();
    int a = 1;
    int b = 2;
    int c = 3;
    enqueue(q, &a);
    enqueue(q, &b);
    enqueue(q, &c);

    int* result = (int *)dequeue(q);
    while(result != NULL) {
        printf("%i\n", *result);
        result = (int *)dequeue(q);
    }
}
