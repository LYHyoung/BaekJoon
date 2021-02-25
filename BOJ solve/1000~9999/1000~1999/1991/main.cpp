#include <iostream>
#include <vector>
#define MAX 26		// A ~ Z
using namespace std;

int n;
vector<pair<int, bool>> tree[MAX];		// number of node, left

void preOrder(int node) {			// good point of preorder
	cout << (char)(node + 'A');
	for (int i = 0; i < tree[node].size(); i++)
		preOrder(tree[node][i].first);
}

void inOrder(int node) {			// also good point of in order
	if (tree[node].size() && tree[node][0].second)		// left child's second is 'true'
		inOrder(tree[node][0].first);

	cout << (char)(node + 'A');

	if (tree[node].size() && !tree[node][0].second)		// only right child ('false')
		inOrder(tree[node][0].first);

	else if (tree[node].size() == 2)					// got left and right
		inOrder(tree[node][1].first);
}

void postOrder(int node) {		// and also good idea of postorder
	for (int i = 0; i < tree[node].size(); i++)
		postOrder(tree[node][i].first);

	cout << (char)(node + 'A');
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char t1, t2, t3; cin >> t1 >> t2 >> t3;

		// left child
		if (t2 != '.')
			tree[t1 - 'A'].push_back({ t2 - 'A', true });

		// right chlid
		if (t3 != '.')
			tree[t1 - 'A'].push_back({ t3 - 'A', false });
	}

	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);
	cout << '\n';

	return 0;
}