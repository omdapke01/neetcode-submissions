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
    int preIdx = 0;
    unordered_map<int, int> inorderMap;

    TreeNode* dfs(vector<int> &preorder, int inStart, int inEnd){
        if(inStart > inEnd) return NULL;

        int rootVal = preorder[preIdx++];

        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];

        root->left = dfs(preorder, inStart, mid-1);
        root->right = dfs(preorder, mid+1, inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); ++i){
            inorderMap[inorder[i]] = i;
        }   
        return dfs(preorder, 0, inorder.size()-1);
    }
};
