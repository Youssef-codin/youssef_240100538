#include <iostream>

using namespace std;

class Queue {
    string arr[6];
    int front = -1;
    int rear = 0; 
    int elems = 0;

    bool isFull(){ return elems == 6; }

    bool isEmpty(){ return elems == 0; }

public:
    void eq(string x){
        if(isFull()){ return; }

        if(isEmpty()){
            front++;
            arr[rear] = x;
            rear++;

        }else {
            arr[rear] = x;
            rear++;
        }

        elems++;
    }

    string dq(){
        string rtrnVal;

        if(isEmpty()){
            return "";
        }


        rtrnVal = arr[front];
        front++;

        if(isFull()){
            rear = 0;
        }

        elems--;

        if(rear == front -1 || elems == 0){
            front = -1;
            rear = 0;
        }


        return rtrnVal;
    }

    string getRear(){ 
        if(!isEmpty()){ return arr[rear-1]; }

        return nullptr;
    }

    string getFront(){ 
        if(!isEmpty()){return arr[front];} 

        return nullptr;
    }

    void printQ(){
        for(int i = front; i < rear; i++){
            cout << "Index: " << i << ") " << arr[i] << '\n';

        }
    }
};

int main () {
    Queue q;
    q.eq("a");
    q.eq("b");
    q.eq("c");
    q.eq("d");
    q.eq("e");
    q.dq();
    q.printQ();
    
    return 0;
}
