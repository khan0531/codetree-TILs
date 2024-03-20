#include <bits/stdc++.h>

using namespace std;
using ll = long long;
pair<ll, ll> p[3];
void func(int st, int en){
    ll x= p[st].second;
    ll y= p[en].second;
    if (x + y > p[en].first){
        p[st].second = x + y - p[en].first;
        p[en].second = p[en].first;
    }
    else {
        p[en].second = x + y;
        p[st].second = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 3;

    for(int i = 0; i < 3; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < 100; i++) {
        int tmp = i%3;
        func(tmp, (tmp+1)%3);
    }
    cout << p[0].second << '\n'<< p[1].second << '\n'<< p[2].second;
    return 0;
}