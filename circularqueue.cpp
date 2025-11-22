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
if(f==(r+1)%maxlen){
    return true;
}
else{
    return false;}
}
void enqueue(int x){
if(isfull()){
    cout<<"queue is full"<<endl;
}
else{
    if(f==-1 && r==-1){
     f=r=0;
     arr[r]=x;

}
   else{
    r=(r+1)%maxlen;
    arr[r]=x;
    cout<<"item inserted:"<<x<<"to index:"<<r<<endl;

}
}}
bool isempty(){
if(f==-1){
    return true;
}
else
    return false;
}
int dequeue(){
    int y;
if(isempty()){
    cout<<"queue is underflow"<<endl;
}
else {
        y=arr[f];
    if(f==r){

    f=r=-1;}
    else{
     f=(f+1)%maxlen;
     }
     return y;
     }}
int peek(){
   return arr[f];
}
void display(){ int i;
if(isempty()){
    cout<<"queue is underflow"<<endl;
}
else{
   cout<<"queue items are:"<<endl;
   for(i=f; i!=r; i=(i+1)%maxlen){
    cout<<arr[i]<< " ";
   }
cout<<arr[i];
}

}

};
int main(){

Queue q;
  q.dequeue();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  q.display();

  int x = q.dequeue();

  if (x!= -1)
    cout <<"\nELEMENT DELETED: " << x <<" FROM INDEX "<<endl;

  q.display();
  q.enqueue(7);
  q.display();
  q.enqueue(8);

 return 0;

}
