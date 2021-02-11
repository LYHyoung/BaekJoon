#include <iostream>			// 2220
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 1; j /= 2) arr[j] = arr[j / 2];
		arr[1] = i + 1;
	}
	arr[n] = 1;

	for (int j = 1; j <= n; j++)
		cout << arr[j] << " ";

	return 0;
}