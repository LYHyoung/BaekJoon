#include <iostream>
#include <string>
#include <queue>
#define MAX 11
using namespace std;

int N, M;
int rx, ry, bx, by;
int hx, hy;
int ans = 0;
bool flag;
char map[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];
int dy[4] = { 0,0,-1,1 }, dx[4] = { -1,1,0,0 };
queue<pair<int, int>> redball;
queue<pair<int, int>> blueball;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'R') {
				redball.push({ i,j });
				rx = i;
				ry = j;
			}
			else if (map[i][j] == 'B') {
				blueball.push({ i,j });
				bx = i;
				by = j;
			}
			if (map[i][j] == 'O') hx = i, hy = j;
		}
	}
	visited[rx][ry][bx][by] = true;
	while (!redball.empty()) {
		int qsize = redball.size();
		while (qsize--) {
			rx = redball.front().first;
			ry = redball.front().second;
			bx = blueball.front().first;
			by = blueball.front().second;
			redball.pop(); blueball.pop();
			// 10번 이상 탑색 : break
			if (ans > 10) break;
			// 빨간 구슬이 구멍에 빠지면 : break
			if (rx == hx && ry == hy) {
				flag = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nrx = rx + dx[i];
				int nry = ry + dy[i];
				int nbx = bx + dx[i];
				int nby = by + dy[i];
				// 구슬 움직이기
				while (1) {
					if (map[nrx][nry] == '#') {
						nrx -= dx[i]; nry -= dy[i];
						break;
					}
					if (map[nrx][nry] == 'O') break;
					nrx += dx[i]; nry += dy[i];
				}
				while (1) {
					if (map[nbx][nby] == '#') {
						nbx -= dx[i]; nby -= dy[i];
						break;
					}
					if (map[nbx][nby] == 'O') break;
					nbx += dx[i]; nby += dy[i];
				}
				if (nbx == hx && nby == hy) continue;
				if (nrx == nbx && nry == nby) {
					switch (i) {
					case 0: rx > bx ? nrx++ : nbx++; break;
					case 1: rx < bx ? nrx-- : nbx--; break;
					case 2: ry > by ? nry++ : nby++; break;
					case 3: ry < by ? nry-- : nby--; break;
					}
				}
				// visite 하지 않았을때 : push
				if (visited[nrx][nry][nbx][nby]) continue;
				redball.push({ nrx,nry });
				blueball.push({ nbx, nby });
				visited[nrx][nry][nbx][nby] = true;
			}
		}
		if (flag) break;
		else ans++;
	}
	if (flag) cout << ans;
	else cout << -1;
	return 0;
}