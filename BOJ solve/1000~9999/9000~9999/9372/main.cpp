/*#include <iostream>  
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		for (int m_idx = 0; m_idx < M; m_idx++) {
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1 << "\n";
	}
	return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		int N, M; cin >> N >> M;
		vector<int> v[MAX];
		bool visited[MAX]; memset(visited, 0, sizeof(visited));
		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int result = 0;
		queue<int> q;
		q.push(1);
		visited[1] = true;
		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			for (int i = 0; i < v[idx].size(); i++) {
				int next = v[idx][i];
				if (!visited[next]) {
					visited[next] = true;
					result++;
					q.push(next);
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}