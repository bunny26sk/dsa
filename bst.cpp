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
    else if (val > root->data) 
        root->right = insert(root->right, val); 
    return root; 
} 

Node* search(Node* root, int val) { 
    if (root == NULL || root->data == val) return root; 
    if (val < root->data) return search(root->left, val); 
    return search(root->right, val); 
} 

Node* findMin(Node* root) { 
    while (root->left != NULL) root = root->left; 
    return root; 
} 

Node* deleteNode(Node* root, int val) { 
    if (root == NULL) return root; 
    if (val < root->data) 
        root->left = deleteNode(root->left, val); 
    else if (val > root->data) 
        root->right = deleteNode(root->right, val); 
    else { 
        if (root->left == NULL) { 
            Node* t = root->right; 
            delete root; 
            return t; 
        } 
        if (root->right == NULL) { 
            Node* t = root->left; 
            delete root; 
            return t; 
        } 
        Node* succ = findMin(root->right); 
        root->data = succ->data; 
        root->right = deleteNode(root->right, succ->data); 
    } 
    return root; 
} 

void inorder(Node* root) { 
    if (root == NULL) return; 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 

int main() { 
    Node* root = NULL; 
    int choice, val; 
    while (true) { 
        cout << "\n1.Insert 2.Search 3.Delete 4.Inorder Display 5.Exit\nEnter choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: cout << "Enter value: "; cin >> val; root = insert(root, val); break; 
            case 2: 
                cout << "Enter value: "; cin >> val; 
                if (search(root, val) != NULL) cout << "Found\n"; 
                else cout << "Not Found\n"; 
                break; 
            case 3: cout << "Enter value: "; cin >> val; root = deleteNode(root, val); break; 
            case 4: cout << "Inorder: "; inorder(root); cout << endl; break; 
            case 5: return 0; 
            default: cout << "Invalid choice\n"; 
        } 
    } 
}
