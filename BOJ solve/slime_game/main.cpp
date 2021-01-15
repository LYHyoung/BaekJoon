#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, size, ans;
	cin >> N;

	vector<int> slime(N);
	for (int i = 0; i < N; i++)
		cin >> slime[i];

	sort(slime.begin(), slime.end(), less<int>());
	size = slime[0];
	ans = 0;
	for (int i = 1; i < N; i++) {
		int temp = size * slime[i];
		ans += temp;
		size += slime[i];
	}
	cout << ans;
	return 0;
}