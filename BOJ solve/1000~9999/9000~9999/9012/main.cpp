#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string str; cin >> str;
		int chk = 0;
		for (int i = 0; i < str.size(); i++) {
			if (chk < 0) break;
			if (str[i] == '(') chk++;
			else chk--;
		}
		if (chk == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}