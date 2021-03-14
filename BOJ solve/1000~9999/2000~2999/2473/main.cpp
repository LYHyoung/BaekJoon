#include <iostream>
#include <algorithm>
#include <climits>
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
	sort(arr, arr + N);

	ll minimum = LLONG_MAX;
	int left, mid, right;

	for (int i = 0; i < N; i++) {
		int j = i + 1;
		int k = N - 1;
		while (1) {
			if (j >= k)
				break;

			ll sum = arr[i] + arr[j] + arr[k];
			if (llabs(sum) < minimum) {
				minimum = llabs(sum);
				left = i;
				mid = j;
				right = k;
			}

			if (sum < 0)
				j++;
			else
				k--;
		}
	}

	cout << arr[left] << ' ' << arr[mid] << ' ' << arr[right] << '\n';

	return 0;
}