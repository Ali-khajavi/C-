#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Recursive function to check if a substring is a palindrome
bool isPalindromeRecursive(const string &s, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (s[start] != s[end]) {
        return false;
    }
    return isPalindromeRecursive(s, start + 1, end - 1);
}

// Function to find all palindromic substrings of length >= 2
void findAllPalindromes(const string &s, vector<string> &palindromes) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int len = j - i + 1;
            if (len >= 2 && isPalindromeRecursive(s, i, j)) {
                palindromes.push_back(s.substr(i, len));
            }
        }
    }
}

int main() {
    string input;
    cout << "Please enter your string: ";
    getline(cin, input);  // Allows full-line input including spaces

    vector<string> palindromes;
    findAllPalindromes(input, palindromes);

    cout << "\nFound Palindromic Substrings:\n";
    for (const string &p : palindromes) {
        cout << p << endl;
    }

    cout << "\nTotal Number of Palindromic Substrings: " << palindromes.size() << endl;

    return 0;
}
