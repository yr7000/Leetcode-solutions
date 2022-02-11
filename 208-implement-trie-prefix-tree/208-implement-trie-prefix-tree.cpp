class TrieNode{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
        
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++) children[i] = NULL;
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

    void insertWord(TrieNode* root,string word){
        if(word.size()==0) {
            root->isTerminal = true;
            return;
        }
        char firstChar = word[0];
        TrieNode* firstCharNode = root->children[firstChar-'a'];
        if(firstCharNode==NULL){
            firstCharNode = new TrieNode(firstChar);
            root->children[firstChar-'a'] = firstCharNode;
        }
        insertWord(firstCharNode,word.substr(1));
    }
    
    bool searchWord(TrieNode* root,string word){
        if(word.size()==0){
            return root->isTerminal == true;
        }
        char firstChar = word[0];
        if(root->children[firstChar-'a'] == NULL) return false;
        return searchWord(root->children[firstChar-'a'],word.substr(1));
    }
    
    bool startsWithWord(TrieNode* root,string word){
        if(word.size()==0){
            return true;
        }
        char firstChar = word[0];
        if(root->children[firstChar-'a'] == NULL) return false;
        return startsWithWord(root->children[firstChar-'a'],word.substr(1));   
    }
    
public:
        
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertWord(root,word);
        return;
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWithWord(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */