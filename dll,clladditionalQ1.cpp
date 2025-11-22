#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int new_value) {
        data = new_value;
        next = nullptr;
    }
};

// Function to split a circular linked list into two halves
void splitList(Node* head, Node*& head1, Node*& head2) {
    if (head == nullptr) {
        head1 = nullptr;
        head2 = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Use slow and fast pointer strategy
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For even nodes, move fast one more step
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // Set head1 and head2
    head1 = head;
    head2 = slow->next;

    // Break the list into two halves
    slow->next = head1;    // First half becomes circular
    fast->next = head2;    // Second half becomes circular
}

// Utility function to print a circular linked list
void printList(Node* head) {
    Node* curr = head;
    if (head != nullptr) {
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;  // Make it circular

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    splitList(head, head1, head2);

    cout << "First half: ";
    printList(head1);

    cout << "Second half: ";
    printList(head2);

    return 0;
}
