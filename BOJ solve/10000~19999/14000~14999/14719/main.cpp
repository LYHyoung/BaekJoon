#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;
int h, w, ans;
int Height[MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w;
	for (int i = 1; i <= w; i++) cin >> Height[i];

	for (int i = 2; i < w; i++) {
		int left = 0, right = 0;
		for (int j = 1; j < i; j++) left = max(left, Height[j]);
		for (int j = i + 1; j <= w; j++) right = max(right, Height[j]);
		int result = min(left, right) - Height[i];
		if (result >= 0) ans += result;
	}
	cout << ans << '\n';

	return 0;
}