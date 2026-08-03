class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]>st.top()){
                ans[i]++;
                st.pop();
            }
            if(!st.empty()){
                ans[i]++;
            }
            st.push(heights[i]);
        }
        return ans;
        
    }
};