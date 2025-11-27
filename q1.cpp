#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertBeginning(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertEnd(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    if (!head) { head = temp; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

void insertAfter(int value, int x) {
    Node* p = head;
    while (p && p->data != value) p = p->next;
    if (!p) { cout << "Node not found\n"; return; }
    Node* temp = new Node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

void insertBefore(int value, int x) {
    if (!head) return;
    if (head->data == value) { insertBeginning(x); return; }
    Node* p = head;
    while (p->next && p->next->data != value) p = p->next;
    if (!p->next) { cout << "Node not found\n"; return; }
    Node* temp = new Node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

void deleteBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Node* p = head;
    while (p->next->next) p = p->next;
    delete p->next;
    p->next = nullptr;
}

void deleteNode(int value) {
    if (!head) return;
    if (head->data == value) { deleteBeginning(); return; }
    Node* p = head;
    while (p->next && p->next->data != value) p = p->next;
    if (!p->next) { cout << "Node not found\n"; return; }
    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
}

void searchNode(int value) {
    Node* p = head;
    int pos = 1;
    while (p) {
        if (p->data == value) { cout << "Node found at position " << pos << endl; return; }
        p = p->next;
        pos++;
    }
    cout << "Node not found\n";
}

void display() {
    Node* p = head;
    if (!p) { cout << "List is empty\n"; return; }
    while (p) { cout << p->data << " "; p = p->next; }
    cout << endl;
}

int main() {
    int choice, x, value;
    while (true) {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert Before Node\n4.Insert After Node\n";
        cout << "5.Delete from Beginning\n6.Delete from End\n7.Delete Specific Node\n8.Search Node\n9.Display\n10.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) { cout << "Enter value: "; cin >> x; insertBeginning(x); }
        else if (choice == 2) { cout << "Enter value: "; cin >> x; insertEnd(x); }
        else if (choice == 3) { cout << "Enter value to insert: "; cin >> x; cout << "Enter node value before which to insert: "; cin >> value; insertBefore(value, x); }
        else if (choice == 4) { cout << "Enter value to insert: "; cin >> x; cout << "Enter node value after which to insert: "; cin >> value; insertAfter(value, x); }
        else if (choice == 5) deleteBeginning();
        else if (choice == 6) deleteEnd();
        else if (choice == 7) { cout << "Enter value to delete: "; cin >> x; deleteNode(x); }
        else if (choice == 8) { cout << "Enter value to search: "; cin >> x; searchNode(x); }
        else if (choice == 9) display();
        else if (choice == 10) break;
        else cout << "Invalid choice\n";
    }
}
