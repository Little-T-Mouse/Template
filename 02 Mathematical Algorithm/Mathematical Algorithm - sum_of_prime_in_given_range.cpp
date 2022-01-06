#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

int psa[N+1];

void precompute() {
    int arr[N + 1];
    arr[0] = 1;
    arr[1] = 1;
    for (int i=2; i<=sqrt(N); i++) {
        if (arr[i] == 0) {
            for (int j=i*i; j<=N; j+=i) {
                arr[j] = 1;
            }
        }
    }
    long PrimeSum = 0;
    for (int i=1; i<=N; i++) {
        if (arr[i] == 0) PrimeSum += i;
        psa[i] = PrimeSum;
    }
}

int main() {
    precompute();
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int l, r;
        cin >> l >> r;
        cout << psa[r] - psa[l-1] << endl;
    }
    return 0;
}
