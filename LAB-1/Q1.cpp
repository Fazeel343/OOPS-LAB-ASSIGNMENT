#include <iostream>
using namespace std;
int main() {
    float arr[20], max1 = -1e9, max2 = -1e9;
    float *ptr = arr;
    cout << "Enter 20 Float Numbers: ";
    for (int i = 0; i < 20; i++) {
        cin >> *(ptr + i);
    }
    for (int i = 0; i < 20; i++) {
        if (*(ptr + i) > max1) {
            max2 = max1;
            max1 = *(ptr + i);
        } else if (*(ptr + i) > max2 && *(ptr + i) < max1) {
            max2 = *(ptr + i);
        }
    }
    cout << "The Second Highest Number is: " << max2 << endl;
    return 0;
}