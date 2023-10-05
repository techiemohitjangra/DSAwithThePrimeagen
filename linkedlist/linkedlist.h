// Node
struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
};

// Linkedlist
struct LinkedList {
    struct Node *head;
    struct Node *tail;
    unsigned int length;
};

// constructors
struct Node* Node(int val);
struct LinkedList *LinkedList(struct Node *head, struct Node *tail);

// methods
int insert(struct LinkedList *list, int val, int pos);
int popTail(struct LinkedList *list);
int popHead(struct LinkedList *list);
int deleteNode(struct LinkedList *list, int pos);
int pushTail(struct LinkedList *list, int val);
int pushHead(struct LinkedList *list, int val);
int getTail(struct LinkedList *list);
int getHead(struct LinkedList *list);
int at(struct LinkedList *list, int pos);
int find(struct LinkedList *list, int val);
void print(struct LinkedList *list);
void printReverse(struct LinkedList *list);

