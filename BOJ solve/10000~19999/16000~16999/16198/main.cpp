#include <iostream>
#include <vector>
using namespace std;
int n, ans;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		v.push_back(t);
	}

	cout << ans << '\n';
	return 0;
}