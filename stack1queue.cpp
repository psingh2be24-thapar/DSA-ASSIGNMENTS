#include<iostream>
#include<queue>

using namespace std;
class Mystack{
public:
    queue<int>q;
void push(int x){
    int n=q.size();
    q.push(x);
for(int i=0; i<n; i++){
        q.push(q.front());
        q.pop();
        }
}
bool isempty() {
        return q.empty();
    }
int pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }
 int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }
    void display() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        queue<int> temp = q;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
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
