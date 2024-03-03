#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *value;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
    int elements;
} List;

List *init_list() {
    List *l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->elements = 0;
    return l;
}

void add_first(List *l, void *value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = value;
    if (l->head == NULL) {
        l->head = new;
        l->tail = new;
        new->next = NULL;
    } else {
        new->next = l->head;
        l->head = new;
    }
    l->elements++;
}

void add_last(List *l, void *value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = value;
    if (l->head == NULL) {
        l->head = new;
        l->tail = new;
        new->next = NULL;
    } else {
        new->next = NULL;
        l->tail->next = new;
        l->tail = new;
    }
    l->elements++;
}

void add(List *l, void *value, int pos) {
    if (pos < 0 || pos > l->elements) {
        return;
    }

    if (l->elements == 0 || pos == 0) {
        add_first(l, value);
        return;
    }

    if (pos == l->elements) {
        add_last(l, value);
        return;
    }

    Node *new = (Node*)malloc(sizeof(Node));
    new->value = value;
    Node *runner = l->head;

    while (pos != 1) {
        runner = runner->next;
        pos--;
    }
     
    Node *link = runner->next;
    new->next = link;
    runner->next = new;

    l->elements++;
}

void print_list(List *l) {
    Node *runner = l->head;
    while (runner) {
        int *t = (int *)runner->value;
        printf("%i\n", *t);
        runner = runner->next;
    }
}

void remove_first(List *l) {
    if (l->elements == 0) {
        return;
    }
    if (l->elements == 1) {
        Node *temp = l->head;
        l->head = NULL;
        l->tail = NULL;
        free(temp);
        l->elements--;
        return;
    }
    Node *temp = l->head;
    l->head = l->head->next;
    free(temp);
    l->elements--;
    return;
}

void remove_last(List *l) {
    if (l->elements == 0) {
        return;
    }
    if (l->elements == 1) {
        Node *temp = l->head;
        l->head = NULL;
        l->tail = NULL;
        free(temp);
        l->elements--;
        return;
    }

    Node *runner = l->head;
    while(runner->next != l->tail && runner->next != NULL) {
        runner = runner->next;
    }
    Node *temp = l->tail;
    l->tail = runner;
    l->tail->next = NULL;
    free(temp);
    l->elements--;
    return;
}

int search(List *l, void *value) {
    if (l->elements == 0) {
        return -1;
    }
    
    int index = 0;
    Node *runner = l->head;
    if (runner->value == value) {
        return index;
    }
    while (runner->value != value && runner->next != NULL) {
        runner = runner->next;
        index++;
    }
    if (runner->value == value) {
        return index;
    }
    return -1;
}

int main(void) {
    List* l = init_list();
    int a = 1;
    int b = 2;
    int c = 3;

    add_first(l, &a);
    add_last(l, &b);
    add(l, &c, 2);
    printf("%i\n",search(l, &c));
    print_list(l);
}
