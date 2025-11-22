#include <iostream>
using namespace std;


class node {
public:
    char data;
    node *next;
    node *prev;

    node(char data) {
        this->data = data;
        next = prev = nullptr;
    }
};
class dll {
public:
    node*head;
    dll(){
    head=nullptr;
    }
void insertend(char val){
node*newnode= new node(val);
if(head==nullptr){
    head=newnode;
    return;
}
node*temp=head;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;
}
bool ispalindrome(){
if(head==nullptr)
    return true;
node*left=head;
node*right=head;
while(right->next!=nullptr)
    right=right->next;
while(left!=right && right->next!=left){
    if(left->data!=right->data){
        return false;
    }
    left=left->next;
    right=right->prev;
}
return true;
}
 void display() {
        node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};
int main(){
dll dl;
    dl.insertend('A');
    dl.insertend('B');
    dl.insertend('C');
    dl.insertend('A');


    cout << "List: ";
    dl.display();

    if (dl.ispalindrome())
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is not a palindrome.\n";

    return 0;

}
