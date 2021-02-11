#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 101
using namespace std;
int map[MAX][MAX];
int visited[MAX][MAX];
int M, N, K;
int dh[4] = { -1,1,0,0 };
int dw[4] = { 0,0,-1,1 };
vector<int> v;
void bfs(int h, int w) {
	int cnt = 1;
    queue<pair<int, int>> q;
	q.push({ h,w });
	visited[h][w] = cnt;
	while (!q.empty()) {
		h = q.front().first;
		w = q.front().second;
        q.pop();
		for (int i = 0; i < 4; i++) {
			int nh = h + dh[i];
			int nw = w + dw[i];
            if (nh >= 0 && nw >= 0 && nh < M && nw < N) {
                if (visited[nh][nw] == 0 && map[nh][nw] == 0) {
                    q.push({ nh,nw });
                    cnt++;
                    visited[nh][nw] = cnt;
                }
            }
		}
	}
	v.push_back(cnt);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int sw, sh, ew, eh; 
        cin >> sw >> sh >> ew >> eh;
		for (int w = sw; w < ew; w++) {
			for (int h = sh; h < eh; h++) {
				map[h][w] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}
/*
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k;
struct Pos {
    int x; int y;
};
int map[101][101];
int group[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

queue<Pos> q;//bfs���� �� ����(���� �������ִ� �������� ����)�� Ž���ϱ� ���� ��ǥ�� �ֱ����� ť
vector<int> v_ans;//������ ������, ������ ���̸� �޾Ƴ��� ���� ����

void bfs(int x, int y) {
    int cnt = 1; //������ 1�� ���־��, (0.0)�� map==0 �϶� 1�� �� �� ����
    q.push({ x,y });
    group[x][y] = cnt; //main�Լ����� ������������ �޾ƿ� x,y ��ġ�� �ش� ������ ���° ĭ���� cnt�� ����.

    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (map[nx][ny] == 0 && group[nx][ny] == 0) {
                    q.push({ nx, ny });
                    cnt++;
                    group[nx][ny] = cnt;//cnt�� ������ ������.
                }
            }
        }
    }
    v_ans.push_back(cnt);//while���� �����ԵǸ� cnt�� ���� �ᱹ �� ������ ���̰��� �ȴ�.
}

int main() {
    cin >> m >> n >> k; //��� ��

    for (int i = 0; i < k; i++) { //�簢�� ������ 1�� �ֱ�.

        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;

        for (int j = startX; j < endX; j++) {
            for (int t = startY; t < endY; t++) {
                map[t][j] = 1;//�־��� �簢���� 1�� ������ش�.
            }
        }
    }

    //bfs�� ���� ���ϱ� -> ������ ���Ϸ��� ��¿������ ��� map�� �� ���ƺ�����
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0 && group[i][j] == 0) { //group�� �湮üũ�� ������ �Ѵ�.
                bfs(i, j);
            }
        }
    }
    sort(v_ans.begin(), v_ans.end());// �����ؼ� ����϶�� �����Ƿ�

    cout << v_ans.size() << "\n";//������ ������ = ������ ����

    for (int i = 0; i < v_ans.size(); i++) {
        cout << v_ans[i] << " ";
    }
    return 0;
}
*/