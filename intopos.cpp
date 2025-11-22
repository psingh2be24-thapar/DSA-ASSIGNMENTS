#include<iostream>
#include<stack>
using namespace std;
int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
void intopos( string s){
stack<char>st;
string result;
int i;
while (i <s.length()){
    if((s[i]>='A'&& s[i]<='Z') || (s[i]>='a'&& s[i]<='z') ||(s[i]>='0'&&s[i]<='9')){
       result+=s[i];
       }
    else if(s[i]=='('){
                st.push(s[i]);
            }
    else if(s[i]==')'){
        while(st.top()!='('){
                result += st.top();
                st.pop();
              } st.pop();
    }
    else {
			while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		i++;
	}


	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}


int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	intopos(exp);

	return 0;
}



