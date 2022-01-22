#include <iostream>
#include <iomanip>
#define MAX_VALUE 1000

using namespace std;

int main () {
    double arr[1000] = {0};

    // printing the values to verify
    for (int i = 0; i < 1000; i++) {
        if (i % 10 == 0) {
            cout << endl;
            cout << setw(4) << i + 10 << setfill(' ') << "   ";
        }
        cout << setw(2) << arr[i] << setfill(' ') << " ";
    }
    return 0;
}