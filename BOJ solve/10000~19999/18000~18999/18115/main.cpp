#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	vector<int> v;
	deque<int> dq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		v.push_back(t);
	}
	int input = 1;
	reverse(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (v[i] == 1)
			dq.push_back(input);
		else if (v[i] == 2) {
			int t = dq[dq.size() - 1];
			dq.pop_back();
			dq.push_back(input);
			dq.push_back(t);
		}
		else if (v[i] == 3)
			dq.push_front(input);
		input++;
	}
	while (!dq.empty()) {
		cout << dq[dq.size() - 1] << ' ';
		dq.pop_back();
	}
	return 0;
}