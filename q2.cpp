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

int countOccurrences(int key) {
    Node* p = head;
    int count = 0;
    while (p) {
        if (p->data == key) count++;
        p = p->next;
    }
    return count;
}

void deleteAllOccurrences(int key) {
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}

void display() {
    Node* p = head;
    while (p) { cout << p->data; if(p->next) cout<<"->"; p = p->next; }
    cout << endl;
}

int main() {
    int n, x, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }
    cout << "Enter key to delete: ";
    cin >> key;

    int count = countOccurrences(key);
    cout << "Count: " << count << endl;

    deleteAllOccurrences(key);
    cout << "Updated Linked List: ";
    display();
}
