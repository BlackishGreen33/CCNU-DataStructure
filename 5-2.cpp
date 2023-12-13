#include <iostream>
using namespace std;

int findMissingPositive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    int n;
    cout << "请输入数组大小n: ";
    cin >> n;

    int arr[n];
    cout << "请输入" << n << "个整数: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int missingNumber = findMissingPositive(arr, n);
    cout << "未出现的最小正整数是: " << missingNumber << endl;

    return 0;
}