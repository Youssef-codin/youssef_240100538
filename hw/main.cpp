#include <iostream>
using namespace std;
//
// Reuse the same Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; // points to the top node of the stack

    bool isEmpty(){
        if(top == NULL){
            return true;
        }

        return false;
    }
   
public:
    Stack() { top = NULL; } // constructor

    ~Stack() {
        Node* nPointer = top;
        while(nPointer != NULL){
            Node* nextNode = nPointer->next;
            delete nPointer;
            nPointer = nextNode;
        }
    }
    
    // Function to add a new element to the stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if(isEmpty()){
            top = newNode;
            return;
        }

        Node* nPointer = top;
        while(nPointer->next != NULL){
            nPointer = nPointer->next;
        }

        nPointer->next = newNode;
    }
   
    // Function to display all elements
    void display() const {
        Node* nPointer = top;
        while(nPointer != NULL){
            cout << nPointer->data << '\n';
            nPointer = nPointer->next;
        }
    }
};

class Queue {
private:
    Node* head; // points to the first node
    Node* tail; // points to the last node

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
        Node* nPointer = head;
        while(nPointer != NULL){
            Node* nextNode = nPointer->next;
            delete nPointer;
            nPointer = nextNode;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if(isEmpty()){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    // Function to display all elements
    void display() const {
        Node* nPointer = head;
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
