#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int count0 = 0;
	int count1 = 0;
	int check = s[0];
	if (check == '1') count1++;
	else count0++;
	for (int i = 0; i < n; i++) {
		if (s[i] == check) continue;
		else {
			if (s[i] == '0') {
				count0++;
				check = s[i];
			}
			else {
				count1++;
				check = s[i];
			}
		}
	}
	cout << min(count1, count0);
	return 0;
}
