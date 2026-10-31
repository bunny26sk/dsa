#include <iostream> 
using namespace std; 

struct Node { 
    int data; 
    Node* left; 
    Node* right; 
}; 

Node* newNode(int val) { 
    Node* n = new Node; 
    n->data = val; 
    n->left = NULL; 
    n->right = NULL; 
    return n; 
} 

Node* insert(Node* root, int val) { 
    if (root == NULL) return newNode(val); 
    if (val < root->data) 
        root->left = insert(root->left, val); 
    else 
        root->right = insert(root->right, val); 
    return root; 
} 

void inorder(Node* root) { 
    if (root == NULL) return; 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 

void preorder(Node* root) { 
    if (root == NULL) return; 
    cout << root->data << " "; 
    preorder(root->left); 
    preorder(root->right); 
} 

void postorder(Node* root) { 
    if (root == NULL) return; 
    postorder(root->left); 
    postorder(root->right); 
    cout << root->data << " "; 
} 

int main() { 
    Node* root = NULL; 
    int n, val; 
    cout << "Enter number of nodes: "; 
    cin >> n; 
    cout << "Enter values: "; 
    for (int i = 0; i < n; i++) { 
        cin >> val; 
        root = insert(root, val); 
    } 
    cout << "Inorder: "; inorder(root); cout << endl; 
    cout << "Preorder: "; preorder(root); cout << endl; 
    cout << "Postorder: "; postorder(root); cout << endl; 
    return 0; 
}
