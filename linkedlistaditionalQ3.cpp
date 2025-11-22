#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*next;
    node(int val){
    data=val;
    next= nullptr;

    }
};
class ll{

public:
    node* head;
    ll() {
        head=nullptr;
}
 void insertAtEnd(int val) {
        node* newnode = new node(val);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newnode;
    }
 void createloop(int pos) {
        if (pos == 0) return;
        node* loopstart = head;
        for (int i = 1; i < pos && loopstart != nullptr; i++)
            loopstart = loopstart->next;

        node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = loopstart; // creating loop
    }
void removeacycle(){
node*slow=head;
node*fast=head;
node*prev=nullptr;
while(fast!=nullptr&&fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        cout<<"loop detected"<<endl;
        break;
    }
}

 if (fast == nullptr || fast->next == nullptr) {
            cout << "No loop found.\n";
            return;
        }

slow=head;
while(slow!=fast){
    slow=slow->next;
    prev=fast;
    fast=fast->next;

}
cout << "Starting node of loop is: " << slow->data << endl;

prev->next=nullptr;

cout << "Loop removed successfully!\n";


}
void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
 void displayWithLimit(int limit) {
        node* temp = head;
        int count = 0;
        while (temp != nullptr && count < limit) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
            count++;
        }
        if (temp != nullptr)
            cout << "->(loop continues...)";
        cout << endl;
    }
};
int main() {
    ll list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    // Create loop for testing: connect last node to node 3
    list.createloop(3);
    cout << "List (with loop, showing only first 15 nodes):\n";
    list.displayWithLimit(10);
    list.removeacycle();  // Detect and remove loop

    cout << "\nList after loop removal:\n";
    list.display();

    return 0;
}

