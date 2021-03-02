// DFS + Trie
class AutocompleteSystem {
public:
    class TrieNode{
    public:
        TrieNode* child[27];
        int fre = 0;
        vector<int> idxs;
        TrieNode(){
            for(auto &c: child) c = NULL;
        }
    };
    void insert(string s, int freq){
        TrieNode* p = root;
        for(char c: s){
            int idx = (c==' ')? 26: c-'a';
            if(!p->child[idx]){
                p->child[idx] = new TrieNode();
                p->idxs.push_back(idx);
            } 
            p = p->child[idx];
        }
        p->fre += freq;
    }
    struct cmp{
        bool operator()(const pair<string,int>& a,const pair<string,int>&b){
            if(a.second == b.second){
                return a.first>b.first;
            }
            return a.second<b.second;
        }  
    };
    void dfs(TrieNode* p, string s,priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>& pq){
        if(p->idxs.size()==0) {
            pq.push(make_pair(s,p->fre));
            return;
        }
        if(p->fre!=0) pq.push(make_pair(s,p->fre));
        for(int i=0;i<p->idxs.size();++i){
            if(p->idxs[i]==26) s+=' ';
            else s += p->idxs[i]+'a';
            dfs(p->child[p->idxs[i]],s,pq);
            s.pop_back();
        }
    }
    vector<string> search(string s){
        vector<string> res;
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
        TrieNode* p = root;
        for(char c: s){
            int idx = (c==' ')? 26: c-'a';
            if(!p->child[idx]) return{};
            p = p->child[idx];
        }
        dfs(p,s,pq);
        for(int i=0;i<3;++i){
            if(pq.empty()) break;
            auto t = pq.top();pq.pop();
            res.push_back(t.first);
        }
        return res;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for(int i=0;i<sentences.size();++i){
            insert(sentences[i],times[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c=='#'){
            insert(prefix,1);
            prefix = "";
            return {};
        }
        prefix += c;
        return search(prefix);      
    }
private:
    TrieNode* root;
    string prefix = "";

};

// Map 
// 别想了太慢了留作纪念吧
class AutocompleteSystem {
public:
    struct cmp{
        bool operator()(const pair<string,int>& a,const pair<string,int>&b){
            if(a.second == b.second){
                return a.first>b.first;
            }
            return a.second<b.second;
        }  
    };
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i=0;i<sentences.size();++i){
            m[sentences[i]] += times[i];
        }
    }   
    vector<string> input(char c) {
        vector<string> res;
        if(c=='#'){
            m[prefix]++;
            prefix = "";
            return {};
        }
        prefix += c;
        
        for(auto iter: m){
            bool matched = true;
            for(int i=0;i<prefix.size();++i){
                if(prefix[i]!=iter.first[i]) {
                    matched = false;
                    break;
                }
            }
            if(matched) {
                pq.push(iter);
            }
        }     
        for(int i=0;i<3;++i){
            if(pq.empty()) break;
            auto t = pq.top();pq.pop();
            res.push_back(t.first);
        }
        pq = {};
        return res;
    }
private:
    unordered_map<string,int> m;
    string prefix = "";
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
};