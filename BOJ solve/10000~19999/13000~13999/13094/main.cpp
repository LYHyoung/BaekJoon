#include <iostream>		// 13094
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int end, N, ans=0;
	int score, deadline;
	int result[1001];
	memset(result, 0, sizeof(result));
	cin >> N;
	vector<pair<int, int>> W;
	for (int i = 0; i < N; i++) {
		cin >> deadline >> score;
		W.push_back({ score,deadline });	// pair 넣는 방법
		//cin >> W[i].second;
		//cin >> W[i].first;
	}
	sort(W.begin(), W.end(), greater<pair<int,int>>());
	//vector<int> result(N,0);		// save
	for (int i = 0; i < N; i++) {
		end = W[i].second;
		while (end >= 1) {
			if (result[end] == 0) {
				result[end] = W[i].first;
				break;
			}
			else
				--end;
		}
		/*		// what i first made
		if (result[end] == 0)
			result[end] = W[i].first;
		else {
			int pos = W[i].first;
			while (result[pos] != 0) {
				pos--;
			}
			if (pos < 1) continue;
			result[pos] = W[i].second;
		}
		*/
	}
	for (int i = 0; i < 1001; i++)
		ans += result[i];
	cout << ans;
	return 0;
}