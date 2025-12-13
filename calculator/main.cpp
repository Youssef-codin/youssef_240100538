#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        // TODO:
    }

    void push(char value) {
        // TODO:
    }

    char pop() {
        // TODO:
    }

    char peek() {
        // TODO:
    }

    ~Stack() {
        // TODO: delete all nodes
    }
};

// ============================================================
// HELPER FUNCTIONS
// ============================================================

int precedence(char op) {
    // TODO:
}

bool isOperator(char ch) {
    // TODO:
}

// ============================================================
// CONVERSION: INFIX TO POSTFIX
// ============================================================
string infixToPostfix(const string& infix) {
    Stack st;
    string postfix = "";

    // TODO:

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    Stack st;

    // TODO:

    return 0;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
