class Solution {
public:
    bool isIdentical(TreeNode* root1, TreeNode* root2) {

        // Both are empty
        if (root1 == NULL && root2 == NULL)
            return true;

        // One is empty, other is not
        if (root1 == NULL || root2 == NULL)
            return false;

        // Values are different
        if (root1->val != root2->val)
            return false;

        // Compare left and right subtrees
        return isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }
};