#include <iostream>
#include <vector>
#define MAX 55
using namespace std;

struct fireball {
	int x;// r 행,
	int y;// c 열
	int m;// m 질량
	int s;// d 방향
	int d;// s 속력
};

int N, M, K;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int All[] = { 0,2,4,6 };
int nAll[] = { 1,3,5,7 };

vector<fireball> v;
vector<fireball> map[MAX][MAX];

void check() {
	// setting the map
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j].clear();
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		int m = v[i].m;
		int s = v[i].s;
		int d = v[i].d;
		
		int mov = s % N;
		int nx = x + dx[d] * mov;
		int ny = y + dy[d] * mov;

		if (nx > N) nx -= N;
		if (ny > N) ny -= N;
		if (nx < 1) nx += N;
		if (ny < 1) ny += N;
		map[nx][ny].push_back({ nx,ny,m,s,d });
		v[i].x = nx;
		v[i].y = ny;
	}

	// Union fireball
	vector<fireball> t;		// temporary instance
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].size() == 0) continue; // no fireball inside
			if (map[i][j].size() == 1) {
				t.push_back(map[i][j][0]);
				continue;
			}

			int m_union = 0;
			int s_union = 0;
			int cnt = map[i][j].size();

			bool check_e = true, check_o = true;
			for (int k = 0; k < map[i][j].size(); k++) {
				m_union += map[i][j][k].m;
				s_union += map[i][j][k].s;
				if (map[i][j][k].d % 2 == 0) check_o = false;
				else check_e = false;
			}

			int m = m_union / 5;
			int s = s_union / cnt;

			if (m == 0) continue;
			if (check_e || check_o) {
				for (int k = 0; k < 4; k++) {
					t.push_back({ i,j,m,s,All[k] });
				}
			}
			else {
				for (int k = 0; k < 4; k++) {
					t.push_back({ i,j,m,s,nAll[k] });
				}
			}
		}
	}
	v = t;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> K;

	// input into fireball and map
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		v.push_back({ r,c,m,s,d });
		map[r][c].push_back({ r,c,m,s,d });
	}

	for (int i = 0; i < K; i++) {
		check();
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
		ans += v[i].m;

	cout << ans << '\n';

	return 0;
}