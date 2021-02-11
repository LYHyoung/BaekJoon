#include <iostream>			// 2276
#include <vector>
#include <queue>
#define MAX 300
using namespace std;

int N, M, ans;
int cx[4] = { 0,0,1,-1 }; int cy[4] = { 1,-1,0,0 };
bool visited[MAX][MAX];
int adj[MAX][MAX];
bool flag;
struct node {
	int x, y, h;
	bool operator <(const node& a)const {		// 구조체 이용하여 priority_queue 사용
		return a.h < h;
	}
};

priority_queue<node> PQ;

void dfs(int x, int y, int height) {
	for (int i = 0; i < 4; i++) {
		int nx = x + cx[i];
		int ny = y + cy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;
		visited[nx][ny] = true;
		if (adj[nx][ny] > height) PQ.push({ nx,ny,adj[nx][ny] });
		else {
			ans += height - adj[nx][ny];
			dfs(nx, ny, height);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> adj[i][j];
			if (i == 0 || j == 0 || i == N-1 || j == M-1) {
				PQ.push({ i,j,adj[i][j] });
				visited[i][j] = true;
			}
		}
	}
	for (int i = 0; i < PQ.size(); i++) {
		int x = PQ.top().x;
		int y = PQ.top().y;
		int h = PQ.top().h;
		PQ.pop();
		cout << x << " :: " << y << " :: " << h << '\n';
	}
	while (!PQ.empty()) {
		int x = PQ.top().x;
		int y = PQ.top().y;
		PQ.pop();
		dfs(x, y, adj[x][y]);
	}
	cout << ans << '\n';
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 300

int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool visited[MAXN][MAXN];
int arr[MAXN][MAXN];
int ans;
bool flag;
struct node {
	int x, y, h;
	bool operator <(const node& a)const {
		return a.h < h;
	}
};
priority_queue<node> pq;
void dfs(int x, int y, int height) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;
		visited[nx][ny] = true;
		if (arr[nx][ny] > height) pq.push({ nx,ny,arr[nx][ny] });
		else {
			ans += height - arr[nx][ny];
			dfs(nx, ny, height);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (i == 0 || j == 0 || i == N - 1 || j == M - 1) {
				pq.push({ i,j,arr[i][j] });
				visited[i][j] = true;
			}
		}
	}
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();
		dfs(x, y, arr[x][y]);
	}
	cout << ans << "\n";
	return 0;
}*/