/*
#define MAX 987654321
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int idx;
	double val;
};
struct cmp {
	bool operator()(info& a, info& b) {
		return a.val > b.val;
	}
};
info tmp;
vector<info> v[102];		//대포 최대 100개+시작+끝
double arr[102][2];
double dist[102];
int pre[102];
int num;

double cal(int from, int to) {
	double x = fabs(arr[from][0] - arr[to][0]);
	double y = fabs(arr[from][1] - arr[to][1]);
	double val = hypot(x, y);
	return val;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double ex, ey;
	cin >> arr[0][0] >> arr[0][1] >> ex >> ey;
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> arr[i][0] >> arr[i][1];
	arr[num + 1][0] = ex;
	arr[num + 1][1] = ey;

	for (int i = 0; i <= num + 1; i++)
		dist[i] = MAX;
	priority_queue<info, vector<info>, cmp> pq;
	dist[0] = 0;
	tmp.idx = 0;
	tmp.val = 0;
	pq.push(tmp);
	bool first = true;
	while (!pq.empty()) {
		int cidx = pq.top().idx;
		double cv = pq.top().val;
		pq.pop();
		if (dist[cidx] < cv) continue;
		for (int i = 1; i <= num + 1; i++) {
			if (cidx == i) continue;
			double val = cal(cidx, i);
			double nv;
			if (first)
				nv = val / 5;
			else
				nv = min(val / 5, fabs(val - 50) / 5 + 2);
			if (dist[i] > cv + nv) {
				dist[i] = cv + nv;
				tmp.idx = i;
				tmp.val = cv + nv;
				pre[i] = cidx;
				pq.push(tmp);
			}
		}
		first = false;
	}
	cout << dist[num + 1];
	system("pause");
	return 0;
}*/

#include <iostream>		// 10473
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#define MAX 102
#define INF 987654321
using namespace std;

vector<pair<double, double>> cannon(MAX);
double dist[MAX];

double cal(int from, int to) {
	double x = fabs(cannon[from].first - cannon[to].first);
	double y = fabs(cannon[from].second - cannon[to].second);
	double ans = hypot(x,y);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	double start_x, start_y;
	cin >> start_x >> start_y;
	cannon[0].first = start_x;
	cannon[0].second = start_y;

	double end_x, end_y;
	cin >> end_x >> end_y;

	int n;
	cin >> n;
	cannon[n + 1].first = end_x;
	cannon[n + 1].second = end_y;

	for (int i = 1; i <= n; i++) {
		double c_x, c_y;
		cin >> c_x >> c_y;
		cannon[i].first = c_x;
		cannon[i].second = c_y;
	}

	for (int i = 0; i <= n+1; i++) dist[i] = INF;

	priority_queue < pair<int, double>, vector<pair<int, double>>, greater<pair<int,double>>> PQ;
	dist[0] = 0;

	int temp_idx = 0;
	double temp_val = 0;
	PQ.push({ 0,0 });

	bool first = true;

	while (!PQ.empty()) {
		int idx = PQ.top().first;
		double val = PQ.top().second;
		PQ.pop();

		if (dist[idx] < val) continue;

		for (int i = 1; i <= n + 1; i++) {
			if (idx == i) continue;
			double dat = cal(idx, i);
			double nv;
			if (first)  nv = dat / 5;
			else  nv = min(dat / 5, fabs(dat - 50) / 5 + 2);

			if (dist[i] > val + nv) {
				dist[i] = val + nv;
				temp_idx = i;
				temp_val = val + nv;
				PQ.push({ temp_idx,temp_val });
			}
		}
		first = false;
	}
	cout << dist[n + 1];
	system("pause");
	return 0;
}