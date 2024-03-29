#include <bits/stdc++.h>
using namespace std;

int N, K;
// 추천 수, 처음 추천받은 시점, 사용된 사진틀 수
int recommend[101], when[101], homany;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= K; ++i) {
		int student;
		cin >> student;
		// 이미 추천받은 경우 (사진틀이 있는 경우)
		if (recommend[student] > 0) recommend[student]++;
		// 새로 사진틀을 줘야하는 경우
		else {
			// 사용된 사진틀 수가 사진틀 개수보다 적은경우
			if (homany < N) {
				recommend[student]++;
				when[student] = i;
				homany++;
			}
			// 사용된 사진틀 중 하나를 뺏어 줘야하는 경우
			else {
				int change;
				int reco = 1111;
				for (int i = 1; i <= 100; ++i) {
					if (!recommend[i]) continue;
					// 추천 수 적으면 뺏을꺼
					if (reco > recommend[i]) {
						change = i;
						reco = recommend[i];
					}
					// 추천 수 동률인 경우
					else if (reco == recommend[i]) {
						// 오래된애를 뺏을꺼
						if (when[i] < when[change]) change = i;
					}
				}
				// 새로 추천받은애
				recommend[student]++;
				when[student] = i;
				// 빼았긴애
				recommend[change] = 0;
				when[change] = 0;
			}
		}
	}
	for (int i = 1; i <= 100; ++i)
		if (when[i]) cout << i << ' ';

	return 0;
}