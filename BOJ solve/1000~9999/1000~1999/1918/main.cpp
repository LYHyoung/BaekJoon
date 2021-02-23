#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	stack<char> op;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			cout << s[i];
		else {
			if (s[i] == '(')
				op.push(s[i]);
			else if (s[i] == '*' || s[i] == '/') {
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == ')') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}

	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}

	return 0;
}