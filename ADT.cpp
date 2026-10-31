#include <iostream> 
using namespace std; 

int arr[100], n = 0; 

void insert(int val, int pos) { 
    if (pos < 0 || pos > n) { 
        cout << "Invalid position\n"; 
        return; 
    } 
    for (int i = n; i > pos; i--) 
        arr[i] = arr[i - 1]; 
    arr[pos] = val; 
    n++; 
} 

void del(int pos) { 
    if (pos < 0 || pos >= n) { 
        cout << "Invalid position\n"; 
        return; 
    } 
    for (int i = pos; i < n - 1; i++) 
        arr[i] = arr[i + 1]; 
    n--; 
} 

int search(int val) { 
    for (int i = 0; i < n; i++) 
        if (arr[i] == val) return i; 
    return -1; 
} 

void display() { 
    cout << "List: "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main() { 
    int choice, val, pos; 
    while (true) { 
        cout << "\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\nEnter choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                cout << "Enter value and position: "; 
                cin >> val >> pos; 
                insert(val, pos); 
                break; 
            case 2: 
                cout << "Enter position to delete: "; 
                cin >> pos; 
                del(pos); 
                break; 
            case 3: 
                cout << "Enter value to search: "; 
                cin >> val; 
                pos = search(val); 
                if (pos != -1) cout << "Found at position " << pos << endl; 
                else cout << "Not found\n"; 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                return 0; 
            default: 
                cout << "Invalid choice\n"; 
        } 
    } 
}
