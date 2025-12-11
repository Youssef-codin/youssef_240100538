#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BST{
private:
    node* root;

    node* deleteNode(node* r, int key) {
        if (key < r->data) {
            r->left = deleteNode(r->left, key);
        } else if (key > r->data) {
            r->right = deleteNode(r->right, key);
        } else {
            if (r->left == NULL) {
                node* temp = r->right;
                delete r;
                return temp;
            } 

            if (r->right == NULL) {
                node* temp = r->left;
                delete r;
                return temp;
            } 

            else {
                node* temp = findMin(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }
        return r;
    }
public:
    BST(){
        root = NULL;
    }

    node* insert(node* r, int item) {
        if (r == NULL) {
            return new node(item);
        }

        if (item <= r->data) {
            r->left = insert(r->left, item);
        } else {
            r->right = insert(r->right, item);
        }

        return r;
    }

    void insert(int item){
        root= insert(root,item);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void Preoredr(node* r){
        if (r == NULL){
            return;
        }
        cout << r->data << "\t";
        Preoredr(r->left);
        Preoredr(r->right);
    }

    void inorder(node* r){
        if (r == NULL){
            return;
        }
        inorder(r->left);
        cout << r->data << "\t";
        inorder(r->right); 
    }
    void postorder(node* r){
        if (r == NULL){
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout << r->data << "\t"; 
    }

    node* search(node* r,int k){
        if (r==NULL){
            return NULL;
        }else if(r->data == k){
            return r;
        }else if(k <r->data){
            return search(r->left, k);
        }else {
            return search(r->right, k);
        }
    }

    bool search(int k){
        root= search(root, k);
        if (root != NULL){
            return true;
        }else return false;
    }

    node* findMin(node* r){
        if (r == NULL){
            return NULL;
        }
        else if( r->left == NULL){
            return r;
        }else return findMin(r->left);
    }
};
