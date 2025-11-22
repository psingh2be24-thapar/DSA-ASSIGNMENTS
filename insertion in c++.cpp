#include <iostream>

using namespace std;


int insert(int in , int sz, int n, int arr[]){
    int i;
for(i=sz;i>in;i--){
    arr[i]=arr[i-1];
};
cout<<endl;
arr[in]=n;
sz++;
return sz;
};
int main(){ int in,i,sz,arr[100],n;
cout << "Enter the number of elements in the array (max 100): ";
cin >> sz;
cout << "Enter " << sz << " elements:" << endl;
for (int i = 0; i < sz; i++) {
        cin >> arr[i];
};
cout<<endl;
cout<<"enter the number to be inserted:";
cin>>n;
cout<<"enter the index where the number is to be inserted: ";
cin>>in;
sz=insert(in,sz,n,arr);
cout << "array after inserting new number:";
for(i=0;i<sz;i++){
    cout<<arr[i]<<" ";
};
cout<<endl;
    return 0;
}
