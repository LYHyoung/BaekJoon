#include <iostream>
#include <vector>
using namespace std;

string s, p;
vector<int> pi;

void get_pi() {
	int n = s.size();
	pi.resize(n, 0);
	int j = 0;

	for (int i = 1; i < n; i++) {
		while ((j > 0) && (s[i] != s[j])) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
			pi[i] = j;
		}
	}
}

bool kmp() {
	int n = s.size();
	int m = p.size();
	int j = 0;

	for (int i = 0; i < n; i++) {
		while ((j > 0) && (s[i] != p[j])) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				return 1;
			}
			else
				j++;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> p;
	get_pi();
	cout << kmp() << '\n';
	return 0;
}

// first try
/*#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str, comp; cin >> str >> comp;
	
	if (str.find(comp) != string::npos)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}*/