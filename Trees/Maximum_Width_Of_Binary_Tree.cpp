/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,unsigned long long >>q;
        q.push({root,0});
        unsigned long long maxwidth=0;
        while(!q.empty()){
            int size=q.size();
            
            unsigned long long firstindex=q.front().second;
            unsigned long long lastindex=firstindex;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                unsigned long long index=q.front().second;
                q.pop();
                lastindex=index;
                if (node->left){
                    q.push({node->left,2*index+1});

                }
                if(node->right){
                    q.push({node->right,2*index+2});
                 }

            }
            unsigned long long width=lastindex-firstindex+1;
            maxwidth=max(maxwidth,width);

        }
        return maxwidth;
    }
};