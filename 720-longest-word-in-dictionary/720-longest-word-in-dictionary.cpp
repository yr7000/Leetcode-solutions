class TrieNode{
  public:
    char value;
    TrieNode** children;
    bool isTerminal;
    
    TrieNode(char value){
        this->value = value;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    
    TrieNode* root;
    
    void insert(TrieNode* root,string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        TrieNode* firstCharNode = root->children[word[0]-'a'];
        if(firstCharNode == NULL){
            firstCharNode = new TrieNode(word[0]);
            root->children[word[0]-'a'] = firstCharNode;
        }
        insert(firstCharNode,word.substr(1));
    }
    
    bool isPossibleAns(TrieNode* root,string word){
        if(word.size()==0){
            return root->isTerminal;
        }
        root = root->children[word[0]-'a'];
        return root->isTerminal and isPossibleAns(root,word.substr(1));
    }
    
public:
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insert(string word){
        insert(root,word);
    }
    
    bool isPossibleAns(string word){
        return isPossibleAns(root,word);
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* T = new Trie();
        for(string word:words){
            T->insert(word);
        }
        string bestAns = "";
        for(string word:words){
            if(T->isPossibleAns(word)){
                if(word.size() > bestAns.size()){
                    bestAns = word;
                }else if(word.size()==bestAns.size() and word < bestAns){
                    bestAns = word;
                }
            }
        }
        return bestAns;
    }
};