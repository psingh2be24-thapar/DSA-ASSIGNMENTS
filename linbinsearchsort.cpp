#include<iostream>
using namespace std;
int linearmissing( int arr[10], int len){
for(int i=0; i<len; i++){
    if(arr[i]!=i+1){
      return i+1;
    }
}
return len+1;

}
int binarymissing( int arr[], int len){
    int l=0; int r=len-1;
while(l<=r){
        int mid=(l+r)/2;
        if(mid>0 && arr[mid]!=mid+1 && arr[mid-1]==mid){
            return mid+1;
        }
        else if(arr[mid]==mid+1){
            l=mid+1;
        }
        else{
            r=mid-1;
        }

}

return len+1;

}
int main(){

int arr[]={1,2,4,5,6};
int len=sizeof(arr)/sizeof(arr[0]);
 cout<< binarymissing(arr,len) <<endl;



return 0;






}
