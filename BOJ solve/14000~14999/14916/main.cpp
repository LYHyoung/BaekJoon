#include <iostream>		// 14916

using namespace std;

int main() {
	int N;
	cin >> N;
	int change = 0;
	while (N > 0) {
		if (N > 8) {
			change++;
			N -= 5;
		}
		else {
			if (N % 2 == 0) {
				change++;
				N -= 2;
			}
			else {
				change++;
				N -= 5;
			}
		}
	}
	if (N < 0) printf("%d", -1);
	else printf("%d", change);
	return 0;
}

//https://jeongminhee99.tistory.com/88
/*
#include<iostream>
using namespace std;

int main() {

	int n, result;
	cin >> n;
	int o = n % 5;
	if (n == 1 || n == 3) {
		result = -1;
	}
	else if (o % 2 == 0) {
		result = n / 5 + o / 2;
	}
	else {
		result = ((n / 5) - 1) + ((o + 5) / 2);
	}

	cout << result;
	return 0;
}
*/