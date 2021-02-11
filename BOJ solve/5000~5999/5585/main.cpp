#include <iostream>
#include <vector>
using namespace std;

int change(vector<int> coin, int re) {
	int ans = 0;
	for (int i = coin.size()-1; i >= 0; i--) {
		if (re <= 0) break;
		if (coin[i] > re) continue;
		while (coin[i] <= re) {
			re -= coin[i];
			ans++;
		}
	}
	return ans;
}

int main() {
	int buy;
	cin >> buy;
	int re = 1000 - buy;

	vector<int> coin(6);
	coin[0] = 1;
	coin[1] = 5;
	coin[2] = 10;
	coin[3] = 50;
	coin[4] = 100;
	coin[5] = 500;

	cout << change(coin,re);

	return 0;
}