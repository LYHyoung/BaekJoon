#include <iostream>
#include <algorithm>
using namespace std;
int nums[200001];
int cnt[100001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> nums[i];
	int s = 0, e = 0;
	int result = 0;
	while (s < N) {
		if (cnt[nums[s]] != K) {
			cnt[nums[s]]++;
			s++;
		}
		else {
			cnt[nums[e]]--;
			e++;
		}
		result = max(result, s - e);
	}
	cout << result << '\n';
	return 0;
}
