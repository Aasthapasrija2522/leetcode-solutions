class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xorr=0;
        bool hasnonzero=false;
        for(int i=0;i<n;i++){
            xorr^=nums[i];
            if(nums[i]!=0){
                hasnonzero=true;
            }
          
        }
          if(!hasnonzero){
                return 0;
            }
        if(xorr!=0){
            return n;
        }
        return n-1;
    }
};