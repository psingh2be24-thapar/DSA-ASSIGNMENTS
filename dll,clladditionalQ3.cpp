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
node*reverseknodes(node*head,int k){
node*curr=head;
node*prev=nullptr;
node*next=nullptr;
int count=0;
while(curr!=nullptr && count<k){
    next=curr->next;
    curr->next=prev;
    if(prev!=nullptr){
        prev->prev=curr;
    }
    prev=curr;
    curr=next;
    count++;
}
if(curr!=nullptr){
    head->next=reverseknodes(curr,k);
    if(head->next!=nullptr){
        head->next->prev=head;
    }
}
return prev;
}


void display() {
        node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
     dll dl;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dl.insertend(val);
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "\nOriginal list:\n";
    dl.display();

    // 👇 Using your requested approach
    dl.head = dl.reverseknodes(dl.head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    dl.display();

    return 0;
}
