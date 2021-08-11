#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	map<string, bool> visited;
	int cnt = 0;
	
	do {
		string s = "";
		for (int i = 0; i < k; i++) {
			s += to_string(v[i]);
		}
		if (visited.count(s) == false) {
			visited[s] = true;
			cnt++;
		}

	} while (next_permutation(v.begin(), v.end()));

	cout << cnt << '\n';
	return 0;
}