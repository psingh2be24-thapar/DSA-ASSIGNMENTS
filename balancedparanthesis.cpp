#include<iostream>
#include<stack>
using namespace std;
bool isvalidparathesis(string exp){ int i;
stack<char>s;
for(i=0;i<exp.length();i++){
    char ch=exp[i];
    if(ch=='['||ch=='{'||ch=='('){
        s.push(ch);
        }
    else{
        if(!s.empty()){
            char ch=s.top();
            if((ch==')'&& ch=='(') || (ch=='}' && ch=='{') || (ch==']' && ch=='[')){
                s.pop();

            }
            else{
                return false;
            }
            }
        else {
            return false;
        }


    }

}
return s.empty() ? true:false;

};
int main(){


string expr="{()}";
    if(isvalidparathesis(expr))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";


}
