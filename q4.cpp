#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEnd(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    if (!head) { head = temp; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

void display() {
    Node* p = head;
    while (p) { cout << p->data; if(p->next) cout << "->"; p = p->next; }
    cout << "->NULL" << endl;
}

void reverseList() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }
    cout << "Original Linked List: ";
    display();
    reverseList();
    cout << "Reversed Linked List: ";
    display();
}
