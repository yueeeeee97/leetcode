// class Solution {
// public:
//     bool dfs(TreeNode* root, vector<int>& voyage, int start, int end) {
//         if (start > end) return false;
//         if (!root) return true;
//         if (root -> val != voyage[start]) return false;
//         int leftidx = 0, rightidx = 0;
//         for (int i = start; i <= end; ++i) {
//             if (root -> left && voyage[i] == root -> left -> val) leftidx = i;
//             if (root -> right && voyage[i] == root -> right -> val) rightidx = i;
//         }
//         if (leftidx && rightidx && leftidx > rightidx) {
//             res.push_back(root -> val);
//         }
//         if (root -> left && !leftidx) return false;
//         if (root -> right && !rightidx) return false;
//         if (leftidx && leftidx > rightidx) {
//             return dfs(root -> left, voyage, leftidx, end) && dfs(root -> right, voyage, rightidx, leftidx - 1);
//         }else if (rightidx && leftidx < rightidx) {
//             return dfs(root -> left, voyage, leftidx, rightidx - 1) && dfs(root -> right, voyage, rightidx, end);
//         }
//         return true;
//     }
//     vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
//         return dfs(root, voyage, 0, voyage.size() - 1) ? res : vector<int>{-1};
//     }
// private: 
//     vector<int> res;
// };
class Solution {
public:
    bool dfs(TreeNode* root, vector<int>& voyage) {
        if (!root) return true;
        if (root -> val != voyage[i++]) return false;
        if (root -> left && root -> left -> val != voyage[i]) {
            res.push_back(root -> val);
            return dfs(root -> right, voyage) && dfs(root -> left, voyage);
        }
        return dfs(root -> left, voyage) && dfs(root -> right, voyage);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return dfs(root, voyage) ? res : vector<int>{-1};
    }
private: 
    vector<int> res;
    int i = 0;
};