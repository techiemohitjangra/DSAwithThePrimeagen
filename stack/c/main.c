#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
    int choice = 0, value, result;
    struct Stack *top = Stack();
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    printf("Stack Initialized!\n");
    while (1) {
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Size\n");
        printf("5. Print\n");
        printf("6. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(stack, value);
                printf("%d inserted into the stack\n\n", value);
                break;

            case 2:
                pop(stack);
                printf("Item poped from the stack\n\n");
                break;

            case 3:
                result = peek(stack);
                printf("%d is at the top of the stack\n\n", result);
                break;

            case 4:
                result = size(stack);
                printf("Size of the stack is:%d\n\n", result);
                break;

            case 5:
                print(stack);
                break;

            default:
                fprintf(stderr, "Invalid choice!\n\n");
                break;
        }
    }
}

int main() {
    menu();

    return 0;
}
