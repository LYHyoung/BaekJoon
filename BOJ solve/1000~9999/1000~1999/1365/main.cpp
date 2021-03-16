#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Lower_Bound(vector<int> vt, int num) {
    int low = 0, high = vt.size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;
        if (vt[mid] >= num)
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, num;
    cin >> n;
    vector<int> vt;
    vt.push_back(-1);
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > vt[vt.size() - 1])
            vt.push_back(num);
        else
            vt[Lower_Bound(vt, num)] = num;
    }

    cout << n - vt.size() + 1 << '\n';

    return 0;
}