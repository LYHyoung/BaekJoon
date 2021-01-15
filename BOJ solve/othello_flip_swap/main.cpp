#include <iostream>		// 13413
using namespace std;

int main() {
	int T;
	cin >> T;
	string oth, aim;

	for (int i = 0; i < T; i++) {
		int N, bw = 0, wb = 0;
		cin >> N;
		cin >> oth;
		cin >> aim;
		for (int j = 0; j < N; j++) {
			if (oth[j] != aim[j]) {
				if (oth[j] == 'W')
					wb++;
				else
					bw++;
			}
		}
		if (bw > wb)
			cout << bw << "\n";
		else
			cout << wb << "\n";
	}

	return 0;
}