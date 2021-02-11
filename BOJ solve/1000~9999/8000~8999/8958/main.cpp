#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	while (n--) {
		string line;
		cin >> line;
		int cnt = 0;
		int t = 0;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == 'O') {
				cnt++;
				t += cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << t << '\n';
	}
	return 0;
}