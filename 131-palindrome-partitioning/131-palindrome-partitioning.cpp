class Solution {
public:
    vector<vector<string>> answer;
    
    bool isPalindrome(string s,int startIndex,int endIndex){
        while(startIndex<endIndex){
            if(s[startIndex++]!=s[endIndex--]) return false;
        }
        return true;
    }
    
    void getAnswer(string s,int startIndex,vector<string> partition){
        if(startIndex==s.size()){
            answer.push_back(partition);
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isPalindrome(s,startIndex,i)){
                partition.push_back(s.substr(startIndex,i-startIndex+1));
                getAnswer(s,i+1,partition);
                partition.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        getAnswer(s,0,partition);
        return answer;
    }
};