int n; cin >> n;
int val[n], s=0;
for(int i=0; i<n; i++){
    cin >> val[i];
    s+=val[i];
}
memset(dp, false, sizeof dp);
dp[0] = true;
for(int i=0; i<n; i++){
    for(int j=s; j>=0; j--){
        if(j<val[i]||dp[j-val[i]]==false) continue;
        dp[j] = true;
    }
}
for(int i=(s+1)/2; i>=0; i--) { // minimum different = sum - 2*maximum possible i
    if(dp[i]){
        cout << abs(s-2*i) << endl;
        break;
    }
}
