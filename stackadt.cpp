#include <iostream> 
using namespace std; 

#define SIZE 100 

int stackArr[SIZE], top = -1; 
int queueArr[SIZE], front = -1, rear = -1; 

void push(int val) { 
    if (top == SIZE - 1) { 
        cout << "Stack Overflow\n"; 
        return; 
    } 
    stackArr[++top] = val; 
} 

void pop() { 
    if (top == -1) { 
        cout << "Stack Underflow\n"; 
        return; 
    } 
    cout << "Popped: " << stackArr[top--] << endl; 
} 

void displayStack() { 
    cout << "Stack: "; 
    for (int i = top; i >= 0; i--) 
        cout << stackArr[i] << " "; 
    cout << endl; 
} 

void enqueue(int val) { 
    if (rear == SIZE - 1) { 
        cout << "Queue Overflow\n"; 
        return; 
    } 
    if (front == -1) front = 0; 
    queueArr[++rear] = val; 
} 

void dequeue() { 
    if (front == -1 || front > rear) { 
        cout << "Queue Underflow\n"; 
        return; 
    } 
    cout << "Dequeued: " << queueArr[front++] << endl; 
} 

void displayQueue() { 
    cout << "Queue: "; 
    for (int i = front; i <= rear; i++) 
        cout << queueArr[i] << " "; 
    cout << endl; 
} 

int main() { 
    int choice, val; 
    while (true) { 
        cout << "\n1.Push 2.Pop 3.Display Stack 4.Enqueue 5.Dequeue 6.Display Queue 7.Exit\nEnter choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: cout << "Enter value: "; cin >> val; push(val); break; 
            case 2: pop(); break; 
            case 3: displayStack(); break; 
            case 4: cout << "Enter value: "; cin >> val; enqueue(val); break; 
            case 5: dequeue(); break; 
            case 6: displayQueue(); break; 
            case 7: return 0; 
            default: cout << "Invalid choice\n"; 
        } 
    } 
}
