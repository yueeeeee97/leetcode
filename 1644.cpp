class Solution {
public:
    bool find_p = false,find_q = false;
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return root;
        TreeNode* left = helper(root->left,p,q);
        TreeNode* right = helper(root->right,p,q);
        if(p==root) {find_p = true;return root;}
        if(q==root) {find_q = true;return root;}
        if(left&&right) return root;
        return left?left:right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* tmp = helper(root,p,q);
        if(find_p&&find_q) return tmp;
        else return NULL;
    }
};