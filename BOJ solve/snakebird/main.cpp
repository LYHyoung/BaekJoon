#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, L;
	cin >> N >> L;
	vector<int> H(N);
	for (int i = 0; i < N; i++)
		cin >> H[i];
	sort(H.begin(), H.end());
	for (int i = 0; i < N; i++) {
		if (H[i] <= L) L += 1;
		else break;
	}
	cout << L;
	return 0;
}