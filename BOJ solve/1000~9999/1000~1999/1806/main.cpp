#include <iostream>
#include <algorithm>
#define MAX 100000
#define INF 987654321
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, S; cin >> N >> S;
	int map[MAX];
	int low = 0;
	int high = 0;
	int sum = 0;
	int length = INF;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	
	sum = map[0];

	while (low <= high && high < N) {
		if (sum < S)
			sum += map[++high];
		else if (sum == S) {
			length = min(length, (high - low + 1));
			sum += map[++high];
		}
		else if (sum > S) {
			length = min(length, (high - low + 1));
			sum -= map[low];
			low++;
		}
	}

	if (length == INF)
		cout << 0 << '\n';
	else
		cout << length << '\n';

	return 0;
}