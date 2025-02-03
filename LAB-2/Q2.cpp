#include <iostream>
using namespace std;
void modifyArray(void* arr, int n) {
    int* intArr = (int*)arr;
    for (int i = 0; i < n; i++) {
        intArr[i] += 10;
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    modifyArray(arr, n);
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;    
    return 0;
}
