#include <iostream>
#include <iomanip>

#define RAND_LIMIT 100
#define MAX_VALUE 1000

using namespace std;

int main () {
    double arr[1000] = {0};
    // assigning the random values to array 
    for (int i = 0; i < MAX_VALUE; i++) {
        arr[i] = rand() % RAND_LIMIT;
    }
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