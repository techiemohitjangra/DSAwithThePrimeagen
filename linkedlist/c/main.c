#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("LinkedList Initialized!\n");
    int choice = 0, val, pos, result;
    struct LinkedList *list = LinkedList(NULL, NULL);
    while (1) {
        printf("Menu:\n");
        printf("1. Insert Item at index\n");
        printf("2. Delete Item at index\n");
        printf("3. Push Item at front\n");
        printf("4. Pop Item from front\n");
        printf("5. Push Item at end\n");
        printf("6. Pop Item from end\n");
        printf("7. Find item\n");
        printf("8. Get Item at specific position\n");
        printf("9. Get First Item\n");
        printf("10. Get Last Item\n");
        printf("11. Print List\n");
        printf("12. Print List in Reverse Order\n");
        printf("13. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter position to insert at: ");
            scanf("%d", &pos);
            result = insert(list, val, pos);
            printf("%s", (result > 0 ? "Item inserted\n" : "Failed to insert item\n"));
            break;

        case 2:
            printf("Enter position to delete from: ");
            scanf("%d", &pos);
            result = deleteNode(list, pos);
            printf("%s", (result > 0 ? "Item deleted\n" : "Failed to delete item\n"));
            break;

        case 3:
            printf("Enter the value to insert at the front: ");
            scanf("%d", &val);
            result = pushHead(list, val);
            printf("%s",
                   (result > 0 ? "Item inserted at first position\n" : "Failed to insert item at the first place\n"));
            break;

        case 4:
            result = popHead(list);
            printf("%s", (result > 0 ? "First item Deleted\n" : "Failed to delete first item\n"));
            break;

        case 5:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &val);
            result = pushTail(list, val);
            printf("%s", (result > 0 ? "Item inserted at the end\n" : "Failed to insert item at the end\n"));
            break;

        case 6:
            result = popTail(list);
            printf("%s", (result > 0 ? "Last item Deleted\n" : "Failed to delete last item\n"));
            break;

        case 7:
            printf("Enter the value to search: ");
            scanf("%d", &val);
            result = find(list, val);
            (result > 0 ? (printf("Item found at index %d\n", result)) : (printf("Item not found\n")));
            break;

        case 8:
            printf("Enter index to get value at that index: ");
            scanf("%d", &pos);
            val = at(list, pos);
            printf("Value at index %d is: %d\n", pos, val);
            break;

        case 9:
            val = getHead(list);
            (val ? printf("Frist item in the list is: %d\n", val) : printf("List is empty.\n"));
            break;

        case 10:
            val = getTail(list);
            (val ? printf("Last item in the list is: %d\n", val) : printf("List is empty.\n"));
            break;

        case 11:
            print(list);
            break;
        case 12:
            printReverse(list);
            break;
        case 13:
            exit(0);
            break;
        default:
            break;
        }
    }
}

int main() {

    menu();

    return 0;
}
