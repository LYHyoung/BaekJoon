#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n, m;
vector<string> voca;
map<string, int> mp;
string v;
bool compare(string a, string b) {
	if (a.size() == b.size() && mp[a] == mp[b]) {
		return a < b;
	}
	else if (mp[a] == mp[b]) {
		return a.size() > b.size();
	}
	return mp[a] > mp[b];
}

int main() {

	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v;
		if (v.size() < m) continue;
		if (mp.find(v)==mp.end()) {
			mp[v] = 0;
			voca.push_back(v);
		}
		mp[v]++;
	}
	sort(voca.begin(), voca.end(), compare);

	for (int i = 0; i < voca.size(); i++) {
		cout << voca[i] << '\n';
	}
}