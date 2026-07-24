class Solution {
public:

    void solve(int index, int sum, vector<int>& arr, vector<int>& ans) {

        if(index == arr.size()) {
            ans.push_back(sum);
            return;
        }

        // Pick
        solve(index + 1, sum + arr[index], arr, ans);

        // Not Pick
        solve(index + 1, sum, arr, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {

        vector<int> ans;

        solve(0, 0, arr, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};