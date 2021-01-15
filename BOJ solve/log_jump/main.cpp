#include <iostream>		// 11497
#include <algorithm>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int* a = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		sort(a, a + n);
		int result = 0;
		for (int k = 2; k < n; k++) {
			int c = a[k] - a[k - 2];
			result = max(result, c);
		}
		cout << result << '\n';

	}
	return 0;
}
/*
int difficulty(int* L) {
	int size = sizeof(L) - 1;
	for (int i = 0; i < size / 2; i++) {
		for (int j = i; j < size - i; j++) {
			if (L[i] > L[j]) {
				int temp = L[i];
				L[i] = L[j];
				L[j] = temp;
			}
		}
		for (int j = i + 1; j < size - i; j++) {
			if (L[size - i] > L[j]) {
				int temp = L[size - i];
				L[size - i] = L[j];
				L[j] = temp;
			}
		}
	}
	int ans = abs(L[0] - L[size]);
	for (int i = 0; i < size - 1; i++) {
		ans = max(ans, (int)abs(L[i] - L[i + 1]));
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	int* L[] = { 0, };
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> L[i][j];
	}
	for (int i = 0; i < T; i++)
		cout << difficulty(L[i]) << '\n';
	return 0;
}
*/