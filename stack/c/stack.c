#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constructors
struct Node *Node(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

struct Stack *Stack() {
    struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

void push(struct Stack *stack, int value) {
    struct Node *newNode = Node(value);
    if (stack->size == 0) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
    stack->size++;
}

void pop(struct Stack *stack) {
    if (stack->size == 0)
        return;
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

int peek(struct Stack *stack) {
    if (stack->size == 0)
        return 0;
    else
        return stack->top->value;
}

int size(struct Stack *stack) { return stack->size; }

void print(struct Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = stack->top;
    printf("TOP[");
    while (temp->next != NULL) {
        printf("%d-> ", temp->value);
        temp = temp->next;
    }
    printf("%d-> NULL\n", temp->value);
}
