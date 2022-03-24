#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+6;
int N, arr[MN], ans[MN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    stack<int> st;
    for(int i=0; i<N; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        ans[i] = st.empty() ? i : i - st.top(); st.push(i);
    }
    for(int i=0; i<N; i++) cout << ans[i] << (i == N-1 ? "\n" : " ");
    return 0;
}
