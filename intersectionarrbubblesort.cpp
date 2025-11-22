#include <iostream>
using namespace std;

// Manual sorting using Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[] = {1, 4, 2, 5, 6};
    int B[] = {2, 5, 3, 7};
    int sizeA = 5, sizeB = 4;

    bubbleSort(B, sizeB); // Sort B manually using our function

    cout << "Intersection using binary search and manual sort: ";

    for (int i = 0; i < sizeA; i++) {
        int key = A[i];
        int left = 0, right = sizeB - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (B[mid] == key) {
                cout << key << " ";
                break;
            } else if (B[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return 0;
}
