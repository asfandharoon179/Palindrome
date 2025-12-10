#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

string longestPalindrome(const string& s) {
    int n = s.length();
    if (n == 0) return "";

    int bestStart = 0;
    int bestLen = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            int length = j - i + 1;
            if (length > bestLen) {
                if (isPalindrome(s, i, j)) {
                    bestStart = i;
                    bestLen = length;
                }
            }
        }
    }

    return s.substr(bestStart, bestLen);
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    string result = longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
