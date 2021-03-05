//// simpliest idea
// time complexity: O(N^2)
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL||root==p||root == q) return root;
        TreeNode* left = findLCA(root->left,p,q);
        TreeNode* right = findLCA(root->right,p,q);
        if(left&&right) return root;
        return left?left:right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        TreeNode* res = nodes[0];
        for(int i=1;i<nodes.size();++i){
            if(res == nodes[i]) continue;
            TreeNode* cur = findLCA(root,res,nodes[i]);
            res = cur;
        }
        return res;
    }

/// DFS + set
/// time complexity: O(N)
    unordered_set<int> set;
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes){
        for(auto node:nodes){
            set.insert(node->val);
        }
        return helper(root);
    }
    TreeNode* helper(TreeNode* root){
        if(root == NULL) return NULL;
        if(set.count(root->val)) return root;
        TreeNode* left = helper(root->left);
        TreeNode* right = helper(root->right);
        if(left&&right) return root;
        else if(!left&&!right) return NULL;
        else return left?left:right;
    }