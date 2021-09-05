#include <iostream>
#define MAX 100001
using namespace std;
int N;
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	bool chk = false;
	cin >> arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		if (arr[i - 1] != arr[i]) {
			chk = true;
			break;
		}
	}
	if (chk == 1) cout << "koosaga" << '\n';
	else {
		if (N % 2 == 0)
			cout << "cubelover" << '\n';
		else
			cout << "koosaga" << '\n';
	}
	return 0;
}