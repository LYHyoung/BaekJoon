#include <iostream>
#include<stack>
#include<string>

using namespace std;


int main()
{
	int tmp = 1, output = 0;
	string str;
	bool wrong = false;
	stack<char> st;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push('(');
			tmp *= 2;
		}
		else if (str[i] == '[') {
			st.push('[');
			tmp *= 3;
		}

		else if (str[i] == ')') {
			if (st.empty()) {
				wrong = true;
				break;
			}
			if (st.top() == '(') {
				if (str[i - 1] == '(') output += tmp;
				st.pop();
				tmp /= 2;
			}
			else {
				wrong = true;
				break;
			}
		}
		else if (str[i] == ']') {
			if (st.empty()) {
				wrong = true;
				break;
			}
			if (st.top() == '[') {
				if (str[i - 1] == '[') output += tmp;
				st.pop();
				tmp /= 3;
			}
			else {
				wrong = true;
				break;
			}
		}
	}

	if (wrong or !st.empty()) {
		cout << 0 << endl;
	}
	else {
		cout << output << endl;
	}
}