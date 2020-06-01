#include<iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;
    Node* insert(int item, Node* newNode)
    {
        if(newNode == NULL)
        {
            newNode = new Node;
            newNode->data = item;
            newNode->left = newNode->right = NULL;
        }
        else if(item < newNode->data)
            newNode->left = insert(item, newNode->left);
        else if(item > newNode->data)
            newNode->right = insert(item, newNode->right);
        return newNode;
    }

    Node* findMin(Node* newNode)
    {
        if(newNode == NULL)
            return NULL;
        else if(newNode->left == NULL)
            return newNode;
        else
            return findMin(newNode->left);
    }

    Node* findMax(Node* newNode) {
        if(newNode == NULL)
            return NULL;
        else if(newNode->right == NULL)
            return newNode;
        else
            return findMax(newNode->right);
    }

    Node* remove(int item, Node* newNode) {
        Node* temp;
        if(newNode == NULL)
            return NULL;
        else if(item < newNode->data)
            newNode->left = remove(item, newNode->left);
        else if(item > newNode->data)
            newNode->right = remove(item, newNode->right);
        else if(newNode->left && newNode->right)
        {
            temp = findMin(newNode->right);
            newNode->data = temp->data;
            newNode->right = remove(newNode->data, newNode->right);
        }
        else
        {
            temp = newNode;
            if(newNode->left == NULL)
                newNode = newNode->right;
            else if(newNode->right == NULL)
                newNode = newNode->left;
            delete temp;
        }

        return newNode;
    }

    void inorder(Node* newNode) {
    	//the same idea for post-order and pre-order
    	//in-order displays the left sub-tree then root then right sub-tree
        if(newNode == NULL)
            return;
        inorder(newNode->left);
        cout << newNode->data << " ";
        inorder(newNode->right);
    }

    Node* find(Node* newNode, int item) {
        if(newNode == NULL)
            return NULL;
        else if(item < newNode->data)
            return find(newNode->left, item);
        else if(item > newNode->data)
            return find(newNode->right, item);
        else
            return newNode;
    }

public:
    BST() {
        root = NULL;
    }
    void insert(int item) {
        root = insert(item, root);
    }
    void remove(int item) {
        root = remove(item, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int item) {
        root = find(root, item);
    }
};

int main() {

    return 0; 
}