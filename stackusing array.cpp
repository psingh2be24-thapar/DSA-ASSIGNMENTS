#include<iostream>
#include<stack>
using namespace std;
class Stack {
public:
 int *arr;
 int size;
 int top;
 Stack(int size){
 this->size=size;
 top=-1;
 arr = new int[size];
}
 void push(int element){
 if(size-top>1){
    top++;
    arr[top]=element;
}
 else{
    cout<<"overflow"<<endl;
}
}
 void pop(){
 if(top>=0)
    top--;
 else
    cout<<"underflow"<<endl;
}

 int peek(){
 if(top>=0){
    return arr[top];
}
 else
    cout<<"Stack is Empty"<<endl;

}
 bool isempty(){
 if(top==-1){
    return true;
}
 else
    return false;

}};
int main(){
Stack st(5);
st.push(3);
st.push(4);
st.push(7);
st.push(8);
st.push(9);
cout<<st.peek()<<endl;
}









