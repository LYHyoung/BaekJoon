#include <iostream>			// Union-Find 알고리즘
#include <vector>
#define MAX 51
using namespace std;
int N, M, T, ans;
int parent[MAX];
vector<int> truth;
vector<int> party[MAX];

int find_parent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find_parent(parent[a]);
}

void Union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	parent[b] = a;
}

bool same_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> T;
	for (int i = 0; i < T; i++) {
		int person; cin >> person;
		truth.push_back(person);
	}
	for (int i = 0; i < M; i++) {
		int p; cin >> p;
		for (int j = 0; j < p; j++) {
			int person; cin >> person;
			party[i].push_back(person);
		}
	}
	ans = M;

	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int a = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			int b = party[i][j];
			Union(a, b);
		}
	}
	for (int i = 0; i < M; i++) {
		bool Go_party = true;
		for (int j = 0; j < party[i].size(); j++) {
			if (Go_party == false) break;
			int a = party[i][j];
			for (int k = 0; k < truth.size(); k++) {
				int b = truth[k];
				if (same_parent(a, b) == true) {
					Go_party = false;
					break;
				}
			}
		}
		if (Go_party == false) ans--;
	}
	cout << ans << '\n';

	return 0;
}