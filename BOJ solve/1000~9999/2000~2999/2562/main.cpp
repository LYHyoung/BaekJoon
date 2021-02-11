#include <iostream>
using namespace std;
int main() {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	int temp = arr[0];
	int idx = 0;
	for (int i = 1; i < 9; i++) {
		if (temp < arr[i]) {
			temp = arr[i];
			idx = i;
		}
	}
	cout << temp << '\n' << idx + 1;
}