#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	cin.ignore();
	while (T--) {
		string str;
		getline(cin, str);
		int idx = 0;
		while (1) {
			if (str[idx] == ' ')
				break;
			idx++;
		}
		cout << "god";
		for (int i = idx + 1; i < str.size(); i++) {
			if (str[i] == ' ') continue;
			cout << str[i];
		}
		cout << '\n';
	}
	return 0;
}