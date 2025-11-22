#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cout << "Enter the characters (space separated): ";
    getline(cin, str);

    queue<char> q;
    int freq[256] = {0};
    for (int i = 0; i < str.length(); i++) {
    char ch = str[i];

    if (ch == ' ') continue;

    freq[ch]++;
    q.push(ch);

    while (!q.empty() && freq[q.front()] > 1)
        q.pop();

    if (q.empty())
        cout << "-1 ";
    else
        cout << q.front() << " ";
}
return 0;
}
