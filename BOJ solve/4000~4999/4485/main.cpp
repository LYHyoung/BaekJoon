#include <iostream>
#include <queue>
#define MAX 125
#define INF 654321
using namespace std;

int MAP[MAX][MAX];
int DIST[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int ans;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	priority_queue < pair<int, pair<int, int>>> PQ;

	while (++cnt) {
		int N;
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> MAP[i][j];
				DIST[i][j] = INF;
			}
		}
		DIST[0][0] = MAP[0][0];
		PQ.push(make_pair(-MAP[0][0], make_pair(0, 0)));
		while (PQ.empty() == 0) {
			int cost = -PQ.top().first;
			int x = PQ.top().second.first;
			int y = PQ.top().second.second;
			PQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
					int ncost = cost + MAP[nx][ny];
					if (DIST[nx][ny] > ncost) {
						DIST[nx][ny] = ncost;
						PQ.push(make_pair(-DIST[nx][ny], make_pair(nx, ny)));
					}
				}
			}
		}
		ans = DIST[N - 1][N - 1];
		cout << "Problem " << cnt << ": " << ans << '\n';
	}

	return 0;
}