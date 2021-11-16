void prime_sieve(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int i=2; i*i<=n; i++){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i) prime[j] = false;
        }
    }
}
