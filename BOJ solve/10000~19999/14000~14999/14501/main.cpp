#include <iostream>
#include <algorithm>
using namespace std; 
#define MAX 16
int Day[MAX];
int Cost[MAX];
int DP[MAX];

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Day[i] >> Cost[i];
	}
	for (int i = N; i >= 1; i--)
	{
		if (i + Day[i] > N + 1) DP[i] = DP[i + 1];
		else DP[i] = max(DP[i + 1], DP[i + Day[i]] + Cost[i]);
	}
	cout << DP[1] << endl;
	return 0;
}