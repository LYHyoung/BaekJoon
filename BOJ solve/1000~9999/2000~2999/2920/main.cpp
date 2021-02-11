#include <iostream>
using namespace std;
int main() {
	int check[8];
	for (int i = 0; i < 8; i++) {
		cin >> check[i];
	}
	int asc = 0, des = 0;
	for (int i = 0; i < 4; i++) {
		if (check[i] + check[7 - i] == 9 && check[i] == i + 1) {
			asc++;
		}
		else if (check[7 - i] == i + 1 && check[i] + check[7 - i] == 9) {
			des++;
		}
	}
	if (asc == 4)
		cout << "ascending";
	else if (des == 4)
		cout << "descending";
	else
		cout << "mixed";
	return 0;
}