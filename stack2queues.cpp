#include<iostream>
#include<queue>
using namespace std;
class Mystack{
public:
    queue<int>q1;
    queue<int>q2;
    Mystack(){

    };
void push(int x){
while(!q1.empty()){
    q2.push(q1.front());
    q1.pop();
}
q1.push(x);
while(!q2.empty()){
    q1.push(q2.front());
    q2.pop();
}
}
int pop(){
    if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
int ans=q1.front();
q1.pop();
return ans;
}
int top(){
    if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
return q1.front();
}
bool isempty(){
return q1.empty();
}
void display() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }


};
int main(){
Mystack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "After pushing 10, 20, 30, 40:" << endl;
    s.display();

    cout << "\nTop element: " << s.top() << endl;

    cout << "\nPop one element: " << s.pop() << endl;
    s.display();

    cout << "\nPop another element: " << s.pop() << endl;
    s.display();

    cout << "\nIs stack empty? " << (s.isempty() ? "Yes" : "No") << endl;

    return 0;





}
