const int mod=1e9+7;
vector<long long >dp(26,0);
for (char c:s){
    int idx=c-'a';
    long long total=1;
    for(long long x:dp){
        total=(total+x)%mod;
    }
    dp[idx]=total%mod;

}
long long ans=0;
for(int x:dp){
    ans+=x
}
return ans;