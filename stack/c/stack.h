struct Node {
    int value;
    struct Node *next;
};

struct Stack {
    struct Node *top;
    unsigned int size;
};

struct Stack *Stack();
struct Node *Node(int value);

void push(struct Stack *stack, int value);
void pop(struct Stack *stack);
int peek(struct Stack *stack);
int size(struct Stack *stack);
void print(struct Stack *stack);
