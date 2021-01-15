#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, sum = 0;
	cin >> N >> K;

	vector<int> p(N);
	for (int i = 0; i < N; i++)
		cin >> p[i];

	sort(p.begin(), p.end());
	vector<int> ans(N - 1);
	for (int j = 0; j < N - 1; j++) {
		int temp = abs(p[j] - p[j + 1]);
		ans[j] = temp;
	}
	
	sort(ans.begin(), ans.end());
	for (int k = 0; k < N - K; k++) {
		sum += ans[k];
	}

	cout << sum << '\n';

	return 0;
}