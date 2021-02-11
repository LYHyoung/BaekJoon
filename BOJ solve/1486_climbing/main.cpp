#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;
vector<int> num;
int map[MAX][MAX];
int map2[1010];
int cost[1010][1010];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, T, D; cin >> N >> M >> T >> D;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	for (int i = 1; i <= N; i++) {
		string line; cin >> line;
		for (int j = 1; j <= M; j++) {
			num.push_back(i * M + j);
			if (line[j - 1] >= 'A' && line[j - 1] <= 'Z')
				map[i][j] = line[j - 1] - 'A';
			else
				map[i][j] = line[j - 1] - 'a' + 26;
			map2[i * M + j] = map[i][j];
		}
	}
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
			if (i != j)
				cost[i][j] = INF;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
				int s = i * M + j, e = nx * M + ny;
				if (abs(map[i][j] - map[nx][ny]) > T) continue;
				if (map[i][j] >= map[nx][ny]) cost[s][e] = 1;
				else cost[s][e] = (map[i][j] - map[nx][ny]) * (map[i][j] - map[nx][ny]);
			}
	for (auto k : num)
		for (auto i : num)
			for (auto j : num)
				if (cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
	int ans = 0;
	for (auto k : num) {
		if (cost[M+1][k] + cost[k][M+1] <= D)
			ans = max(ans, map2[k]);
	}
	cout << ans;
	return 0;
}