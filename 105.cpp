class Solution {
public:
    TreeNode* dfs(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if (inStart > inEnd || preStart == preorder.size()) return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int idx = 0;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == preorder[preStart]) {
                idx = i;
                break;
            }
        }
        root -> left = dfs(preStart + 1, inStart, idx - 1, preorder, inorder);
        root -> right = dfs(preStart + idx - inStart + 1, idx + 1, inEnd, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0, 0, inorder.size() - 1, preorder, inorder);
    }
};