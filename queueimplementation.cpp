#include<iostream>
#define maxlen 5
using namespace std;
class Queue{
    int f,r;
    int arr[maxlen];
public:
    Queue(){
    f=r=-1;
    }
bool isfull(){
if(r==maxlen-1){
    return true;
}
else{
    return false;}
}
void enqueue(int x){
if(isfull()){
    cout<<"queue is full"<<endl;
}
else if(f==-1 && r==-1){
    f=r=0;
    arr[r]=x;
    cout<<"item inserted:"<<x<<"to index:"<<r<<endl;
}
else{
    r++;
    arr[r]=x;
    cout<<"item inserted:"<<x<<"to index:"<<r<<endl;

}}
bool isempty(){
if(f==-1 || f>r){
    return true;
}
else
    return false;
}
void dequeue(){
    int y;
if(isempty()){
    cout<<"queue is underflow"<<endl;
}
else if(f==0 && r==0){
    y=arr[f];
    cout<<"item deleted:"<<y<<"from index:"<<f<<endl;
    f=r=-1;
}
else{
    y=arr[f];
    cout<<"item deleted:"<<y<<"from index:"<<f<<endl;
    f++;
}}
int peek(){
   return arr[f];
}
void display(){
if(isempty()){
    cout<<"queue is underflow"<<endl;
}
else{
   cout<<"queue items are:"<<endl;
   for(int i=f; i<=r; i++){
    cout<<arr[i]<< " ";
   }
   cout<<endl;
}

}

};
int main(){

Queue q;

      q.display();
      q.enqueue(10);
      q.enqueue(20);

      q.display();
      q.dequeue();

      q.enqueue(30);
      q.enqueue(40);
      q.enqueue(50);
      q.enqueue(60);

      q.display();

      cout<<q.peek()<<endl;
 return 0;

}


















