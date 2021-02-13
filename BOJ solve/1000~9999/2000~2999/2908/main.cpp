#include <iostream>
using namespace std;

int main() {
    int index = 2;
    string A, B;
    cin >> A >> B;
    while (index >= 0) {
        if (A[index] == B[index]) {
            cout << A[index--];
            continue;
        }
        if (A[index] > B[index])
            while (index >= 0)
                cout << A[index--];
        else
            while (index >= 0)
                cout << B[index--];
    }
}