#include <iostream> 
using namespace std; 

struct Node { 
    int data; 
    Node* next; 
}; 

Node* head = NULL; 

void insert(int val) { 
    Node* newNode = new Node; 
    newNode->data = val;
    newNode->next = NULL;
    
    if (head == NULL) { 
        head = newNode; 
        return; 
    } 
    Node* temp = head; 
    while (temp->next != NULL) 
        temp = temp->next; 
    temp->next = newNode; 
} 

void del(int val) { 
    if (head == NULL) { 
        cout << "List is empty\n"; 
        return; 
    } 
    if (head->data == val) { 
        Node* t = head; 
        head = head->next; 
        delete t; 
        return; 
    } 
    Node* prev = head; 
    Node* curr = head->next; 
    while (curr != NULL) { 
        if (curr->data == val) { 
            prev->next = curr->next; 
            delete curr; 
            return; 
        } 
        prev = curr; 
        curr = curr->next; 
    } 
    cout << "Value not found\n"; 
} 

void search(int val) { 
    Node* temp = head; 
    int pos = 0; 
    while (temp != NULL) { 
        if (temp->data == val) { 
            cout << "Found at position " << pos << endl; 
            return; 
        } 
        temp = temp->next; 
        pos++; 
    } 
    cout << "Not found\n"; 
} 

void display() { 
    Node* temp = head; 
    cout << "List: "; 
    while (temp != NULL) { 
        cout << temp->data << " -> "; 
        temp = temp->next; 
    } 
    cout << "NULL" << endl; 
} 

int main() { 
    int choice, val; 
    while (true) { 
        cout << "\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\nEnter choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: cout << "Enter value: "; cin >> val; insert(val); break; 
            case 2: cout << "Enter value to delete: "; cin >> val; del(val); break; 
            case 3: cout << "Enter value to search: "; cin >> val; search(val); break; 
            case 4: display(); break; 
            case 5: return 0; 
            default: cout << "Invalid choice\n"; 
        } 
    } 
}
