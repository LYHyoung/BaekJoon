
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>		// 2645
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 51
#define INF 1000000000

int cost[MAX][MAX], dist[MAX][MAX];
int cx[4] = { 1,0,-1,0 }; int cy[4] = { 0,1,0,-1 };
pair<int, int> path[MAX][MAX];

void circuit(int k, int x1, int x2, int y1, int y2) {
	int w = 0;
	if (x1 == x2 && y1 < y2) w = 1;
	if (y1 == y2 && x1 > x2) w = 2;
	if (x1 == x2 && y1 > y2) w = 3;
	while (!(x1 == x2 && y1 == y2)) {
		cost[x1][y1] = k;
		x1 += cx[w];
		y1 += cy[w];
	}
	cost[x2][y2] = k;
}

int main() {
	int n, xf, yf, xs, ys, k, m;
	int start_x, start_y, end_x, end_y;
    scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		dist[i][j] = INF;
		cost[i][j] = 1;
	}
	scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
	scanf("%d", &k);
	scanf("%d", &m);
	while (m--) {
		int v_n;
		scanf(" %d", &v_n);
		v_n--; scanf("%d %d", &xf, &yf);
		while (v_n--) {
			scanf("%d %d", &xs, &ys);
			circuit(k, xf, xs, yf, ys); 
			xf = xs; yf = ys;
		}
	}
	priority_queue< pair<int, pair<int, int> > > PQ;
	dist[start_x][start_y] = cost[start_x][start_y];
	PQ.push({ -dist[start_x][start_y], {start_x,start_y} });
	while (!PQ.empty()) {
		int x1 = PQ.top().second.first;
		int y1 = PQ.top().second.second;
		int sum = -PQ.top().first;
		if (dist[x1][y1] < sum) continue;
		for (int i = 0; i < 4; i++) {
			int x2 = x1 + cx[i], y2 = y1 + cy[i];
			// 아래와 같은 새로운 방법으로도 다익스트라를 구현할 수 있다.
			if (x2 < 1 || x2 > n || y2 < 1 || y2 > n || dist[x2][y2] <= sum + cost[x2][y2]) continue;
			dist[x2][y2] = sum + cost[x2][y2];
            path[x2][y2] = { x1,x2 };
			PQ.push({ dist[x2][y2],{x2,y2} });
		}
	}
	printf("%d\n", dist[end_x][end_y]);
    vector<pair<int, int>> v;
    xf = end_x, yf = end_y;
    v.push_back({ xs,ys });
    while (!(xf == start_x && yf == start_y)) {
        xs = path[xf][yf].first, ys = path[xf][yf].second;
        while (1) {
            int x3 = path[xs][ys].first, y3 = path[xs][ys].second;
            if (!(xf == x3 || yf == y3)) break;
            xs = x3, ys = y3;
        }
        xf = xs, yf = ys;
        v.push_back({ xf,yf });
    }
    n = v.size();
    printf("%d ", n);
    for (int i = n - 1; i >= 0; i--)printf("%d %d ", v[i].first, v[i].second);
	return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define mxn 51
#define inf 1000000000

int dist[mxn][mxn], a[mxn][mxn];
int dr[4] = { 1,0,-1,0 }, dc[4] = { 0,1,0,-1 };
pair<int, int> path[mxn][mxn];

void circuit(int k, int r1, int c1, int r2, int c2) {
    int w = 0;
    if (r1 == r2 && c1 < c2) w = 1;
    if (c1 == c2 && r1 > r2) w = 2;
    if (r1 == r2 && c1 > c2) w = 3;
    while (!(r1 == r2 && c1 == c2)) { a[r1][c1] = k; r1 += dr[w]; c1 += dc[w]; }
    a[r2][c2] = k;
}
int main() {
    int n, sr, sc, er, ec, k, m, r1, r2, c1, c2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) { dist[i][j] = inf; a[i][j] = 1; }
    scanf("%d%d%d%d", &sr, &sc, &er, &ec);
    scanf("%d", &k);
    scanf("%d", &m);
    while (m--) {
        int cnt;
        scanf("%d", &cnt);
        cnt--; scanf("%d%d", &r1, &c1);
        while (cnt--) {
            scanf("%d%d", &r2, &c2);
            circuit(k, r1, c1, r2, c2);	  // 입력받은 회로를 간선 단위로 배치하는 함수
            r1 = r2, c1 = c2;
        }
    }
    // 다익스트라 알고리즘
    priority_queue< pair<int, pair<int, int> > > q;
    dist[sr][sc] = a[sr][sc];
    q.push({ -dist[sr][sc],{sr,sc} });
    while (!q.empty()) {
        r1 = q.top().second.first, c1 = q.top().second.second;
        int sum = -q.top().first;
        q.pop();
        if (dist[r1][c1] < sum) continue;
        for (int i = 0; i < 4; i++) {
            r2 = r1 + dr[i], c2 = c1 + dc[i];
            if (r2<1 || r2>n || c2<0 || c2>n || dist[r2][c2] <= sum + a[r2][c2]) continue;
            dist[r2][c2] = sum + a[r2][c2];	 // 최단거리 갱신
            path[r2][c2] = { r1,c1 };		// 경로저장
            q.push({ -dist[r2][c2],{r2,c2} });
        }
    }

    printf("%d\n", dist[er][ec]);
    vector< pair<int, int> > v;
    r1 = er, c1 = ec;
    v.push_back({ r1,c1 });
    while (!(r1 == sr && c1 == sc)) {
        r2 = path[r1][c1].first, c2 = path[r1][c1].second;
        while (1) {
            int r3 = path[r2][c2].first, c3 = path[r2][c2].second;
            if (!(r1 == r3 || c1 == c3)) break;
            r2 = r3, c2 = c3;
        }
        r1 = r2, c1 = c2;
        v.push_back({ r1,c1 });
    }
    n = v.size();
    printf("%d ", n);
    for (int i = n - 1; i >= 0; i--) printf("%d %d ", v[i].first, v[i].second);
    return 0;
}
*/