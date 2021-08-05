#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	vector<int> v;
	for (int i = 0; i < 9; i++) {
		int t; cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());	// 오름차순
	int i, j, t;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			t = 0;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) continue;
				t += v[k];
			}
			if (t == 100) break;
		}
		if (t == 100) break;
	}
	//cout << "i: " << i << " j: " << j << '\n';
	for (int k = 0; k < 9; k++) {
		if (k == i || k == j) continue;
		cout << v[k] << '\n';
	}

	return 0;
}