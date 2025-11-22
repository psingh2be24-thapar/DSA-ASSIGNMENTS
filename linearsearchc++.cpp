#include<iostream>
using namespace std;
int linearsearch(int sz, int key, int arr[]){
    int i;
for(i=0; i<sz; i++){
    if(arr[i]==key){
        return i;
    }
}
return -1;
}
int main(){
int sz,arr[100],key;
cout<<"enter the number of elements in array:";
cin>>sz;
cout<<" enter "<< sz <<" elements "<<endl;
for(int i=0; i<sz; i++ ){
    cin>>arr[i];
};
cout << "Enter the number to search: ";
    cin >> key;


    int index = linearsearch(sz,key,arr);


    if (index != -1) {
        cout << "Element found at index " << index << "." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}









