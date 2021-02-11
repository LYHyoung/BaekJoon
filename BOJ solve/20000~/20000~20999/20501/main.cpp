/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>		// 20501
#include <vector>
#include <string>
#include <bitset>
#define MAX 2000
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<bitset<MAX>> v(N);
	for (int i = 0; i < N; i++) {
		v[i].reset();
		for (int j = 0; j < N; j++) {
			char t;
			scanf(" %c", &t);
			if (t == '1')
				v[i].set(j, true);
		}
	}
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int a, b;
		int count = 0;
		scanf("%d %d", &a, &b);
		for (int j = 0; j < N; j++) {
			if (v[j].test(a - 1) && v[j].test(b - 1)) count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>		// 20501
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	scanf("%d", &N);
	vector<string> bb(N + 1);
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		bb[i] = t;
	}
	int Q;
	scanf("%d", &Q);
	vector<pair<int, int>> PAIR(Q);
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", )
	}
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int count = 0;
		for (int j = 0; j < N; j++)
			if (bb[j][a - 1] == '1' && bb[j][b - 1] == '1') count++;
		printf("%d\n", count);
	}
	return 0;
}
*/
#include <iostream>
#include <bitset>
using namespace std;
bitset<2001> bt[2010];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> bt[i];
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b; a--; b--;
		cout << (bt[a] & bt[b]).count() << '\n';
	}
}