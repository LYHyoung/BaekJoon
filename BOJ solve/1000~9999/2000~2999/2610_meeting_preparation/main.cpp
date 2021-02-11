#include <iostream>		// 2610
#include <algorithm>
#define MAX 100+1
#define INF 1e9
#define f(i,l,r) for(int i=l;i<=r;i++)		// define for loop
using namespace std;
int map[MAX][MAX];
int N, M;
bool visit[MAX];
int sol(int i) {
	int mn = INF;
	int re;
	f(j, 1, N)if (map[i][j] != INF) {
		visit[j] = true;
		int tmp = 0;
		f(k, 1, N)if (map[j][k] != INF && tmp < map[j][k])tmp = map[j][k];
		if (mn > tmp) {
			mn = tmp;
			re = j;
		}
	}
	return re;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	f(i, 1, N) {			// unique setting job
		map[i][i] = 0;
		f(j, i + 1, N)
			map[i][j] = map[j][i] = INF;
	}
	while (M--) {
		int a, b; cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	f(k, 1, N)f(i, 1, N)f(j, 1 + 1, N)if (map[i][k] != INF && map[k][j] != INF)
		if (map[i][j] > map[i][k] + map[k][j])map[i][j] = map[j][i] = map[i][k] + map[k][j];
	int j = 0, ans[MAX];
	f(i, 1, N)if (!visit[i])ans[++j] = sol(i);
	cout << j << '\n';
	sort(ans + 1, ans + j + 1);
	f(i, 1, j)cout << ans[i] << '\n';
	return 0;
}