#include <iostream>
#include <algorithm>
#define MAX 20
#define INF 1e9
using namespace std;
int n, ans = INF;
int arr[MAX][MAX];
int check[MAX];
void DFS(int x, int pos) {
	if (x == n / 2) {
		int start, link;
		start = 0;
		link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i] == true && check[j] == true) start += arr[i][j];
				if (check[i] == false && check[j] == false) link += arr[i][j];
			}
		}
		int t = abs(start - link);
		if (ans > t) ans = t;
		return;
	}
	for (int i = pos; i < n; i++) {
		check[i] = true;
		DFS(x + 1, i + 1);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	DFS(0, 0);
	cout << ans << '\n';
	return 0;
}
