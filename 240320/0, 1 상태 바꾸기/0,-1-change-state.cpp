#include <bits/stdc++.h>

using namespace std;

int d[4005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0 ; i < n; i++) {
        cin >> d[i];
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1){
            d[b-1] = c;
        }
        else if (a == 2){
            for (int i = b-1; i < c; i++) {
                d[i]+=1;
                d[i]%=2;
            }
        }
        else if (a == 3){
            for (int i = b-1; i < c; i++) {
                d[i] = 0;
            }
        }
        else {
            for (int i = b-1; i < c; i++) {
                d[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << d[i] <<' ';
    return 0;
}