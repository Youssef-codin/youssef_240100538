#include <iostream>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;

    node() {
        prev = nullptr;
        next = nullptr;
    }
};

class doublyLinkedList {
private:
    node* head;
    node* tail;

    bool isEmpty(){
        return head == nullptr;
    }

public:
    doublyLinkedList() {
        head = tail = nullptr;
    }

    void pushFront(int data) {
        node* node = new struct node;
        node->data = data;

        if (head == nullptr || tail == nullptr) {
            head = tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void pushBack(int val) {
        node* node = new struct node;
        node->data = val;
        node->next = nullptr;

        if (head == nullptr || tail == nullptr) {
            head = tail = node;
            return;
        }

        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    node* search(int value) {
         if (isEmpty()) {
            return nullptr;
        }

        node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
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

        node* searchNode = search(value);
        if (searchNode == nullptr) {
            return;
        }

        node* target = searchNode;
        searchNode->prev->next = target->next;
        delete target;
    }

    void display() const {
        node* nPointer = head;
        while(nPointer != NULL){
            cout << nPointer->data << '\n';
            nPointer = nPointer->next;
        }
    }

    ~doublyLinkedList() {
        node* cur = head;
        while (cur != nullptr) {
            node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
};

int main() {
    doublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushFront(0);
    list.display();
}
