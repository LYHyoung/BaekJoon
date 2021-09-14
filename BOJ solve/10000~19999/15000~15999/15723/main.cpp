#include <iostream>
#include <vector>
#include <string>
#define INF 1e9
using namespace std;

int n, m;
int d[26][26];
string s;
char fr, to;

//플로이드 와샬
void floydWashall() {
	// k : 거쳐가는 노드
	for (int k = 0; k < 26; k++)
		// 출발
		for (int i = 0; i < 26; i++)
			// 도착
			for (int j = 0; j < 26; j++)
				if (d[i][j] == INT32_MAX && d[i][k] != INT32_MAX && d[k][j] != INT32_MAX)
					d[i][j] = d[i][k] + d[k][j];
}

int main() {
	cin >> n;

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			d[i][j] = INT32_MAX;

	while (n--) {
		cin >> fr >> s >> to;
		d[fr - 'a'][to - 'a'] = 1; //fr은 to이다를 표현
	}

	floydWashall();

	cin >> m;

	while (m--) {
		cin >> fr >> s >> to;
		if (d[fr - 'a'][to - 'a'] != INT32_MAX) //fr은 to이다를 정의할 수 있으면
			cout << "T" << '\n';
		else //fr은 to이다를 정의할 수 없으면
			cout << "F" << "\n";
	}
	return 0;
}
