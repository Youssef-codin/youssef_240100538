#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node() {
        next = nullptr;
    }
};

class circularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    circularLinkedList() {
        head = tail = nullptr;
    }

    void pushFront(int value) {
        Node* node = new Node;
        node->data = value;

        if (head == nullptr) {
            head = tail = node;
            node->next = node;  
            return;
        }

        node->next = head;
        head = node;
        tail->next = head;
    }

    void pushBack(int value) {
        Node* node = new Node;
        node->data = value;

        if (head == nullptr) {
            head = tail = node;
            node->next = node;
            return;
        }

        tail->next = node;
        tail = node;
        tail->next = head;
    }

    void display() const {
        if (head == nullptr) return;

        Node* cur = head;
        do {
            cout << cur->data << '\n';
            cur = cur->next;
        } while (cur != head);
    }

    ~circularLinkedList() {
        if (head == nullptr) return;

        Node* cur = head->next;
        while (cur != head) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        delete head;
    }
};

int main() {
    circularLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushFront(0);
    list.display();
}
