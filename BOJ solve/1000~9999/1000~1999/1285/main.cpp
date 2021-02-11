// reculsive solution
#include <iostream>		// 1285
#include <vector>
#include <algorithm>
using namespace std;

int flip(vector<unsigned int>& coins, int row, int N) {
	if (row == N) {
		int total = 0;
		for (int i = 0; i < N; i++) {
			int col_t_cnt = 0;
			for (int j = 0; j < N; j++) {
				if (coins[j] & (1 << i))
					++col_t_cnt;
			}
			total += min(col_t_cnt, N - col_t_cnt);
		}
		return total;
	}

	int unfliped_t_cnt = flip(coins, row + 1, N);

	coins[row] = ~coins[row];
	int fliped_t_cnt = flip(coins, row + 1, N);

	return min(unfliped_t_cnt, fliped_t_cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<unsigned int> coins(N);		// bit mask vector
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < N; j++) {
			if (line.at(j) == 'T') {
				coins[i] |= (1 << j);
			}
		}
	}
	cout << flip(coins, 0, N);

	return 0;
}
// this is another solution
/*
#include <iostream>		// 1285
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
// https://staticvoidlife.tistory.com/144
const int MAX_SIZE = 20;

int N;
char map[MAX_SIZE][MAX_SIZE];

int main(void)
{
	int ans = 2100000000;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			while (true)
			{
				cin >> map[i][j];
				if (map[i][j] != '\n') break;
			}
		}
	}

	for (int k = 0; k < (1 << N); k++) // 각 행에 대해서 뒤집을지?
	{
		int sum = 0;

		for (int j = 0; j < N; j++) // 열
		{
			int nowT = 0;

			for (int i = 0; i < N; i++) // 행
			{
				char now = map[i][j];

				if ((1 << i) & k)
				{
					if (now == 'T') now = 'H';
					else now = 'T';
				}

				if (now == 'T') nowT++;
			}

			// 이 열을 뒤집는게 이득인지
			sum += MIN(nowT, N - nowT);
		}

		ans = MIN(ans, sum);
	}

	cout << ans;
	return 0;
}
*/