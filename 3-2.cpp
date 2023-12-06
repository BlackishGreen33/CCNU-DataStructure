#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(const string &str) {
    stack<char> stk;

    int length = str.length();
    int halfLength = length / 2;
    for (int i = 0; i < halfLength; i++) {
        stk.push(str[i]);
    }

    int startIndex = (length % 2 == 0) ? halfLength : halfLength + 1;
    for (int i = startIndex; i < length; i++) {
        if (str[i] != stk.top()) {
            return false;
        }
        stk.pop();
    }

    return stk.empty();
}

int main() {
    string str1 = "123654";
    string str2 = "12321";

    bool result1 = isPalindrome(str1);
    bool result2 = isPalindrome(str2);

    cout << str1 << " is palindrome? " << (result1 ? "Yes" : "No") << endl;
    cout << str2 << " is palindrome? " << (result2 ? "Yes" : "No") << endl;

    return 0;
}