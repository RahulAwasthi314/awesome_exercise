#include <iostream>

using namespace std;

int main () {
    double arr[1000] = {0};
    for (int i = 0; i < 1000; i++) {
        if (i % 10 == 0) {
            cout << endl;
            cout << i + 10 << " ";
        }
        cout << arr[i] << " "; 
    }
    return 0;
}