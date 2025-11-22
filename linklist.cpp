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
    node* tail;

public:
    ll() {
        head=tail = nullptr;
    }
void insbeg(int x){
    node*newnode= new node(x);
if(head==nullptr)
    head=tail=newnode;
else{
    newnode->next=head;
    head= newnode;
}}

void insend(int x){
node*newnode= new node(x);
if(head==nullptr)
    head=tail=newnode;
else {
    tail->next=newnode;
    tail=newnode;
}}

void delbeg(){
node*temp=head;
head=head->next;
temp->next= nullptr;
delete temp;
}
void delend(){
node*temp=head;
if (head == nullptr) return;
if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
while(temp->next!=tail){
    temp=temp->next;
}
temp->next= nullptr;
delete tail;
tail=temp;
}
void insertmid(int val, int pos){
    if (pos <= 0 || head == nullptr) {
        insbeg(val);
        return;
    }
node*newnode= new node(val);
node*temp=head;
for(int i=0; i<pos-1; i++){
    temp=temp->next;
}
newnode->next=temp->next;
temp->next=newnode;
 if (newnode->next == nullptr) {
        tail = newnode;
    }
}
void insert_before(int target, int val) {
        if (head == nullptr) return;

        if (head->data == target) {
            insbeg(val);
            return;
        }

        node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value " << target << " not found.\n";
            return;
        }

        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void insert_after(int target, int val) {
        node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value " << target << " not found.\n";
            return;
        }

        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;

        if (newnode->next == nullptr)
            tail = newnode;
    }
void deleteSpecificNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head->data == value) {
            delbeg();
            return;
        }
        node* temp = head;
        node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with value " << value << " not found.\n";
            return;
        }
        prev->next = temp->next;
        cout << temp->data << " deleted from the list.\n";
        delete temp;
    }

void printll(){
node*temp=head;
while(temp!= nullptr){
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<"NULL"<<endl;
}

};

void menu(ll& list) {
    int choice, value, pos, target;
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Insert before value\n";
        cout << "5. Insert after value\n";
        cout << "6. Delete from beginning\n";
        cout << "7. Delete from end\n";
        cout << "8. Delete specific value\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insbeg(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insend(value);
            break;
        case 3:
            cout << "Enter value and position (0-based index): ";
            cin >> value >> pos;
            list.insertmid(value, pos);
            break;
        case 4:
            cout << "Enter target value and new value to insert before it: ";
            cin >> target >> value;
            list.insert_before(target, value);
            break;
        case 5:
            cout << "Enter target value and new value to insert after it: ";
            cin >> target >> value;
            list.insert_after(target, value);
            break;
        case 6:
            list.delbeg();
            break;
        case 7:
            list.delend();
            break;
        case 8:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteSpecificNode(value);
            break;
        case 9:
            cout << "Linked List: ";
            list.printll();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
int main(){
ll myList;
    menu(myList);
/*ll a;
a.insbeg(1);
a.insbeg(2);
a.insbeg(3);
a.insbeg(4);
a.printll();
a.delbeg();
a.delend();
a.printll();
a.insertmid(5,1);
a.printll();
a.deleteSpecificNode(2);
a.printll()*/
return 0;





}
