#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	getline(cin, str);
	str += '\n';
	stack<char> st;
	bool chk = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << "<";
			chk = true;
		}
		else if (str[i] == '>') {
			cout << ">";
			chk = false;
		}
		else if (chk) cout << str[i];
		else if (str[i] == ' ' || str[i] == '\n') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
		else st.push(str[i]);
	}
	return 0;
}