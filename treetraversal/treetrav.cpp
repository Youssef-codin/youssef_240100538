#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* node){
    if (node == nullptr) return;

    cout << node->data << '\n';
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << '\n';
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << '\n';
}

int main () {

    return 0;
}

