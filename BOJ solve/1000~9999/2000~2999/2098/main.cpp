#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 16
#define INF 987654321
using namespace std;

int N, ans_bit;
int map[MAX][MAX];
int cost[MAX][1 << MAX];

int DFS(int cur_node, int cur_bit) {
	if (cur_bit == ans_bit) {
		if (map[cur_node][0] == 0) return INF;
		else return map[cur_node][0];
	}

	if (cost[cur_node][cur_bit] != -1) return cost[cur_node][cur_bit];
	cost[cur_node][cur_bit] = INF;
	
	for (int i = 0; i < N; i++) {
		if (map[cur_node][i] == 0) continue;
		if ((cur_bit & (1 << i)) == (1 << i)) continue;

		cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit], map[cur_node][i] + DFS(i, cur_bit | 1 << i));
	}
	return cost[cur_node][cur_bit];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];
	ans_bit = (1 << N) - 1;

	memset(cost, -1, sizeof(cost));
	cout << DFS(0, 1) << '\n';

	return 0;
}