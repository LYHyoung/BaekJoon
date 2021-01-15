#include <iostream>				//2262
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, sum = 0;
	cin >> n;
	vector<int> p(n);
	
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < n - 1; i++) {
		int size = n - i;
		int max = 0;
		int dif;
		int idx;
		for (int j = 0; j < size; j++) {
			if (max < p[j]) {
				idx = j;
				max = p[j];
			}
		}
		if (idx == 0) {
			dif = abs(p[idx] - p[idx + 1]);
		}
		else if (idx == size - 1) {
			dif = abs(p[idx] - p[idx - 1]);
		}
		else {
			int temp = p[idx - 1] > p[idx + 1] ? p[idx - 1] : p[idx + 1];
			dif = abs(p[idx] - temp);
		}

		sum += dif;

		for (int j = idx; j < size - 1; j++) {
			p[j] = p[j + 1];
		}
	}

	cout << sum << '\n';

	return 0;
}