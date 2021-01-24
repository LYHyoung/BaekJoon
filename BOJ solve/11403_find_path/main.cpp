#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int adj[MAX][MAX];
	for (int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adj[i][j] == 1) continue;
				if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << adj[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}