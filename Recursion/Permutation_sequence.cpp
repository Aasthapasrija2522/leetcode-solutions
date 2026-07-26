class Solution {
public:
    vector<string> ans;

    void solve(vector<int>& nums, vector<bool>& vis, string &temp) {

        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (vis[i])
                continue;

            vis[i] = true;

            temp.push_back(nums[i] + '0');

            solve(nums, vis, temp);

            temp.pop_back();

            vis[i] = false;
        }
    }

    string getPermutation(int n, int k) {

        vector<int> nums;

        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        vector<bool> vis(n, false);

        string temp;

        solve(nums, vis, temp);

        return ans[k - 1];
    }
};