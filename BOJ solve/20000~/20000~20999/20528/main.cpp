#include <iostream>
#define MAX 101
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int check = 0;
	cin >> N;
	string str[MAX];
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int leng = str[i].length();
		/*
		for (int j = 0; j < leng / 2 - 1; j++) {
			if (str[i][j] != str[i][leng - j - 1]) {
				check++;
				break;
			}
		}
		*/
		if (str[i][leng - 1] != str[i + 1][0]) {
			check++;
		}
	}
	if (check)
		cout << 0 << '\n';
	else
		cout << 1 << '\n';
	return 0;
}