class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode *cur = root;
        int l = 0, r = 0;
        while (cur) {
            l++;
            cur = cur -> left;
        }
        cur = root;
        while (cur) {
            r++;
            cur = cur -> right;
        }
        if (l == r) return pow(2, l) - 1;
        else return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};