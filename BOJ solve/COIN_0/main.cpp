#include <iostream>		// 11047
#include <vector>

using namespace std;

int N, K;
vector<int> A;

int Count() {
	int count = 0;

	for (int i = N-1; i >= 0; i--) {		// N-1
		if (K <= 0) break;
		if (A[i] > K) continue;
		while (A[i] <= K) {
			K -= A[i];
			count++;
		}
	}

	return count;
}

int main() {
	cin >> N >> K;
	A.resize(N);		// resize	// vector<int> A(N); µµ °¡´É
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cout << Count();

	return 0;
}