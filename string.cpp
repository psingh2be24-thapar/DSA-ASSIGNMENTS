#include <iostream>
#include <string>
using namespace std;

// (a) Concatenate two strings
string concatenateStrings(string s1, string s2) {
    string result = s1;
    for(int i=0; s2[i] != '\0'; i++) {
        result += s2[i]; // append characters of s2
    }
    return result;
}

// (b) Reverse a string
string reverseString(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++) {
        // swap characters from front and back
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }
    return s;
}

// (c) Delete all vowels from a string
string removeVowels(string s) {
    string result = "";
    for(int i=0; s[i] != '\0'; i++) {
        char c = s[i];
        char lower = (c >= 'A' && c <= 'Z') ? (c + 32) : c; // manual lowercase
        if(lower!='a' && lower!='e' && lower!='i' && lower!='o' && lower!='u') {
            result += c; // keep only non-vowels
        }
    }
    return result;
}

// (d) Sort strings in alphabetical order (Bubble Sort)
void sortStrings(string arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {  // lexicographic compare
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// (e) Convert a character from uppercase to lowercase
char toLowercase(char c) {
    if(c >= 'A' && c <= 'Z') {
        return c + 32;  // convert manually using ASCII
    }
    return c;
}

int main() {
    // (a) Concatenate
    string s1 = "Hello", s2 = "World";
    cout << "(a) Concatenate: " << concatenateStrings(s1, s2) << endl;

    // (b) Reverse
    string s3 = "OpenAI";
    cout << "(b) Reverse: " << reverseString(s3) << endl;

    // (c) Remove vowels
    string s4 = "Beautiful Day";
    cout << "(c) Remove vowels: " << removeVowels(s4) << endl;

    // (d) Sort strings
    string arr[] = {"banana", "apple", "cherry", "date"};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortStrings(arr, n);
    cout << "(d) Sorted strings: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // (e) Uppercase to lowercase
    char c = 'G';
    cout << "(e) Lowercase of " << c << " is " << toLowercase(c) << endl;

    return 0;
}
