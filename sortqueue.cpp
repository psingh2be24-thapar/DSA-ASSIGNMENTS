#include <iostream>
#include <queue>
#include<climits>
using namespace std;

int findMinIndex(queue<int> &q, int sortedIndex) {
    int minIndex = -1;
    int minValue = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (curr < minValue && i <= sortedIndex) {
            minValue = curr;
            minIndex = i;
        }
        q.push(curr);
    }
    return minIndex;
}

void moveMinToRear(queue<int> &q, int minIndex) {
    int n = q.size();
    int minValue;

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i == minIndex)
            minValue = curr;
        else
            q.push(curr);
    }
    q.push(minValue);
}

void sortQueue(queue<int> &q) {
    int n = q.size();

    for (int i = 1; i <= n; i++) {
        int minIndex = findMinIndex(q, n - i);
        moveMinToRear(q, minIndex);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

