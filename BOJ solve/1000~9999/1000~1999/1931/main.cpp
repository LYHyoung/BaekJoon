#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(), comp);
	int cnt = 1;
	int temp = v[0].second;
	for (int i = 1; i < N; i++) {
		if (v[i].first < temp) 
			continue;
		else {
			temp = v[i].second;
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}