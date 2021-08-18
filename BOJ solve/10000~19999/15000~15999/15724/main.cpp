#include <iostream>
#define MAX 1025
#define ll long long
using namespace std;
int n, m, k;
ll arr[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp; cin >> temp;
			arr[i][j] = temp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	cin >> k;
	for (int test = 0; test < k; test++) {
		int x_1, y_1, x_2, y_2;
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cout << arr[x_2][y_2] - arr[x_1 - 1][y_2] - arr[x_2][y_1 - 1] + arr[x_1 - 1][y_1 - 1] << '\n';		
	}
	return 0;
}
