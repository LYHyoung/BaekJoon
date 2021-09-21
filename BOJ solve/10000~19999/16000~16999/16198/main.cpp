#include <iostream>
#include <vector>
using namespace std;

int n, ans, temp_ans;
vector<int> v;

void select_ball() {
	if (v.size() == 2) {
		if (ans < temp_ans) ans = temp_ans;
		return;
	}
	for (int i = 1; i < v.size() - 1; i++) {
		int select = v.at(i);
		temp_ans = temp_ans + v.at(i - 1) * v.at(i + 1);
		v.erase(v.begin() + i);
		select_ball();
		v.insert(v.begin() + i, select);
		temp_ans = temp_ans - v.at(i - 1) * v.at(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		v.push_back(t);
	}
	select_ball();
	cout << ans << '\n';
	return 0;
}
