// time: O(logN)
// space: O(N)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> vals;
        inorder(root,nodes,vals);
        sort(vals.begin(),vals.end());
        for(int i=0;i<nodes.size();++i){
            nodes[i]->val = vals[i];
        }
    }
    void inorder(TreeNode* root,vector<TreeNode*> &nodes,vector<int> &vals){
        if(root == NULL) return;
        inorder(root->left,nodes,vals);
        nodes.push_back(root);vals.push_back(root->val);
        inorder(root->right,nodes,vals);
    }
};
// 递归（出错的两个节点必定是中序遍历里相邻的？）
//三个指针，first，second 分别表示第一个和第二个错乱位置的节点，pre 指向当前节点的中序遍历的前一个节点。
//这里用传统的中序遍历递归来做，不过再应该输出节点值的地方，换成了判断 pre 和当前节点值的大小，
//如果 pre 的大，若 first 为空，则将 first 指向 pre 指的节点，把 second 指向当前节点。
//这样中序遍历完整个树，若 first 和 second 都存在，则交换它们的节点值即可。
//// Still O(n) space complexity 递归本质是栈。所以空间复杂度还是O(N)。N为树的高度
class Solution {
public:
    TreeNode *pre = NULL, *first = NULL, *second = NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (!pre) pre = root;
        else {
            if (pre->val > root->val) {
                if (!first) first = pre;
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
    }
};

//用栈实现递归
// Always O(n) space complexity
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = NULL, *first = NULL, *second = NULL, *p = root;
        stack<TreeNode*> st;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top(); st.pop();
            if (pre) {
                if (pre->val > p->val) {
                    if (!first) first = pre;
                    second = p;
                }
            }
            pre = p;
            p = p->right;
        }
        swap(first->val, second->val);
    }
};

//Morris 遍历，这是一种非递归且不使用栈，空间复杂度为 O(1) 的遍历方法
// Now O(1) space complexity
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *cur = root, *pre = nullptr ;
        while (cur) {
            if (cur->left){
                TreeNode *p = cur->left;
                while (p->right && p->right != cur) p = p->right;
                if (!p->right) {
                    p->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    p->right = NULL;
                }  
            }
            if (pre && cur->val < pre->val){
              if (!first) first = pre;
              second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
