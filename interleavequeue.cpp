#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int>&q){
    int n=q.size();
    if(n%2!=0){
        cout<<"queue cannot be interleaved"<<endl;
    }
int half=n/2;
queue<int>temp;
for(int i=0; i<half; i++){
    temp.push(q.front());
    q.pop();
}
while(!temp.empty()){
    q.push(temp.front());
    temp.pop();
    q.push(q.front());
    q.pop();
}


}
int main() {
    queue<int> q;


    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    queue<int> t = q;
    while (!t.empty()) {
        cout << t.front() << " ";
        t.pop();
    }
    cout << endl;

    interleave(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
