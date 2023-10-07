#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct LinkedList *LinkedList(struct Node *head, struct Node *tail) {
    struct LinkedList *newList = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if (head == NULL || tail == NULL) {
        newList->head = NULL;
        newList->tail = NULL;
        newList->length = 0;
    } else {
        newList->head = head;
        newList->tail = tail;

        int length = 1;
        struct Node *temp = head;
        while (temp != tail) {
            temp = temp->next;
            length++;
        }
        newList->length = length;
    }

    return newList;
}

struct Node *Node(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void print(struct LinkedList *list) {
    if (list->length == 0) {
        printf("Empty List!");
    } else {
        struct Node *temp = list->head;
        printf("[");
        while (temp->next != NULL) {
            printf("%d, ", temp->val);
            temp = temp->next;
        }
        printf("%d]", temp->val);
    }
    printf("\n");
}

void printReverse(struct LinkedList *list) {
    if (list->length == 0) {
        printf("Empty List!");
    } else {
        struct Node *temp = list->tail;
        while (temp != NULL) {
            printf("%d ", temp->val);
            temp = temp->prev;
        }
    }
    printf("\n");
}

int pushHead(struct LinkedList *list, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (list->head == NULL && list->tail == NULL) {
        newNode->val = val;
        newNode->prev = NULL;
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->val = val;
        newNode->prev = NULL;
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->length++;
    return 1;
}

int popHead(struct LinkedList *list) {
    if (list->length == 0) {
        fprintf(stderr, "Err: Cannot remove element. List is empty!\n");
        return -1;
    } else if (list->length == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        struct Node *temp = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
    }

    list->length--;
    return 1;
}

int pushTail(struct LinkedList *list, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (list->tail == NULL && list->head == NULL) {
        newNode->val = val;
        newNode->prev = NULL;
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->val = val;
        newNode->next = NULL;
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
    return 1;
}

int popTail(struct LinkedList *list) {
    if (list->length == 0) {
        fprintf(stderr, "Err: Cannot remove element. List is empty!\n");
        return -1;
    } else if (list->length == 1) {
        free(list->tail);
        list->tail = NULL;
        list->head = NULL;
    } else {
        struct Node *temp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
    }
    list->length--;
    return 1;
}

int insert(struct LinkedList *list, int val, int pos) {
    if (list == NULL) {
        fprintf(stderr, "Err: List does not exist.");
        return -1;
    }
    if (abs(pos) > list->length) {
        fprintf(stderr, "Err: Position out of range.");
        return -1;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (pos == 0) {
        pushHead(list, val);
    } else if (pos == -1 || pos == list->length - 1) {
        pushTail(list, val);
    } else if (pos < 0) {
        int curr = -1;
        struct Node *temp = list->tail;
        while (curr != pos) {
            temp = temp->prev;
            curr--;
        }
        newNode->val = val;
        newNode->prev = temp;
        newNode->next = temp->next;

        temp->next->prev = newNode;
        temp->next = newNode;

        list->length++;
    } else {
        int curr = 0;
        struct Node *temp = list->head;
        while (curr != pos) {
            temp = temp->next;
            curr++;
        }
        newNode->val = val;
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;

        list->length++;
    }
    return 1;
}

int deleteNode(struct LinkedList *list, int pos) {
    if (list->head == NULL && list->tail == NULL) {
        fprintf(stderr, "Err: List does not exist.");
        return -1;
    } else if (pos >= list->length) {
        fprintf(stderr, "Err: Position out of range.");
        return -1;
    } else if (list->length == 0) {
        fprintf(stderr, "Err: List is empty");
        return -1;
    }
    if (pos == 0) {
        popHead(list);
    } else if (pos == list->length - 1 || pos == -1) {
        popTail(list);
    } else if (pos > 0) {
        int curr = 1;
        struct Node *temp = list->head->next;
        while (pos != curr) {
            temp = temp->next;
            curr++;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    } else if (pos < 0) {
        int curr = -2;
        struct Node *temp = list->tail->prev;
        while (pos != curr) {
            temp = temp->prev;
            curr--;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return 1;
}

int getHead(struct LinkedList *list) {
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return -1;
    } else if (list->length == 0) {
        fprintf(stderr, "List is empty.\n");
        return -1;
    }
    return list->head->val;
}

int getTail(struct LinkedList *list) {
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return -1;
    } else if (list->length == 0) {
        fprintf(stderr, "List is empty.\n");
        return -1;
    }
    return list->tail->val;
}

int at(struct LinkedList *list, int pos) {
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return -1;
    } else if (list->length == 0) {
        fprintf(stderr, "List is empty.\n");
        return -1;
    } else if (pos >= list->length) {
        fprintf(stderr, "Index out of range.\n");
    }
    int curr = 0;
    struct Node *temp = list->head;
    while (curr != pos) {
        temp = temp->next;
        curr++;
    }
    return temp->val;
}

int find(struct LinkedList *list, int val) {
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return -1;
    } else if (list->length == 0) {
        fprintf(stderr, "List is empty.\n");
        return -1;
    }
    struct Node *temp = list->head;
    int curr = 0;
    while (temp != NULL) {
        if (temp->val == val) {
            break;
        }
        temp = temp->next;
        curr++;
    }

    if (curr < list->length) {
        return curr;
    }

    return -1;
}
