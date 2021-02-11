#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25+1
using namespace std;
int map[MAX][MAX];
vector<int> complex;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int N, cnt;
void DFS(int x, int y) {
	map[x][y] = 0;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
			if (map[nx][ny] == 1) {
				DFS(nx, ny);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string line; cin >> line;
		for (int j = 1; j <= N; j++)
			map[i][j] = (int)line[j - 1] - 48;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] == 1) {
				cnt = 0;
				DFS(i, j);
				complex.push_back(cnt);
			}
	sort(complex.begin(), complex.end());
	cout << complex.size() << '\n';
	for (int i = 0; i < complex.size(); i++) {
		cout << complex[i] << '\n';
	}
	return 0;
}