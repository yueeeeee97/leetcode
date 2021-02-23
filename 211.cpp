class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(): isEnd(false){
        for(auto &c:child) c = NULL;
    }
};
class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* p = root;
        for(auto s: word){
            int i = s-'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        return helper(word,root,0);
    }
    bool helper(string word, TrieNode* p, int i){
        if(i==word.size()) return p->isEnd;
        if(word[i]=='.'){
            for(auto a:p->child){
                if(a&&helper(word,a,i+1)) return true;
            }
            return false;
        }else{
            return p->child[word[i]-'a']&&helper(word,p->child[word[i]-'a'],i+1);
        }
    }
};