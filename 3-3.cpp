#include <iostream>
#include <stack>

using namespace std;

bool isStackOrderValid(const int pushSequence[], const int popSequence[], int size) {
    stack<int> stk;
    int pushIndex = 0;
    int popIndex = 0;

    while (pushIndex < size) {
        stk.push(pushSequence[pushIndex]);
        pushIndex++;

        while (!stk.empty() && stk.top() == popSequence[popIndex]) {
            stk.pop();
            popIndex++;
        }
    }

    return stk.empty() && popIndex == size;
}

void describeStackOperations(const int pushSequence[], const int popSequence[], int size) {
    stack<int> stk;
    int pushIndex = 0;
    int popIndex = 0;

    while (pushIndex < size) {
        stk.push(pushSequence[pushIndex]);
        pushIndex++;
        cout << pushSequence[pushIndex - 1] << " 入栈" << endl;

        while (!stk.empty() && stk.top() == popSequence[popIndex]) {
            stk.pop();
            popIndex++;
            cout << popSequence[popIndex - 1] << " 出栈" << endl;
        }
    }
}

int main() {
    int pushSequence1[] = {1, 2, 3};
    int popSequence1[] = {2, 1, 3};

    int size1 = sizeof(pushSequence1) / sizeof(pushSequence1[0]);

    bool isValid1 = isStackOrderValid(pushSequence1, popSequence1, size1);
    cout << "出栈顺序是否成立? " << (isValid1 ? "是" : "否") << endl;

    if (isValid1) {
        cout << "出入栈的过程：" << endl;
        describeStackOperations(pushSequence1, popSequence1, size1);
    }

    cout << endl;

    int pushSequence2[] = {1, 2, 3};
    int popSequence2[] = {2, 3, 1};

    int size2 = sizeof(pushSequence2) / sizeof(pushSequence2[0]);

    bool isValid2 = isStackOrderValid(pushSequence2, popSequence2, size2);
    cout << "出栈顺序是否成立? " << (isValid2 ? "是" : "否") << endl;

    if (isValid2) {
        cout << "出入栈的过程：" << endl;
        describeStackOperations(pushSequence2, popSequence2, size2);
    }

    return 0;
}