class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        if(p==q) return 0;
        return helper(root,p,q,0);
    }
    int helper(TreeNode* root, int p, int q, int depth){
        if(root == NULL) return 0;
        
        int left = helper(root->left,p,q,depth+1);
        int right = helper(root->right,p,q,depth+1);
        
        if(root->val == p||root->val == q) return abs(max(left,right)-depth);
        if(left&&right) return left+right;
        else return max(left,right);
    }
};