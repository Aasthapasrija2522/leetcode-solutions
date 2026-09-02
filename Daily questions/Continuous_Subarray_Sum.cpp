unordered_map<int,int>mp;
int prefixsum=0;
mp[0]=-1
for(int i=0;i<n;i++){
    prefixsum+=nums[i];
    int rem=prefixsum%k;
    if(mp.find(rem)!=mp.end()){
        if(i-mp[rem]>=2){
            retur true;
        }
        else{
            mp[rem]=i;
        }
        return false
    }
}