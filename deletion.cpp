#include <iostream>
using namespace std;
int deletion(int arr[10], int index, int n){
 int i;
for(i=index; i<n-1; i++){
    arr[i]=arr[i+1];
}
n--;
return n;
};
int main(){
int arr[5]={5,2,3,4,1};
int n=5;
int index=2;
cout<<"original array:"<<endl;
for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
};
cout<<endl;
n=deletion(arr,index,n);
cout<<"array after deletion at index"<<index<<":";
for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
};
cout<<endl;

return 0;

}
