#include <iostream>

using namespace std;

class linkedlist {
   struct node {
        int data;
        node* next;
   }; 

    node* head;

public:
    linkedlist(){ 
        head = nullptr;
    }

    void add(int data){
        node newNode;
        newNode.data = data;
        newNode.next = nullptr;

        if(isEmpty()){
            head = &newNode;
        }else {
            node* endNode = head->next;
            while (endNode != nullptr) {
                endNode = endNode->next;
            }
            endNode->next = &newNode;
        }
    }

    void addFirst(int data){
        node newNode;
        newNode.data = data;
        newNode.next = nullptr;

        if(isEmpty()){
            head = &newNode;
        }else{
            newNode.next = head;
            head->next = &newNode;
        }
    }

    void addAt(int data);

private:
    bool isEmpty(){
        return head == nullptr;
    }
};

int main () {
    return 0;
}

