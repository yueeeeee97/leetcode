class Solution {
public:
    TreeNode* helper(int postEnd, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder) {
        if (postEnd < 0 || inStart > inEnd) return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int idx = 0;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == postorder[postEnd]) {
                idx = i;
                break;
            }
        }
        root -> left = helper(postEnd - inEnd + idx - 1, inStart, idx - 1, inorder, postorder);
        root -> right = helper(postEnd - 1, idx + 1, inEnd, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};