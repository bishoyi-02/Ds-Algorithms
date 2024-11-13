vector<int> sieve(int n){
    vector<int> prime(n+1,1);
    prime[1]=0;
    for(int i=2;i*i<=n;++i){
        if(!prime[i])
            continue;
        for(int j=i*i;j<=n;j+=i){
            prime[j]=0;
        }
    }
    return prime;
}