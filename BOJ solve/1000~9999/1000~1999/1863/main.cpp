// https://www.acmicpc.net/source/24878837

#include <iostream>			// 1863
#include <stack>

using namespace std;

int main(void) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> s;
	int towercount = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		while (s.empty() == false && s.top() > y)
		{
			towercount++;
			s.pop();
		}

		if (s.empty() == false && s.top() == y)		// 같은 것이 있을 시
			continue;

		s.push(y);
	}

	for (int i = 0; !s.empty(); i++)
	{
		if (s.top() == 0)
		{
			break;
		}

		towercount++;

		s.pop();
	}

	cout << towercount;

	return 0;
}