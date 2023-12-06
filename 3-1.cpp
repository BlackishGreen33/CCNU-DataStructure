#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool areParenthesesBalanced(const string &expr) {
    stack<char> stk;

    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty()) {
                return false;
            }

            char top = stk.top();
            stk.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stk.empty();
}

int main() {
    string expr1 = "(12+45)";
    string expr2 = "23+[87a-45b(5*6)]";
    string expr3 = "23+[87a-(45b]5*6)";

    bool result1 = areParenthesesBalanced(expr1);
    bool result2 = areParenthesesBalanced(expr2);
    bool result3 = areParenthesesBalanced(expr3);

    cout << "Expression 1 parentheses balanced? " << (result1 ? "Yes" : "No") << endl;
    cout << "Expression 2 parentheses balanced? " << (result2 ? "Yes" : "No") << endl;
    cout << "Expression 3 parentheses balanced? " << (result3 ? "Yes" : "No") << endl;

    return 0;
}