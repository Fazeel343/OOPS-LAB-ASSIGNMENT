#include <iostream>
using namespace std;
int main() {
    int k, arr[10], *ptr = arr, sum = 0;
    cout << "Enter the Total Number of Integers: ";
    cin >> k;
    cout << "Enter " << k <<  " Integers: ";
    for (int i = 0; i < k; i++) {
        cin >> *(ptr + i);
        sum += *(ptr + i);
    }
    cout << "The Sum of the Array Elements is: " << sum << endl;
    return 0;
}
