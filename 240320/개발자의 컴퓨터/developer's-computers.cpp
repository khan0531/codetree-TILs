#include <bits/stdc++.h>

using namespace std;
using tu = tuple<int, int, int>;

int n, ans, cnt;
vector<tu> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int s, t, b;

    for (int i = 0; i < n; i++) {
        cin >> s >> t >> b;
        v.push_back({s, 0, b});
        v.push_back({t, 1, b});
    }
    sort(v.begin(), v.end());
    int k = 0;
    for (int i = k; i < 2*n - 1; i++) {
        auto [x, y, z] = v[i];
        while(x == get<0>(v[k])) {
            if (y == 0) cnt += z;
            else cnt -= z;
            k++;
        }
        ans = max(cnt, ans);
    }
    cout << ans;


    return 0;
}