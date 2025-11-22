#include<iostream>
#include<string>
#include<queue>
using namespace std;
void generatebinary(int n){
queue<string>q;
q.push("1");
for(int i=1;i<=n;i++){
    string curr=q.front();
    q.pop();
    cout<< curr << endl;
    q.push(curr+'0');
    q.push(curr+'1');

}
}
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << " are:\n";
    generatebinary(n);

    return 0;
}
