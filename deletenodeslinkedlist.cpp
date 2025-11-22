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
    private:
    node* head;
public:
    ll() {
        head=nullptr;
    }
     void insertAtEnd(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
int deletenodes(int key){
int count =0;
while(head!=nullptr && head->data==key){
    node* del=head;
    head=head->next;
    delete del;
    count++;
}
if(head==nullptr){
    return count;
}
node*curr=head;
while(curr->next!=nullptr){
    if(curr->next->data==key){
        node* del=curr->next;
        curr->next=curr->next->next;
        delete del;
        count ++;
    }
    else{
        curr=curr->next;
    }
}
return count;
}
 void display() {
        node* temp = head;
        if (temp == NULL) {
            cout << "Empty List";
            return;
        }
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << "->";
            temp = temp->next;
        }
    }
};
int main() {
    ll list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    int key = 1;
    cout << "Original Linked List: ";
    list.display();
    cout << endl;

    int count = list.deletenodes(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    list.display();
    cout << endl;

    return 0;
}
