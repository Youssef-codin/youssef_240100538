#include <iostream>
using namespace std;

// Reuse the same Node structure
struct node {
    int data;
    node* next;
};

class Stack {
private:
    node* top; // points to the top node of the stack

    bool isEmpty(){
        if(top == NULL){
            return true;
        }

        return false;
    }
   
public:
    Stack() { top = NULL; } // constructor

    ~Stack() {
        node* nPointer = top;
        while(nPointer != NULL){
            node* nextNode = nPointer->next;
            delete nPointer;
            nPointer = nextNode;
        }
    }
    
    // Function to add a new element to the stack
    void push(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = NULL;

        if(isEmpty()){
            top = newNode;
            return;
        }

        node* nPointer = top;
        while(nPointer->next != NULL){
            nPointer = nPointer->next;
        }

        nPointer->next = newNode;
    }

    int pop(){
        if(isEmpty()){
            return -1;
        }

        int value = top->data;
        node* old = top;
        top = top->next;

        delete old;

        return value;
    }
   
    // Function to display all elements
    void display() const {
        node* nPointer = top;
        while(nPointer != NULL){
            cout << nPointer->data << '\n';
            nPointer = nPointer->next;
        }
    }
};

class Queue {
private:
    node* head; // points to the first node
    node* tail; // points to the last node

    bool isEmpty(){
        if(head == NULL | tail == NULL){
            return true;
        }
        return false;
    }

public:
    Queue() {
        head = tail = NULL;
    }

    ~Queue(){
        node* nPointer = head;
        while(nPointer != NULL){
            node* nextNode = nPointer->next;
            delete nPointer;
            nPointer = nextNode;
        }
    }

    void enqueue(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = NULL;

        if(isEmpty()){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    int dequeue(){
        if(isEmpty()){
            return -1;
        }

        int value = head->data;
        node* old = head;
        head = head->next;

        delete old;

        if(head == NULL){
            tail = NULL;
        }

        return value;
    }

    // Function to display all elements
    void display() const {
        node* nPointer = head;
        while(nPointer != NULL){
            cout << nPointer->data << '\n';
            nPointer = nPointer->next;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); 
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // Expected: 30 20 10
    return 0;
}
