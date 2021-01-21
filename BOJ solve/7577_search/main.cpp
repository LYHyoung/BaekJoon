#include <iostream>			// 7577
#define MAX 41
#define INF 1e9
using namespace std;
int map[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, N; cin >> K >> N;
	for (int i = 0; i <= K; i++) 
		for (int j = 0; j <= K; j++) 
			if (i != j)
				map[i][j] = INF;
	for (int i = 0; i < K; i++) map[i + 1][i] = 0, map[i][i + 1] = 1;
	while (N--) {
		int x, y, r; cin >> x >> y >> r;
		if (map[x - 1][y] > r) map[x - 1][y] = r;		// 갱신도 가능?
		map[y][x - 1] = -r;
	}
	for (int s = 0; s <= K; s++)
		for (int i = 0; i <= K; i++)
			for (int j = 0; j <= K; j++)
				if (map[i][j] > map[i][s] + map[s][j])
					map[i][j] = map[i][s] + map[s][j];
	for (int i = 0; i <= K; i++) {
		if (map[i][i] < 0) {
			cout << "NONE" << '\n';
			return 0;
		}
	}
	for (int i = 0; i < K; i++) { 
		char t = map[0][i + 1] - map[0][i] ? '#' : '-';
		cout << t;
	}
	return 0;
}