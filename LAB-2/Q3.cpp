#include <iostream>
#include <vector>
using namespace std;
void resizeArray(vector<int>& arr, int newSize) {
    arr.resize(newSize);
}
int main() {
    vector<int> array = {1, 2, 3, 4, 5};
    int newSize;
    cout << "Enter new size: ";
    cin >> newSize;
    resizeArray(array, newSize);
    cout << "Resized array size: " << array.size() << endl;
    return 0;
}
