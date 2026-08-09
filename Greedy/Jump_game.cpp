class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(i>maxlen)
                return false;
            maxlen=max(maxlen,i+nums[i]);

        }
        return true;
    }
};