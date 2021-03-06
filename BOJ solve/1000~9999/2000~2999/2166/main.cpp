#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N;

double B(double x1, double x2, double x3, double y1, double y2, double y3) {
	double ans = x1 * y2 + x2 * y3 + x3 * y1;
	ans += (-y1 * x2 - y2 * x3 - y3 * x1);
	return ans / 2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	vector<pair<double, double>> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	double ans = 0;
	for (int i = 1; i < N; i++) {
		ans += B(v[0].first, v[i - 1].first, v[i].first, v[0].second, v[i - 1].second, v[i].second);
	}

	printf("%.1lf", abs(ans));

	return 0;
}