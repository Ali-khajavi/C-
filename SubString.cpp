#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isPalindromeRecursive(const string &s, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (s[start] != s[end]) {
        return false;
    }
    return isPalindromeRecursive(s, start + 1, end - 1);
}


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
    cout << "Please Write down your string";
    cin >> input;

    vector<string> palindromes;
    findAllPalindromes(input, palindromes);

    cout << "The Palindromes String has founded\n";
    for (const string &p : palindromes) {
        cout << p << endl;
    }
    cout << "Here is the number of Sub Palindrmes: " << palindromes.size() << endl;

    return 0;
}