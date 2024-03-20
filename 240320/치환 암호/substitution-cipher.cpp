#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string encrypted;
    getline(cin, encrypted);

    string substitutionRule;
    getline(cin, substitutionRule);

    for (char& c : encrypted) {
        if (c != ' ') {
            c = 'a' + substitutionRule.find(c);
        }
    }

    cout << encrypted << '\n';

    return 0;
}