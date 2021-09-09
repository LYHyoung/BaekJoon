/*#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000
using namespace std;

int N, M, P;
int mv[10];		// player's move
int cnt[10];	// player's cnt
bool End[10];	// player's end flag
char MAP[MAX][MAX];		// MAP
queue<pair<pair<int, int>, int>> Q[10];		// player queue

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool BFS(int idx) {
	bool Temp_Flag = false;
	queue<pair<pair<int, int>, int>> NQ = Q[idx];
	while (NQ.empty() == 0) {
		int x = NQ.front().first.first;
		int y = NQ.front().first.second;
		int Cnt = NQ.front().second;
		NQ.pop();
		if (Cnt == mv[idx]) Q[idx].pop();		// 원래 존재했던 성이라면, 새롭게 생긴 섬이 아니기 때문에 더이상 관리 X.
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nCnt = Cnt;
			if (nCnt == 0) break;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (MAP[nx][ny] == '.') {
					MAP[nx][ny] = idx + '0';
					cnt[idx]++;
					Q[idx].push(make_pair(make_pair(nx, ny), mv[idx]));
					NQ.push(make_pair(make_pair(nx, ny), nCnt - 1));
					Temp_Flag = true;
				}
			}
		}
	}
	return Temp_Flag;
}

bool check() {
	for (int i = 1; i <= P; i++)
		if (End[i] == true)
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> mv[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if ('1' <= MAP[i][j] && MAP[i][j] <= '9') {
				Q[MAP[i][j] - '0'].push(make_pair(make_pair(i, j), mv[MAP[i][j] - '0']));
				cnt[MAP[i][j] - '0']++;
			}
		}
	}
	memset(End, true, sizeof(End));

	while (1) {
		for (int i = 1; i <= P; i++) {
			if (End[i] == false) continue;
			bool tmp_flag = BFS(i);
			if (tmp_flag == false) End[i] == false;
		}
		if (check() == false) break;
	}
	for (int i = 1; i <= P; i++)
		cout << cnt[i] << " ";
	cout << '\n';

	return 0;
}*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define endl "\n"
#define MAX 1000
#define P_MAX 10
using namespace std;
int N, M, P;
int Move_Area[P_MAX];
int Count_Area[P_MAX];
bool Visit[MAX][MAX];
bool Flag[P_MAX];
char MAP[MAX][MAX];
queue<pair<pair<int, int>, int>> Q[P_MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void Input() {
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> Move_Area[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if ('1' <= MAP[i][j] && MAP[i][j] <= '9') {
				Q[MAP[i][j] - '0'].push(make_pair(make_pair(i, j), Move_Area[MAP[i][j] - '0']));
				Count_Area[MAP[i][j] - '0']++;
			} // 이 Queue의 의미 = Idx번 플레이어의 성은 (i, j)에서 Move_Area[MAP[i][j])만큼 확장해 나갈 수 있습니다.
		}
	}
	memset(Flag, true, sizeof(Flag));
}
bool BFS(int Idx) {
	bool Temp_Flag = false;
	queue<pair<pair<int, int>, int>> NQ = Q[Idx];
	while (NQ.empty() == 0) {
		int x = NQ.front().first.first;
		int y = NQ.front().first.second;
		int Cnt = NQ.front().second;
		NQ.pop();
		if (Cnt == Move_Area[Idx]) Q[Idx].pop(); // 원래 존재했던 성이라면, 새롭게 생긴 섬이 아니기 때문에 더이상 관리 X.
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nCnt = Cnt;
			if (nCnt == 0) break;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (MAP[nx][ny] == '.') {
					MAP[nx][ny] = Idx + '0';
					Count_Area[Idx]++;
					Q[Idx].push(make_pair(make_pair(nx, ny), Move_Area[Idx]));
					NQ.push(make_pair(make_pair(nx, ny), nCnt - 1));
					Temp_Flag = true;
				}
			}
		}
	}
	return Temp_Flag;
}
bool Check()
{
	for (int i = 1; i <= P; i++)
		if (Flag[i] == true)
			return true;
	return false;
}
void Solution()
{
	while (1) {
		for (int i = 1; i <= P; i++) {
			if (Flag[i] == false) continue;
			bool Temp_Flag = BFS(i);
			if (Temp_Flag == false) Flag[i] = false;
			// Print();
		}
		if (Check() == false) break;
	}
	for (int i = 1; i <= P; i++) {
		cout << Count_Area[i] << " ";
	}
	cout << endl;
}
void Solve()
{
	Input();
	Solution();
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
