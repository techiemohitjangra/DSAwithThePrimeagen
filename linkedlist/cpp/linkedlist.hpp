class Node {
    int value;
    Node *next, *prev;

  public:
    Node();

    Node(int value);
    int getValue();
    Node *getNext();
    Node *getPrev();

    void setValue(int value);
    void setNext(Node *next);
    void setPrev(Node *prev);
};

class LinkedList {
    Node *head, *tail;
    unsigned int len;

  public:

    LinkedList();
    LinkedList(Node *head, Node *tail);

    Node* getHead();
    Node* getTail();
    unsigned int length();
    int begin();
    int end();
    void insert(int index, int value);
    void push_back(int value);
    int pop_back();
    void push_front(int value);
    int pop_front();
    int at(unsigned int index);
    int deleteNode(unsigned int index);
    int find(int target);
    void print();
    void reverse();
};
