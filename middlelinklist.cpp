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
    };
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
int midofll(){
node* slow=head;
node* fast=head;
while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
}
return slow->data;
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
int main(){

ll list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);

    cout << "Original Linked List: ";
    list.display();
    cout << endl;
    int mid=list.midofll();
    cout << "mid is: " << mid<< endl;



    return 0;
}
