// Method 1: 
// Use one Trie and store "pre#suf"
// Can be done by map(faster)
class TrieNode{
public:
    TrieNode* child[27];
    vector<int> idx_list;
    TrieNode(){
        for(auto &c:child) c=NULL;
    }

};
class WordFilter {
private:
    TrieNode* root;
public:
    void add(string pre,string suf,int k){
        TrieNode* p = root;
        for(int i=0;i<pre.size();++i){
            int idx = pre[i]-'a';
            if(!p->child[idx]) p->child[idx]=new TrieNode();
            p = p->child[idx];
        }
        if(!p->child[26]) p->child[26] = new TrieNode();
        p = p->child[26];
        for(int i=0;i<suf.size();++i){
            int idx = suf[i]-'a';
            if(!p->child[idx]) p->child[idx]=new TrieNode();
            p = p->child[idx];
        }
        p->idx_list.push_back(k);
        
    }
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for(int k=0;k<words.size();++k){
            for (int i = 0; i <= words[k].size(); ++i) {
                for (int j = 0; j <= words[k].size(); ++j) {
                    add(words[k].substr(0, i),words[k].substr(words[k].size() - j),k);
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string t = prefix+"#"+suffix;
        TrieNode* p = root;
        for(int i=0;i<t.size();++i){
            int idx = t[i]-'a';
            if(t[i]=='#') idx = 26;
            if(!p->child[idx]) return -1;
            p = p->child[idx];
        }
        auto idxs = p->idx_list;
        return idxs.back();
    }
};

// Method 2
// Use two Trie to store pre and suf seperately
class TrieNode{
public:
    TrieNode* child[26];
    vector<int> idx_list;
    TrieNode(){
        for(auto &c:child) c=NULL;
    }
    void add(string word,int idx, int k){
        idx_list.push_back(k);
        if(idx<word.size()){
            if(!child[word[idx]-'a']) child[word[idx]-'a']=new TrieNode();
            child[word[idx]-'a']->add(word,idx+1,k);
        }  
    }
    vector<int> search(string word, int idx){
        if(idx == word.size()) return idx_list;
        else{
            if(!child[word[idx]-'a']) return {};
            else return child[word[idx]-'a']->search(word,idx+1);
        } 
    }

};
class WordFilter {
private:
    TrieNode* prefix,*suffix;
public:

    WordFilter(vector<string>& words) {
        prefix = new TrieNode();
        suffix = new TrieNode();
        for(int k=0;k<words.size();++k){
            prefix->add(words[k],0,k);
            reverse(words[k].begin(),words[k].end());
            suffix->add(words[k],0,k);
        }
    }
    
    int f(string p, string s) {
        auto pre = prefix->search(p,0);
        reverse(s.begin(), s.end());
        auto suf = suffix->search(s,0);
        int i = pre.size() - 1;
        int j = suf.size() - 1;
        while(i >= 0 && j >= 0){
            if(pre[i] == suf[j]) return pre[i];
            else if(pre[i] > suf[j]) i--;
            else j--;
        }
        return -1;
    }
};

// Method 3:
// Same as method 1 but use map

class WordFilter {
private:
    unordered_map<string,vector<int>> pre,suf;
public:

    WordFilter(vector<string>& words) {
        for(int k=0;k<words.size();++k){
            for(int i=0;i<=words[k].size();++i){
                pre[words[k].substr(0, i)].push_back(k);
                suf[words[k].substr(words[k].size()-i)].push_back(k);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(!pre.count(prefix)||!suf.count(suffix)) return -1;
        vector<int> p = pre[prefix];
        vector<int> s = suf[suffix];
        int i = p.size()-1;
        int j = s.size()-1;
        while(i>=0&&j>=0){
            if(p[i]>s[j]) i--;
            else if(p[i]<s[j]) j--;
            else return p[i];
        }
        return -1;
    }

};

// Method 4:
// Same as method 2 but use map
class WordFilter {
private:
    unordered_map<string,vector<int>> m;
public:

    WordFilter(vector<string>& words) {
        for(int k=0;k<words.size();++k){
            for(int i=0;i<=words[k].size();++i){
                for (int j = 0; j <= words[k].size(); ++j) {
                    m[words[k].substr(0, i) + "#" + words[k].substr(words[k].size() - j)].push_back(k);
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return (m.count(prefix + "#" + suffix)) ? m[prefix + "#" + suffix].back() : -1;
    }

};