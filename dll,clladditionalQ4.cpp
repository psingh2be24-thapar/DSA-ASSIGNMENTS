#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*next;
    node*prev;
node(int val){
data=val;
next=prev=nullptr;
}
};
class dll{
public:
    node*head;
    dll(){
 head = nullptr;
    }
void insertend(int val){
node*temp=head;
node*newnode=new node(val);
if(head==nullptr){
head=newnode;
return;
}
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;
}
void print(){
 node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
}

void printReverse()
    {
        node *temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ->";
            temp=temp->prev;
        }
        cout<<endl;
}

void correctpointer(){
     if(!head)
        {
            return;
        }

node*temp=head;
while(temp->next!=nullptr){
    if(temp->next->prev!=temp){
        temp->next->prev=temp;
    }

   temp=temp->next;
}
}
};
int main(){
dll ll;
    ll.head = new node(1);
    ll.head->next = new node(2);
    ll.head->next->prev = ll.head;
    ll.head->next->next = new node(3);
    ll.head->next->next->prev =ll.head;
    ll.head->next->next->next = new node(4);
    ll.head->next->next->next->prev = ll.head->next->next;

    cout << "\nIncorrect Linked List: ";
    ll.print();
    ll.printReverse();

    ll.correctpointer();

    cout << "\nCorrected Linked List: ";
    ll.print();
    ll.printReverse();


    return 0;
}
