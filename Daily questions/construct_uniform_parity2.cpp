int mn=*min_element(nums.begin(),nums.end());
if(mn%2==1){
    return true;
}
for(int x:nums){
    if(x%2==1){
        return false;
    }
}
return true;