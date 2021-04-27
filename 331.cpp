class Solution {
public:
    using stack
    each time we check subtree valid we make it #
    bool isValidSerialization(string preorder) {
        stack<string> st;
        vector<string> vals;
        istringstream in(preorder);
        string t;
        while (getline(in, t, ',')) vals.push_back(t);
        for (int i = 0; i < vals.size(); ++i) {
            while (!st.empty() && vals[i] == "#" && st.top() == "#") {
                st.pop();
                if (st.empty()) return false;
                st.pop();
            }
            st.push(vals[i]);
        }
        return st.size() == 1 && st.top() == "#";
    }
    dfs
    bool dfs(vector<string> &vals, int &i) {
        if (i >= vals.size()) return false;
        if (vals[i] != "#") return dfs(vals, ++i) && dfs(vals, ++i);
        return true;
    }
    bool isValidSerialization(string preorder) {
        vector<string> vals;
        istringstream in(preorder);
        string t;
        while (getline(in, t, ',')) vals.push_back(t);
        int i = 0;
        return dfs(vals, i) && i == vals.size() - 1;
    }
};
