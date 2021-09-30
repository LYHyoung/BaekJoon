#include <bits/stdc++.h>
using namespace std;

int N, K;
// ��õ ��, ó�� ��õ���� ����, ���� ����Ʋ ��
int recommend[101], when[101], homany;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= K; ++i) {
		int student;
		cin >> student;
		// �̹� ��õ���� ��� (����Ʋ�� �ִ� ���)
		if (recommend[student] > 0) recommend[student]++;
		// ���� ����Ʋ�� ����ϴ� ���
		else {
			// ���� ����Ʋ ���� ����Ʋ �������� �������
			if (homany < N) {
				recommend[student]++;
				when[student] = i;
				homany++;
			}
			// ���� ����Ʋ �� �ϳ��� ���� ����ϴ� ���
			else {
				int change;
				int reco = 1111;
				for (int i = 1; i <= 100; ++i) {
					if (!recommend[i]) continue;
					// ��õ �� ������ ������
					if (reco > recommend[i]) {
						change = i;
						reco = recommend[i];
					}
					// ��õ �� ������ ���
					else if (reco == recommend[i]) {
						// �����Ⱦָ� ������
						if (when[i] < when[change]) change = i;
					}
				}
				// ���� ��õ������
				recommend[student]++;
				when[student] = i;
				// ���ұ��
				recommend[change] = 0;
				when[change] = 0;
			}
		}
	}
	for (int i = 1; i <= 100; ++i)
		if (when[i]) cout << i << ' ';

	return 0;
}