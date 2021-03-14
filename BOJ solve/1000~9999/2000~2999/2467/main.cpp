#include <iostream>
#define MAX 100000
using namespace std;
typedef long long ll;

int N;
ll arr[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = N - 1;

	int liquid = abs(arr[left] + arr[right]);
	ll resA = arr[left];
	ll resB = arr[right];

	while (left < right) {
		int t = arr[left] + arr[right];
		if (abs(t) < liquid) {
			liquid = abs(t);
			resA = arr[left];
			resB = arr[right];
		}

		if (t < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << resA << ' ' << resB << '\n';

	return 0;
}