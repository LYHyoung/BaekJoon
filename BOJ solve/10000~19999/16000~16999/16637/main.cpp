#include <iostream>
#include <algorithm>
#include<climits>
#include<string>
using namespace std;
int N, ans; 
string str;

int cal(int a, int b, char oper) {
	int result = a;
	switch (oper) {
		case '+': result += b; break;
		case '*': result *= b; break;
		case '-': result -= b; break;
	}
	return result;
}

void DFS(int idx, int cur) {
	if (idx > N - 1) {		// terminate condition
		ans = max(ans, cur);
		return;
	}
	char oper = (idx == 0) ? '+' : str[idx - 1];	// operator decision

	if (idx + 2 < N) {		// bracket condition
		int brac = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		DFS(idx + 4, cal(cur, brac, oper));
	}

	DFS(idx + 2, cal(cur, str[idx] - '0', oper));		// no bracket
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> str;

	ans = INT_MIN;
	DFS(0, 0);
	cout << ans;
	return 0;
}