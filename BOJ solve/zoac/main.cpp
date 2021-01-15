#include <iostream>			// 18238
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	
	int sum = abs('A'-str[0]);
	if (sum > 13) sum = 26 - sum;
	int size = str.size();
	for (int i = 1; i < size; i++) {
		int sub = abs((int)str[i] - (int)str[i - 1]);
		if (sub > 13) sub = 26 - sub;
		sum += sub;
	}
	cout << sum;
	return 0;
}