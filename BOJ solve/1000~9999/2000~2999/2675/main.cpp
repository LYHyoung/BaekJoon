#include <iostream>
using namespace std;
int main() {
	int testcase; cin >> testcase;
	while (testcase--) {
		int R; string S;
		cin >> R >> S;
		for (int i = 0; i < S.size(); i++) {
			for (int j = 0; j < R; j++) {
				cout << S[i];
			}
		}
		cout << '\n';
	}
	return 0;
}