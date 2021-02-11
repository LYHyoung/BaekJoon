#include <iostream>		// 11508
#include <algorithm>
using namespace std;
//입력 받은 가격들 중 가장 비싼 것들부터 3개씩 묶었을 때 
//가장 저렴한 가격이 나오므로 
//내림차순으로 가격을 정렬했을 때 인덱스에서 3을 나누었을 때 
//나머지가 2인 것들만 가격에 포함시키지 않으면 된다.
bool desc(int a, int b) {
	return a > b;
}
int main() {
	int N, count = 0;
	cin >> N;

	int* C = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	sort(C, C + N, desc);
	for (int i = 0; i < N; i+=3) {
		if (i+1 == N)
			count += C[i];
		else if (i+2 == N)
			count = count + C[i] + C[i + 1];
		else {
			count = count + C[i] + C[i + 1] + C[i + 2] - *min_element(C + i, C + i + 3);
		}
	}
	cout << count;
	return 0;
}