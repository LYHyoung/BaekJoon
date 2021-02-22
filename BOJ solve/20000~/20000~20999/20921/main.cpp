#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cnt = 0;
vector<int> v;

void fi(int c) {
	if (c - 1 < M) {		// 제일 큰 값을 넣는다
		v.push_back(c);
		M = M - c + 1;
		fi(c - 1);
	}

	else if (c - 1 == M) {		// 같은 경우
		v.push_back(c);
		for (int i = 1; i <= c - 1; i++) {
			v.push_back(i);
		}
	}

	else {			// 가장 큰 값보다 작은 경우
		v.push_back(M + 1);
		for (int i = 1; i < M + 1; i++) {
			v.push_back(i);
		}
		for (int i = M + 2; i <= c; i++) {
			v.push_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	fi(N);

	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}

	return 0;
}