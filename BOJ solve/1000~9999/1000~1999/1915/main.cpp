#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int n, m;
string arr[MAX];
int cache[MAX][MAX];
int getsquare() {
	int side = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0)
				cache[i][j] = arr[i][j] - '0';
			else if (arr[i][j] == '1')
				cache[i][j] = min(min(cache[i - 1][j], cache[i - 1][j - 1]), cache[i][j - 1]) + 1;
			side = max(side, cache[i][j]);
		}
	return side * side;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << getsquare() << '\n';
	return 0;
}
