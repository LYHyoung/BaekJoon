#include <iostream>		// 17224
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, L, K;
	int success = 0, score = 0;
	cin >> N >> L >> K;
	vector<pair<int, int>> sub;
	int sub1, sub2;
	for (int i = 0; i < N; i++) {
		cin >> sub1 >> sub2;
		sub.push_back({ sub2,sub1 });
	}
	sort(sub.begin(), sub.end(), less<>());
	/*
	for (int i = 0; i < N; i++) {
		cout << sub[i].first << ", " << sub[i].second << endl;
	}
	*/
	for (int i = 0; i < N; i++) {
		if (success < K) {
			if (sub[i].first <= L) {
				score += 140;
				success++;
			}
			else if (sub[i].second <= L) {
				success++;
				score += 100;
			}
		}
		else break;
	}
	cout << score;
	return 0;
}