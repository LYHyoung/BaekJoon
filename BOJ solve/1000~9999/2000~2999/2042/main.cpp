// https://yabmoons.tistory.com/431
// segment tree -> O(logN)
#include <iostream>
#include <cmath>
using namespace std;
long long* segtree;
long long arr[1000001];

long long set_segmentTree(int node, int start, int end) {
    if (start == end) return segtree[node] = arr[start];
    int mid = (start + end) / 2;
    return segtree[node] = set_segmentTree(2 * node, start, mid) + set_segmentTree(2 * node + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return segtree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
    if (idx<start || idx>end) return;
    segtree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, diff);
    update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num, m, k, a, b;
    long long c;
    cin >> num >> m >> k;
    int height = ceil(log2(num));
    segtree = new long long[1 << (height + 1)];
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    set_segmentTree(1, 0, num - 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {   //b->c�� ��ȯ
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, 0, num - 1, b - 1, diff);
        }
        else if (a == 2)      //b~c��
            cout << sum(1, 0, num - 1, b - 1, c - 1) << '\n';
    }
    return 0;
}