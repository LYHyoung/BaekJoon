#include <iostream>
using namespace std;
long long tn[36];		// always remember to use 'long long' type
int main() {
	ios_base::sync_with_stdio(0);
	tn[0] = 1;
	for (int i = 1; i < 36; i++) {
		for (int j = 1; j <= i; j++) {
			tn[i] += tn[j - 1] * tn[i - j];
		}
	}
	int n; cin >> n;
	cout << tn[n] << '\n';
	return 0;
}