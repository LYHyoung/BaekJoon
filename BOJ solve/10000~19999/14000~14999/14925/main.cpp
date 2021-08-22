#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int m, n;
int arr[MAX][MAX];
int cache[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int getLength() {
	int side = 0;
	for (int y=1;y<=m;y++)
		for (int x=1;x<=n;x++)
			if (arr[y][x] == 0) {
				cache[y][x] = min(min(cache[y - 1][x], cache[y - 1][x - 1]), cache[y][x - 1]) + 1;
				side = max(side, cache[y][x]);
			}
	return side;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	cout << getLength() << '\n';
	return 0;
}
