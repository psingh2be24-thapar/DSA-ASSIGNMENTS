#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;

    // Push all characters into stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    // Pop characters and form reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed= reversed+s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input; // takes single word input
    string output = reverseString(input);
    cout << "Reversed string: " << output << endl;
    return 0;
}
