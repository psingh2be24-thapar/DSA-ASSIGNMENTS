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
node* newNode = new node(val);
if (head == NULL) {
head = newNode;
return;
}
node* temp=head;
  while(temp->next!=nullptr){
            temp=temp->next;
}
temp->next=newNode;
}
node* getIntersectionNode(node* a , node* b) {
int lengthA=0;
node* currA=a;
while(currA!=nullptr){
    lengthA++;
    currA=currA->next;
}
int lengthB=0;
node* currB=b;
while(currB!=nullptr){
    lengthB++;
    currB=currB->next;
}
int difference= abs(lengthA-lengthB);
if(lengthA<lengthB)
    return findintersectionnode(b,a,difference);
else{
    return findintersectionnode(a,b,difference);
}
}
node* findintersectionnode(node* a, node* b, int difference){
 while(difference>0){
    a=a->next;
    difference--;
 }
while(a!=nullptr && b!=nullptr){
    if(a==b){
        return a;
    }
    a=a->next;
    b=b->next;
}
return nullptr;
}

void display(node*head) {
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
 ll list1, list2;

    // Common nodes (shared part)
    node* common = new node(30);
    common->next = new node(40);
    common->next->next = new node(50);

    // First Linked List: 10 → 20 → 30 → 40 → 50
    list1.head = new node(10);
    list1.head->next = new node(20);
    list1.head->next->next = common;

    // Second Linked List: 15 → 30 → 40 → 50
    list2.head = new node(15);
    list2.head->next = common;

    cout << "List 1: ";
    list1.display(list1.head);
    cout<<endl;

    cout << "List 2: ";
    list2.display(list2.head);
    cout<<endl;

    node* intersection = list1.getIntersectionNode(list1.head, list2.head);

    if (intersection)
        cout << "Intersection Node: " << intersection->data << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}













