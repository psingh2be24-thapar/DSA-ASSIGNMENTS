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
void insertatend(int val){
node*newnode= new node(val);
if(head==nullptr){
    head = newnode;
    return;
}
node*temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;
}

node*reverseknodes(node*head,int k){

  if(head==nullptr){
    return nullptr;
  }
node* temp = head;
    int count = 0;
    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    // If less than k nodes, return head as it is (don’t reverse)
    if (count < k) {
        return head;
    }
/*if(next!=nullptr){
node*previousnode=reverseknodes(temp,k);
}*/
node*curr=head;
node* previousnode = nullptr;
node* next=nullptr;
count=0;
while(curr != nullptr && count<k){
    next=curr->next;
    curr->next=previousnode;
    previousnode=curr;
    curr=next;
    count++;
}
if(next!=nullptr){
head->next=reverseknodes(next,k);
}
return previousnode;

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
cout<<endl;
    }
};
int main(){
ll list;
list.insertatend(1);
list.insertatend(2);
list.insertatend(3);
list.insertatend(4);
list.insertatend(5);
list.insertatend(6);
list.insertatend(7);
list.insertatend(8);

list.display();
int k=3;
list.head=list.reverseknodes(list.head,3);

list.display();

return 0;






}
