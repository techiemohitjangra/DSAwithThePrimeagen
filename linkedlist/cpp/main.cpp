#include "linkedlist.hpp"
#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("LinkedList Initialized!\n");
    int choice = 0, val, pos, result;
    LinkedList list = LinkedList();
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
        printf("12. Reverse List\n");
        printf("13. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter position to insert at: ");
            scanf("%d", &pos);
            list.insert(pos, val);
            printf("Item inserted\n\n");
            break;

        case 2:
            printf("Enter position to delete from: ");
            scanf("%d", &pos);
            result = list.deleteNode(pos);
            printf("Item deleted: %d\n\n", result);
            break;

        case 3:
            printf("Enter the value to insert at the front: ");
            scanf("%d", &val);
            list.push_front(val);
            printf("Item inserted at first position\n\n");
            break;

        case 4:
            result = list.pop_front();
            printf("First item Deleted: %d\n\n", result);
            break;

        case 5:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &val);
            list.push_back(val);
            printf("Item inserted at the end\n\n");
            break;

        case 6:
            result = list.pop_back();
            printf("Last item Deleted: %d\n\n", result);
            break;

        case 7:
            printf("Enter the value to search: ");
            scanf("%d", &val);
            result = list.find(val);
            printf("Item found at index %d\n\n", result);
            break;

        case 8:
            printf("Enter index to get value at that index: ");
            scanf("%d", &pos);
            val = list.at(pos);
            printf("Value at index %d is: %d\n\n", pos, val);
            break;

        case 9:
            val = list.getHead()->getValue();
            printf("Frist item in the list is: %d\n\n", val);
            break;

        case 10:
            val = list.getTail()->getValue();
            printf("Last item in the list is: %d\n\n", val);
            break;

        case 11:
            list.print();
            break;
        case 12:
            list.reverse();
            break;
        case 13:
            printf("Exiting....\n");
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
