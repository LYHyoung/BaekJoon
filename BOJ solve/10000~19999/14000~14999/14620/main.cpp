#include <iostream>
#include <algorithm>
#define MAX 10
#define INF 1e9
using namespace std;

int N;
int ans = INF;
int arr[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool whole_check(int x, int y) {
	if (visit[x][y])
		return false;

	for (int idx = 0; idx < 4; idx++) {
		int nx = x + dx[idx];
		int ny = y + dy[idx];
		if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1 || visit[nx][ny])
			return false;
	}

	return true;
}

void dfs(int count, int sum, int start_i) {
    if (count == 3) {
        if (ans > sum) {
            ans = sum;
        }
        return;
    }

    for (int i = start_i; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!whole_check(i, j)) {
                continue;
            }

            int s = arr[i][j];
            visit[i][j] = true;
            for (int idx = 0; idx < 4; idx++) {
                int i1 = i + dx[idx];
                int j1 = j + dy[idx];
                visit[i1][j1] = true;
                s += arr[i1][j1];
            }

            dfs(count + 1, sum + s, i);

            visit[i][j] = false;
            for (int idx = 0; idx < 4; idx++) {
                int i1 = i + dx[idx];
                int j1 = j + dy[idx];
                visit[i1][j1] = false;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	dfs(0, 0, 1);
	cout << ans << '\n';
	return 0;
}