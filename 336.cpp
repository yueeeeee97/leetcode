//Method 1:
// Map[reversed_string] = index
// Edge case - If empty string exists,check whether palindrome word exists.
// Main logic part. Partition the word into left and right, 
// case 1: lls sl, left = l, right = ls, m[right] exists and left is palindrome
// case 2: sll ls, left = sl, right = l, m[left] exists and right is palindrome
class Solution {
public:
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();++i){
            string word = words[i];
            reverse(word.begin(),word.end());
            m[word] = i;
        }
        if(m.count("")){
             for(int i = 0; i < words.size(); i++){
                 if(i == m[""]) continue;
                 if(isPalindrome(words[i])) res.push_back({m[""], i}); 
             }
         }
        for(int i=0;i<n;++i){
            for(int j=0;j<words[i].size();++j){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                
                if(m.count(left)&&isPalindrome(right)&&m[left]!=i)
                    res.push_back({i,m[left]});
                if(m.count(right)&&isPalindrome(left)&&m[right]!=i)
                    res.push_back({m[right],i});
            }
        }
        return res;
    }
};


//Method 2:
// Same idea, use trie
// why so so so slow
class Solution {
public:
    class TrieNode{
    public:
        TrieNode* child[26];
        int index=-1;
        TrieNode(){
            for(auto &c: child) c = NULL;
        }
    };
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    void insert(string s,int idx){
        TrieNode* p = root;
        for(char c: s){
            int idx = c -'a';
            if(!p->child[idx]) p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->index = idx;
    }
    int search(string s){
        TrieNode* p =root;
        for(char c: s){
            int idx = c-'a';
            if(!p->child[idx]) return -1;
            p = p->child[idx];
        }
        return p->index;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        vector<vector<int>> res;
        for(int i=0;i<words.size();++i){
            string wordTmp = words[i];
            reverse(wordTmp.begin(),wordTmp.end());
            insert(wordTmp,i);
        }
        for(int i=0;i<words.size();++i){
            if(words[i]==""){
                for(int j=0;j<words.size();++j){
                    if(isPalindrome(words[j])&&j!=i)
                        res.push_back({i,j});
                }
            }else{
                for(int j=0;j<words[i].size();++j){
                    string left = words[i].substr(0,j);
                    string right = words[i].substr(j);
                    int existRight = search(right);
                    int existLeft = search(left);
                    
                    if(isPalindrome(left)&&existRight!=-1&&existRight!=i){
                        res.push_back({existRight,i});
                    }
                    if(isPalindrome(right)&&existLeft!=-1&&existLeft!=i){
                        res.push_back({i,existLeft});
                    }
                }   
            }
        }
        return res;
    }
private:
    TrieNode* root;
};
