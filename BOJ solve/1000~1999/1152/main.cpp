#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string line;
	getline(cin, line);		// 기억하기
	int cnt = 1;
	for (int i = 1; i < line.size()-1; i++) {
		if (line[i] == ' ') {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}