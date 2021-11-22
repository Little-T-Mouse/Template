#include<bits/stdc++.h>
using namespace std;
int cnttriplets(int arr[], int n){
    int max_val = 0, ans = 0;
    for (int i = 0; i < n; i++) max_val = max(max_val, arr[i]);
    int freq[max_val + 1]={0};
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    ans += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;
    for (int i = 1; i <= max_val; i++) ans += freq[0] * freq[i] * (freq[i] - 1) / 2;
    for (int i = 1; 2 * i <= max_val; i++) ans += freq[i] * (freq[i] - 1) / 2 * freq[2 * i];
    for (int i = 1; i <= max_val; i++) {
        for (int j = i + 1; i + j <= max_val; j++) ans += freq[i] * freq[j] * freq[i + j];
    }
    return ans;
}
int main(){
    int N, cnt;
    cin >> N;
    int arr[N];
    for(int i=0; i<N; i++) cin >> arr[i];
    cnt = cnttriplets(arr, N);
    cout<< ((cnt == 0) ? -1 : cnt) << endl;
    return 0;
}
