/*#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m; cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		v.push_back(t);
	}
	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		int cnt = 0;
		for (int j = s - 1; j < e; j++) {
			cnt += v[j];
		}
		cout << cnt << '\n';
	}
	return 0;
}*/

#include<iostream>
#include<vector>
#include<cmath>

#define endl "\n"
#define MAX 100010
using namespace std;

int N, M;
int Arr[MAX];
int Sum[MAX];
vector<pair<int, int>> Cmd;

void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
        Sum[i] = Sum[i - 1] + Arr[i];
    }
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        Cmd.push_back(make_pair(a, b));
    }
}

void Solution()
{
    for (int i = 0; i < M; i++)
    {
        int Start = Cmd[i].first;
        int End = Cmd[i].second;

        cout << Sum[End] - Sum[Start - 1] << endl;
    }
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
