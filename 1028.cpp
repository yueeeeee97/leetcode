class Solution {
public:
    TreeNode* dfs(string &S, int left, int right, int depth) {
        if (left > right) return NULL;
        string num;
        while (isdigit(S[left])) {
            num += S[left++];
        }
        TreeNode *root = new TreeNode(stoi(num));
        int leftidx = left + depth, rightidx = 0;
        for (int i = leftidx; i <= right; ++i) {
            while (i <= right && isdigit(S[i])) i++;
            if (isdigit(S[i - 1]) && i + depth <= right && isdigit(S[i + depth])) {
                rightidx = i + depth;
            }
        }
        if (rightidx) {
            root -> left = dfs(S, leftidx, rightidx - 1, depth + 1);
            root -> right = dfs(S, rightidx, right, depth + 1);
        }else {
            root -> left = dfs(S, leftidx, right, depth + 1);
            root -> right = NULL;
        }
        return root;
        
    }
    TreeNode* recoverFromPreorder(string S) {
        return dfs(S, 0, S.size() - 1, 1);
    }
};
// string &S 就不用每次都复制一遍S。快很多
class Solution {
public:
    TreeNode* dfs(string &S, int &i, int depth) {
        int d = 0;
        while (i < S.size() && S[i] == '-') {
            d++;
            i++;
        }
        if (d != depth) {
            i -= d;
            return NULL;
        }

        int val = 0;
        while (i < S.length() && isdigit(S[i]))
            val = val * 10 + (S[i++] - '0'); 
        TreeNode *root = new TreeNode(val);
        
        root -> left = dfs(S, i, depth + 1);
        root -> right = dfs(S, i, depth + 1);
        return root;
    }
    TreeNode* recoverFromPreorder(string S) {
        int idx = 0;
        return dfs(S, idx, 0);
    }
};