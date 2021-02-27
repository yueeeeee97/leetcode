class Solution {
public:
    class TrieNode{
    public:
        TrieNode* child[2]; 
        TrieNode(){
            for(auto &c:child) c = NULL;
        }
    };

    void insert(int num){
        TrieNode* p = root;
        for(int i=29;i>=0;--i){
            int bit = (num >> i) & 1;
            if(!p->child[bit]) p->child[bit] = new TrieNode();
            p = p->child[bit];
        }
    }
    
    int search(int num){
        int cnt = 0;    
        TrieNode* p = root;
        for(int i=29;i>=0;--i){
            int bit = (num >> i) & 1;
            if(!p->child[1-bit]) p = p->child[bit];
            else{
                p = p->child[1-bit];
                cnt+=(1<<i);
            }
        }
        return cnt;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        vector<vector<int>> qs;
        for(int i=0;i<queries.size();++i){
            qs.push_back({queries[i][1],queries[i][0],i});
        }
        sort(nums.begin(),nums.end());
        sort(qs.begin(),qs.end());
        int minNum = *min_element(nums.begin(),nums.end());
        int j=0;
        for(auto q: qs){
            int limit = q[0];
            if(minNum > limit) res[q[2]] = -1;
            else{
                while(j<nums.size()&&nums[j]<=limit){
                    insert(nums[j++]);
                }
                res[q[2]] = search(q[1]);
            }
        }
        return res;
    }
private:
    TrieNode* root = new TrieNode();
};