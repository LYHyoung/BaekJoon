#include <iostream>
#include<cstring>
#include <queue>
#include <vector>
#define MAX 1500
using namespace std;

int R, C;
bool Find;
char arr[MAX][MAX];
bool Visit[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> Swan_Q, Swan_NQ, Q, NQ;
pair<int, int> Swan_pos;

void Input() {
	Find = false;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 'X') Q.push({ i,j });
			if (arr[i][j] == 'L') {
				Swan_pos.first = i;
				Swan_pos.second = j;
			}
		}
	}
}

void Swan_BFS() {
	while (Swan_Q.empty() == 0 && Find == false) {
		int x = Swan_Q.front().first;
		int y = Swan_Q.front().second;
		Swan_Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (Visit[nx][ny] == false) {
					if (arr[nx][ny] == '.') {
						Visit[nx][ny] = true;
						Swan_Q.push({ nx,ny });
					}
					else if (arr[nx][ny] == 'L') {
						Visit[nx][ny] = true;
						Find = true;
						break;
					}
					else if (arr[nx][ny] == 'X') {
						Visit[nx][ny] = true;
						Swan_NQ.push({ nx,ny });
					}
				}
			}
		}
	}
}

void Water_BFS() {
	while (Q.empty() == 0) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (arr[nx][ny] == 'X') {
					arr[nx][ny] = '.';
					NQ.push({ nx,ny });
				}
			}
		}
	}
}

void Solution() {
	int day = 0;
	Swan_Q.push({ Swan_pos.first, Swan_pos.second });
	Visit[Swan_pos.first][Swan_pos.second] = true;
	while (Find == false) {
		Swan_BFS();
		if (Find == false) {
			Water_BFS();
			Q = NQ;
			Swan_Q = Swan_NQ;
			while (NQ.empty() == 0) NQ.pop();
			while (Swan_NQ.empty() == 0) Swan_NQ.pop();
			day++;
		}
	}
	cout << day << '\n';
}

void solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}