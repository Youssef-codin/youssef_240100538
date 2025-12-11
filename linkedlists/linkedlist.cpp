#include <iostream>

using namespace std;

class linkedlist {
private:
    struct node {
        int data;
        node* next;
    };

    node* head;

    bool isEmpty(){
        return head == nullptr;
    }

public:
    linkedlist(){ 
        head = nullptr;
    }

    void add(int data){
        node* newNode = new node;
        newNode->data = data;
        newNode->next = nullptr;

        if(isEmpty()){
            head = newNode;
        }else {
            node* endNode = head->next;
            while (endNode != nullptr) {
                endNode = endNode->next;
            }
            endNode->next = newNode;
        }
    }

    void addFirst(int data){
        node* newNode = new node;
        newNode->data = data;
        newNode->next = nullptr;

        if(isEmpty()){
            head = newNode;
        }else{
            newNode->next = head;
            head->next = newNode;
        }
    }

    node* searchRtrnsPrevNode(int value) {
        if (isEmpty()) {
            return nullptr;
        }

        if (head->data == value) {
            return nullptr;
        }

        node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                return current; 
            }
            current = current->next;
        }

        return nullptr; 
    }
    void remove(int value) {
        if (isEmpty()) {
            return;
        }

        if (head->data == value) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* beforeTarget = searchRtrnsPrevNode(value);
        if (beforeTarget == nullptr) {
            return;
        }

        node* target = beforeTarget->next;
        beforeTarget->next = target->next;
        delete target;
    }
};

int main () {
    return 0;
}

