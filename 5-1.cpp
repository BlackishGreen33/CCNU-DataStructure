#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateLeft(int arr[], int n, int p) {
    p = p % n;

    reverse(arr, 0, p - 1);
    reverse(arr, p, n - 1);
    reverse(arr, 0, n - 1);
}

int main() {
    int n, p;
    cout << "请输入数组大小n: ";
    cin >> n;

    int arr[n];
    cout << "请输入" << n << "个整数: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "请输入左移位数p: ";
    cin >> p;

    rotateLeft(arr, n, p);

    cout << "左移后的数组为: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}