#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<string> ans;

void func(int t, string cur) {
    if (t == n) {
        ans.push_back(cur);
        return;
    }
    if (t > n) {
        return;
    }
    for (int i : {1, 2, 3}) {
        string nxt = cur.length()==0 ? to_string(i) : cur + "+" + to_string(i);
        func(t+i, nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    func(0, "");
    
    k > ans.size() ? cout << -1 : cout << ans[k-1];

    return 0;
}