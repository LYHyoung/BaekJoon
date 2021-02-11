/*#include <iostream>			// 20529
#include <algorithm>
using namespace std;

const int INF = int(1e9);
int cnt[16];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		int n; cin >> n;
		while (n--) {
			string s; cin >> s;
			int temp = 0;
			for (int i = 0; i < 4; i++) {
				if (s[i] == "INTJ"[i]) temp |= 1 << i;
			}
			cnt[temp]++;
		}

		auto f = [&](int a, int b) {
			return __builtin_popcount(a ^ b);
		};
		int ans = INF;
		for (int i = 0; i < 16; i++) {
			if (cnt[i] >= 3) ans = 0;
		}
		for (int i = 0; i < 15; i++) for (int j = i + 1; j < 16; j++) {
			if (!cnt[i] || !cnt[j]) continue;
			if (max(cnt[i], cnt[j]) >= 2) ans = min(ans, f(i, j) + f(i, j));
		}
		for (int i = 0; i < 14; i++) for (int j = i + 1; j < 15; j++) for (int k = j + 1; k < 16; k++) {
			if (cnt[i] && cnt[j] && cnt[k]) ans = min(ans, f(i, j) + f(j, k) + f(k, i));
		}
		cout << ans << '\n';
	}
	return 0;
}
*/
/*
#include <iostream>			// 20529
#define INF 987654321;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	string str[10000];
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> str[i];
		}
		int count = 0;
		int MIN = INF;
		for (int i = 0; i < N - 2; i++) {
			for (int j = i + 1; j < N - 1; j++) {
				for (int k = j + 1; k < N; k++) {
					count = 0;
					for (int z = 0; z < 4; z++) {
						if (str[i][z] != str[j][z]) count++;
						if (str[i][z] != str[k][z]) count++;
						if (str[j][z] != str[k][z]) count++;
					}
					if (MIN > count) MIN = count;
				}
			}
		}
		cout << MIN << '\n';
	}
	return 0;
}
/*
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		printf("%d \n", str[i]);
	}
	return 0;
}
*/