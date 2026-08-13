class Solution {
public:

    int solve(TreeNode* root, int &ans) {

        if (root == NULL)
            return 0;

        int leftSum = max(0, solve(root->left, ans));
        int rightSum = max(0, solve(root->right, ans));

        // Use BOTH sides to make a complete path
        int currentPath = leftSum + root->val + rightSum;

        ans = max(ans, currentPath);

        // Give only ONE side to the parent
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        solve(root, ans);

        return ans;
    }
};