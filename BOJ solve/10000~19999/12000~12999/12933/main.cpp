#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	string str; cin >> str;
	vector<int> v;
	vector<int> num(6, 0);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'q') {
			v.push_back(1);
			num[1]++;
		}
		else if (str[i] == 'u') {
			v.push_back(2);
			num[2]++;
		}
		else if (str[i] == 'a') {
			v.push_back(3);
			num[3]++;
		}
		else if (str[i] == 'c') {
			v.push_back(4);
			num[4]++;
		}
		else if (str[i] == 'k') {
			v.push_back(5);
			num[5]++;
		}
	}
	if (num[1] != num[2] || num[1] != num[3] || num[1] != num[4] || num[1] != num[5]) {
		cout << -1 << '\n';
		return 0;
	}
	vector<vector<int>>duck;
	vector<int>cnt;
	for (int i = 0; i < str.size(); i++) {
		int now = v[i];
		bool flag = false;
		if (now == 1) {
			for (int k = 0; k < duck.size(); k++) {
				if (duck[k].empty()) {
					duck[k].push_back(1);
					flag = true;
					break;
				}
			}
			if (flag) continue;
			vector<int>s;
			s.push_back(1);
			duck.push_back(s);
			cnt.push_back(0);
			continue;
		}
		bool err = true;
		for (int j = 0; j < duck.size(); j++) {
			if (duck[j].empty()) continue;
			if (duck[j].back() == now - 1) {
				duck[j].push_back(now);
				err = false;
				if (duck[j].size() == 5) {
					duck[j].clear();
					cnt[j]++;
				}
				break;
			}
		}
		if (err) {
			cout << -1 << '\n';
			return 0;
		}
	}
	int res = 0;
	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i] > 0)
			res++;
	}
	if (res == 0)
		cout << -1 << '\n';
	else
		cout << res;

	return 0;
}