#include <iostream>		// 11399
#include <vector>
#include <algorithm>
using namespace std;

vector<int> time;
int n;

int calmincost() {
	int sum = 0, answer = 0;
	sort(time.begin(), time.end());

	for (int i = 0; i < time.size(); i++) {
		sum += time[i];
		answer += sum;
	}
	return answer;
}

int main() {
	cin >> n;
	time.resize(n);
	for (int i = 0; i < n; i++)
		cin >> time[i];
	cout << calmincost();
	return 0;
}