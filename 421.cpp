class Solution {
    class TrieNode{
    public:
        TrieNode* child[2];
        TrieNode(){
            for(auto &c: child) c = NULL;
        }
    };
    TrieNode* root;
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(auto num:nums){
            TrieNode* p = root;
            for(int i=30;i>=0;--i){
                int bit = (num >> i) & 1;
                if(!p->child[bit]) p->child[bit] = new TrieNode();
                p = p->child[bit];
            }
        }
        int res=0;
        for(auto num: nums){
            TrieNode* p = root;
            int cur=0;
            for(int i=30;i>=0;--i){
                int bit = (num >> i) & 1;
                if(!p->child[1-bit]) p = p->child[bit];
                else{
                    p = p->child[1-bit];
                    cur+=(1<<i);
                }
            }
            res = max(res,cur);
        }
        return res;
    }
};