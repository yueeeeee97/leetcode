class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode():isEnd(false){
        for(auto &t:child) t=NULL;
    }
};
class Trie {
    private:
    TrieNode *root;
    void clear(TrieNode *root){
        for(int i = 0; i < 26; i++){
            if(root->child[i] != NULL){
                clear(root->child[i]);
            }
        }
        delete root;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        clear(root);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmp = root;
        for(char c:word){
            int i = c-'a';
            if(!tmp->child[i]) tmp->child[i]= new TrieNode();
            tmp = tmp->child[i];
        }
        tmp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp = root;
        for(char c:word){
            int i = c-'a';
            if(!tmp->child[i]) return false;
            tmp = tmp->child[i];
        }
        return tmp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for(char c:prefix){
            int i = c-'a';
            if(!tmp->child[i]) return false;
            tmp = tmp->child[i];
        }
        return true;
    }
};