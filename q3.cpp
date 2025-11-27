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
    cout << endl;
}

void findMiddle() {
    if (!head) { cout << "List is empty\n"; return; }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
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
    cout << "Linked List: ";
    display();
    findMiddle();
}
