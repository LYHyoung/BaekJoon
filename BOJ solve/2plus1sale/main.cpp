#include <iostream>		// 11508
#include <algorithm>
using namespace std;
//�Է� ���� ���ݵ� �� ���� ��� �͵���� 3���� ������ �� 
//���� ������ ������ �����Ƿ� 
//������������ ������ �������� �� �ε������� 3�� �������� �� 
//�������� 2�� �͵鸸 ���ݿ� ���Խ�Ű�� ������ �ȴ�.
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