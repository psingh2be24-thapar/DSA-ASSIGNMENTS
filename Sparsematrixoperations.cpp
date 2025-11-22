#include<iostream>
using namespace std;
/*void matrix(int m, int n, int A[100][100]){
cout<<"enter the elements of matrix:"<<endl;

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>A[i][j];
    }}
}*/
void Sp(int m, int n, int A[100][100], int sp[100][3],int &sz, int &row){

sz=0;
row=1;

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(A[i][j]!=0){
            sz++;
        }}}
    cout<<sz<<endl;

    sp[0][0]=m;
    sp[0][1]=n;
    sp[0][2]=sz;

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(A[i][j]!=0){
            sp[row][0]=i;
            sp[row][1]=j;
            sp[row][2]=A[i][j];
            row++;
        }
    }}
cout<<"Sparse matrix is:"<<endl;
for(int i=0;i<row;i++){
    for(int j=0;j<3;j++){
        cout<<sp[i][j]<<"  ";
    }cout<<endl;
    }
}
void spadd(int A[100][3],int B[100][3], int C[100][3], int &k){
int i = 1, j = 1;
    k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] ||
           (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] ||
                (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {

            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }C[0][2] = k - 1;
}
void transpose(int S[100][3], int T[100][3]) {
    int m = S[0][0], n = S[0][1], sz = S[0][2];
    T[0][0] = n;
    T[0][1] = m;
    T[0][2] = sz;

    int k = 1;
    for (int col = 0; col < n; col++) {
        for (int i = 1; i <= sz; i++) {
            if (S[i][1] == col) {
                T[k][0] = S[i][1];
                T[k][1] = S[i][0];
                T[k][2] = S[i][2];
                k++;
            }
        }
    }
}

void printSparse(int S[100][3], int row) {
    for (int i = 0; i < row; i++) {
        cout << S[i][0] << "  " << S[i][1] << "  " << S[i][2] << endl;
    }
    cout << endl;
}
int main(){
int m, n, a, b;
int sz,row,row1;
int k;
int A[100][100],B[100][100];
int spA[100][3], spB[100][3], C[1000][3], T[100][3];
cout << "Enter the dimensions of matrix: ";
cin >> m >> n;
cout<<"enter the elements of matrix:"<<endl;

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>A[i][j];
    }cout<< endl;
}
cout << "Enter the dimensions of matrix: ";
cin >> a >> b;
cout<<"enter the elements of matrix:"<<endl;

for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
        cin>>B[i][j];}}

//matrix(m,n,A);
Sp(m,n,A,spA,sz,row);
Sp(m,n,B,spB,sz,row1);
spadd(spA,spB,C,k);
 cout << "Result of A + B in Sparse Form:" << endl;
printSparse(C, k);
 transpose(C, T);
cout << "Transpose of Result Matrix (in Sparse Form):" << endl;
printSparse(T, T[0][2] + 1);
return 0;

}
