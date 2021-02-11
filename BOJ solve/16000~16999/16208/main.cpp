//30Á¡
#include <iostream>		// 16208
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int re = 0, num[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		re += num[i];
	}
	sort(num, num + n);
	long long result = 0;
	for (int i = 0; i < n - 1; i++) {
		re -= num[i];
		result += re * num[i];
	}
	cout << result;
}
// 4Á¡
/*
#include <iostream>		// 16208
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), less<int>());
	int ans = 0, sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum += a[j];
		}
		ans += a[i] * sum;
	}
	cout << ans << '\n';
	return 0;
}
*/