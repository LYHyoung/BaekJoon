#include <iostream>
using namespace std;
typedef long long ll;

ll pow(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll val = pow(a, b / 2, m);
	val = val * val % m;

	if (b % 2 == 0) return val;
	else
		return (val * a) % m;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b, m;
	cin >> a >> b >> m;
	cout << pow(a, b, m);
	return 0;
}