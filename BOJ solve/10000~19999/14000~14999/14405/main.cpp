#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	int i = 0;
	bool chk = 0;
	while (i < str.size()) {
		if (str[i] == 'p' && str[i + 1] == 'i') i += 2;
		else if (str[i] == 'k' && str[i + 1] == 'a') i += 2;
		else if (str[i] == 'c' && str[i + 1] == 'h' && str[i + 2] == 'u') i += 3;
		else {
			chk = 1;
			break;
		}
	}
	if (chk == 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
	return 0;
}