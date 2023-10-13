#include "linkedlist.hpp"
#include <iostream>
#include <stack>

Node::Node() {
    this->prev = nullptr;
    this->next = nullptr;
    this->value = 0;
}

Node::Node(int value) {
    this->prev = nullptr;
    this->next = nullptr;
    this->value = value;
}

int Node::getValue() { return this->value; }
Node *Node::getNext() { return this->next; }
Node *Node::getPrev() { return this->prev; }

void Node::setValue(int value) { this->value = value; }
void Node::setNext(Node *next) { this->next = next; }
void Node::setPrev(Node *prev) { this->prev = prev; }

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;
}

LinkedList::LinkedList(Node *head, Node *tail) {
    this->head = head;
    this->tail = tail;
    Node *temp = head;
    this->len = 0;
    while (temp != tail) {
        temp = temp->getNext();
        this->len++;
    }
}

Node *LinkedList::getHead() { return this->getHead(); }
Node *LinkedList::getTail() { return this->getTail(); }

unsigned int LinkedList::length() { return this->len; }
int LinkedList::begin() { return this->getHead()->getValue(); }
int LinkedList::end() { return this->getTail()->getValue(); }

void LinkedList::insert(int index, int value) {
    if (index < 0 && index > this->length()) {
        std::cerr << "Index out of range!" << std::endl;
        return;
    } else if (index == 0) {
        this->push_front(value);
    } else if (index == this->length()) {
        this->push_back(value);
    } else {
        int curr = 0;
        Node *temp = this->head;
        while (index != curr) {
            temp = temp->getNext();
            curr++;
        }
        Node *newNode = new Node(value);
        newNode->setPrev(temp->getPrev());
        newNode->setNext(temp->getNext());
        temp->getPrev()->setNext(newNode);
        temp->getNext()->setPrev(newNode);
    }
    this->len++;
}

void LinkedList::push_back(int value) {
    Node *newNode = new Node(value);
    if (this->length() == 0) {
        this->head = this->tail = newNode;
    }
    this->tail->setNext(newNode);
    newNode->setPrev(this->tail);
    this->tail = newNode;
    this->len++;
}

int LinkedList::pop_back() {
    if (this->length() == 0) {
        std::cerr << "List is empty!\n";
        return 0;
    } else if (this->length() == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        Node *temp = this->tail;
        int value = this->tail->getValue();
        this->tail = this->tail->getPrev();
        this->tail->setNext(nullptr);
        delete temp;
        return value;
    }
    this->len--;
    return 0;
}

void LinkedList::push_front(int value) {
    Node *newNode = new Node(value);
    if (this->head == nullptr && this->tail == nullptr) {
        this->head = this->tail = newNode;
    }
    newNode->setNext(this->head);
    this->head->setPrev(newNode);
    this->head = newNode;
    this->len++;
}

int LinkedList::pop_front() {
    if (this->length() == 0) {
        std::cerr << "List is empty!\n";
        return 0;
    } else if (this->length() == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        Node *temp = this->head;
        int value = this->head->getValue();
        this->head = this->head->getNext();
        this->head->setPrev(nullptr);
        delete temp;
        return value;
    }
    this->len--;
    return 0;
}

int LinkedList::at(unsigned int index) {
    if (index >= this->length()) {
        std::cerr << "Index out of range!" << std::endl;
        return 0;
    }
    int curr = 0;
    Node *temp = this->head;
    while (curr != index) {
        temp = temp->getNext();
        curr++;
    }
    return temp->getValue();
}

int LinkedList::deleteNode(unsigned int index) {
    if (index >= this->length()) {
        std::cerr << "Index out of range!" << std::endl;
        return 0;
    }
    int curr = 0, value = 0;
    Node *temp = this->head;
    while (curr != index) {
        temp = temp->getNext();
        curr++;
    }
    temp->getPrev()->setNext(temp->getNext());
    temp->getNext()->setPrev(temp->getPrev());
    value = temp->getValue();
    delete temp;
    this->len--;
    return value;
}

int LinkedList::find(int target) {
    if (this->length() == 0) {
        std::cerr << "List is empty!" << std::endl;
        return -1;
    }
    Node *temp = this->head;
    int curr = 0;
    while (temp != this->tail) {
        if (temp->getValue() == target) {
            return curr;
        }
        temp = temp->getNext();
        curr++;
    }
    return -1;
}

void LinkedList::print() {
    std::cout << "[";
    Node *temp = this->head;
    while (temp != this->tail) {
        std::cout << temp->getValue() << ", ";
        temp = temp->getNext();
    }
    std::cout << temp->getValue() << "]" << std::endl;
}

void LinkedList::reverse() {
    Node *temp = this->head;
    std::stack<typeof(this->head->getValue())> stack;

    while (temp != nullptr) {
        stack.push(temp->getValue());
        temp = temp->getNext();
    }

    temp = this->head;
    while (temp != nullptr) {
        temp->setValue(stack.top());
        stack.pop();
        temp = temp->getNext();
    }
}
