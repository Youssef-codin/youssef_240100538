#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node() {
        prev = nullptr;
        next = nullptr;
    }
};

class doublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    doublyLinkedList() {
        head = tail = nullptr;
    }

    void pushFront(int data) {
        Node* node = new Node;
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
        Node* node = new Node;
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

    void display() const {
        Node* nPointer = head;
        while(nPointer != NULL){
            cout << nPointer->data << '\n';
            nPointer = nPointer->next;
        }
    }

    ~doublyLinkedList() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* next = cur->next;
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
