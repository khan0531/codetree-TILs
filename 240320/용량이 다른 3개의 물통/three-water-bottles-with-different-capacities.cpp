#include <bits/stdc++.h>

using namespace std;
using ll = long long
pair<ll, ll> p[3];
void func(int st, int en){
    if (p[st].second + p[en].second > p[en].first){
        p[st].second = p[st].second + p[en].second - p[en].first;
        p[en].second = p[en].first;
    }
    else {
        p[st].second = 0;
        p[en].second = p[st].second + p[en].second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 3;

    for(int i = 0; i < 3; i++) {
        cin >> p[i].first >> p[i].second;
    }
    int k = 100;
    while(k--){
        //1->2
        func(0, 1);
        func(1, 2);
        func(2, 0);
    }
    cout << p[0].second << '\n'<< p[1].second << '\n'<< p[2].second;
    return 0;
}