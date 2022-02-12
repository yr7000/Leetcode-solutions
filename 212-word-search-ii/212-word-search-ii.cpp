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

class Solution {
public:
    
    TrieNode* root = new TrieNode('\0');
    
    void insert(TrieNode* root,string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        TrieNode* firstCharNode = root->children[word[0]-'a'];
        if(firstCharNode==NULL){
            firstCharNode = new TrieNode(word[0]);
            root->children[word[0]-'a'] = firstCharNode;
        }
        insert(firstCharNode,word.substr(1));
    }
    
    pair<int,int> dx[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<string> result;
    
    void dfs(int x,int y,vector<vector<char>>& board,TrieNode* root,int m,int n,string str){
        if(x>=m or x<0 or y>=n or y<0 or board[x][y]=='#' or root->children[board[x][y]-'a']==NULL) return;
        root = root->children[board[x][y]-'a'];
        char currentCharacter = board[x][y];
        str += currentCharacter;
        if(root->isTerminal){
            result.push_back(str);
            root->isTerminal = false;
        }
        board[x][y] = '#';
        for(int i=0;i<4;i++){
            int newx = x + dx[i].first;
            int newy = y + dx[i].second;
            dfs(newx,newy,board,root,m,n,str);
        }
        str.pop_back();
        board[x][y] = currentCharacter;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        for(string word:words){
            insert(root,word);
        }
        TrieNode* temp = root;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,board,temp,m,n,"");
            }
        }
        return result;
    }
};