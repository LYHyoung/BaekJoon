#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<pair<ll, ll>> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());

	vector<int> stk;
	vector<pair<ll, ll>> pole;
	for (int i = 0; i < N; i++) {
		if (stk.empty() || stk.back() < v[i].second) {
			pole.push_back({ stk.size(), v[i].first });
			stk.push_back(v[i].second);
		}
		else {
			auto iter = lower_bound(stk.begin(), stk.end(), v[i].second);
			*iter = v[i].second;
			pole.push_back({ iter - stk.begin(), v[i].first });
		}
	}

	vector<int> ans;
	for (int i = pole.size() - 1, j = stk.size() - 1; i >= 0; i--) {
		if (pole[i].first == j) j--;
		else ans.push_back(pole[i].second);
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i : ans)				// 기억하기
		cout << i << '\n';

	return 0;
}