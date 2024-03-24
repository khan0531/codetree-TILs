#include <bits/stdc++.h>

using namespace std;

int n, k;

void applyReversal(vector<int>& arr, int L, int R) {
    while (L < R) {
        swap(arr[L], arr[R]);
        L++;
        R--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, A1, A2, B1, B2;
    cin >> N >> K >> A1 >> A2 >> B1 >> B2;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) arr[i] = i + 1;

    for (int i = 0; i < K; ++i) {
        applyReversal(arr, A1 - 1, A2 - 1);
        applyReversal(arr, B1 - 1, B2 - 1);
    }

    // 최종 수열 출력
    for (int num : arr) {
        cout << num << "\n";
    }
    return 0;
}