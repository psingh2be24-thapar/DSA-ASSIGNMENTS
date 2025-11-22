#include <iostream>
using namespace std;
class dnode {
public:
    int data;
    dnode* next;
    dnode* prev;
    dnode(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class dll {
    dnode* head;

public:
    dll() {
head = nullptr;
}
void insertbeg(int val){
dnode*newnode=new dnode(val);
if(head==nullptr){
    head=newnode;
    return;
}
newnode->next=head;
head->prev=newnode;
head=newnode;
}
void insertend(int val){
dnode*newnode=new dnode(val);
if(head==nullptr){
    head=newnode;
    return;
}
dnode*temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;
}

void insertafter(int key, int val) {
dnode*newnode=new dnode(val);
dnode*temp=head;
 while (temp && temp->data != key){
            temp = temp->next;
 }
if(temp==nullptr){
cout << "Node " << key << " not found.\n";
return;
}
newnode->next=temp->next;
newnode->prev=temp;
if (temp->next!=nullptr){
temp->next->prev = newNode;
}
temp->next=newnode;
}
void insertbefore(int key, int val){
dnode*newnode=new dnode(val);
if(head==nullptr){
    return;
}
if (head->data == key) {
insertbeg(val);
return;
}
dnode*temp=head;
 while (temp && temp->data != key){
            temp = temp->next;
 }
if(temp==nullptr){
cout << "Node " << key << " not found.\n";
return;
}
newNode->next = temp;
newNode->prev = temp->prev;
temp->prev->next = newNode;
temp->prev = newNode;
}
 void deletenode(int val) {
        if (head==nullptr) return;
        dnode* temp = head;

        if (head->data == val) {
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp && temp->data != val)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found.\n";
            return;
        }
        if (temp->next)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
};
class cnode {
public:
    int data;
    cnode* next;

    cnode(int val) {
        data = val;
        next = nullptr;
    }
};

class cll {
    cnode* head;
    cnode*tail;
public:
    cll() {
head = tail=nullptr;
}
void insertbeg(int val){
    cnode*newnode=new cnode(val);

if(head==nullptr){
        head=newnode;
        tail->next=head;
}
else{
    newnode->next=head;
    head=newnode;
    tail->next=head;
}
}
void insertend(int val){
cnode*newnode=new cnode(val);

if(head==nullptr){
        head=tail=newnode;
        tail->next=head;
}
node*temp=head;
while(temp->next!=head){
    temp=temp->next;
}
temp->next=newnode;
tail=newnode;
tail->next=head;
}
void insertafter(int key, int val){
    if(head==nullptr)
        return;
    cnode* temp = head;
    do{
        if(temp->data==key){
            cnode* newnode= new cnode(val);
            newnode->next=temp->next;
            temp->next=newnode;
            return;
        }
        temp=temp->next;
    }while(temp!=head)
cout<<"Node not found.\n"<<endl;
}
void insertbefore(int key, int val) {
        if (head==nullptr) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
       cnode* prev = nullptr;
        cnode* curr = head;
do{
        prev = curr;
        curr = curr->next;
    if(temp->data==key){
        cnode* newnode= new cnode(val);
        newnode->next=curr;
        prev->next=newnode;
        return;
    }
}while (curr != head);
cout << "Node not found.\n";
}
void deletenode(int val){
    if (!head) return;
        if (head->data == val && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        cnode* curr = head;
        cnode* prev = nullptr;
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == val) {
                prev->next = curr->next;
                if (curr == head)
                    head = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);
        cout << "Node not found.\n";
}

};
