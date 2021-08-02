#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int H, W, N; cin >> H >> W >> N;
		int s = N / H + 1;		// Ãþ
		int d = N % H;			// È£
		if (d == 0) {
			d = H;
			s = N / H;
		}
		if (s > 9)
			cout << d << s << '\n';
		else
			cout << d << 0 << s << '\n';
	}
	return 0;
}