#include <iostream>
#include <algorithm>
using namespace std;
string s, t;

string A(string t) {
	t.erase(t.end() - 1, t.end());
	return t;
}

string B(string t) {
	t.erase(t.begin(), t.begin() + 1);
	reverse(t.begin(), t.end());
	return t;
}

void go(string str) {
	int size = str.size();
	if (s.size() == size) {
		if (s == str) {
			cout << 1 << '\n';
			exit(0);
		}
		return;
	}
	if (str[0] == 'A' && str[size - 1] == 'B')
		return;
	if (str[0] == 'B')
		go(B(str));
	if (str[size - 1] == 'A')
		go(A(str));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	go(t);
	cout << 0 << '\n';
	return 0;
}