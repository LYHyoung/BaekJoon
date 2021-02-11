#include <iostream>
#define MAX 1000000+1
using namespace std;
typedef long long ll;
long long numbers[MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll s, e, cnt = 0; cin >> s >> e;
	for (ll i = 2; i * i <= e; i++) {
		ll x = s / (i * i);
		if (s % (i * i) != 0)
			x++;
		while (x * (i * i) <= e) {
			numbers[x * (i * i) - s] = 1;
			x++;
		}
	}
	for (ll i = 0; i <= e - s; i++) {
		if (!numbers[i])
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}