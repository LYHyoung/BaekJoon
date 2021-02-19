#include <iostream>
#include <map>
#define MAX 200001
using namespace std;

int F;
int parent[MAX];
int friend_num[MAX];
map<string, int> m;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) {
		parent[b] = a;
		friend_num[a] += friend_num[b];
	}
	else if (a > b) {
		parent[a] = b;
		friend_num[b] += friend_num[a];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str1, str2;
	map<string, int>::iterator it;

	int Tc, cnt; cin >> Tc;

	for (int i = 0; i < Tc; i++) {
		m.clear();			// map에서는 이렇게 clear를 통해 초기화함
		cnt = 0;
		for (int i = 0; i < MAX; i++) {
			parent[i] = i;
			friend_num[i] = 1;
		}

		int num; cin >> num;
		int a, b;
		for (int i = 0; i < num; i++) {
			cin >> str1 >> str2;
			it = m.find(str1);
			if (it == m.end()) {
				m[str1] = ++cnt;
				a = cnt;
			}
			else a = it->second;

			it = m.find(str2);
			if (it == m.end()) {
				m[str2] = ++cnt;
				b = cnt;
			}
			else b = it->second;
			Union(a, b);
			int root = find(a);
			cout << friend_num[root] << '\n';
		}
	}

	return 0;
}