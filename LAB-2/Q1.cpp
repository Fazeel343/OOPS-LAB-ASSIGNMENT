#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int sum = 0;
    int *ptr = arr;
    for (int i = 0; i < n; i++) {
        sum += *(ptr + i);
    }
    
    cout << "Sum of elements: " << sum << endl;
    return 0;
}
