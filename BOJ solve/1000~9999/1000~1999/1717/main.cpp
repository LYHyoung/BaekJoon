#include <iostream>				// Union-Find 알고리즘
#define MAX 1000000
using namespace std;

int n, m;
int parent[MAX];

int find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = find(parent[num]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, check; cin >> check >> a >> b;
		if (!check)
			Union(a, b);
		else if (check) {
			if (find(a) == find(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}