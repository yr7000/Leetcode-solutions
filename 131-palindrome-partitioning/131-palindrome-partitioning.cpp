class Solution {
public:
    vector<vector<string>> answer;
    int dp[17][17];
    
    bool isPalindrome(string s,int startIndex,int endIndex){
        if(startIndex>=endIndex) return true;
        if(dp[startIndex][endIndex]!=-1) return dp[startIndex][endIndex];
        if(s[startIndex]==s[endIndex]) return dp[startIndex][endIndex] = isPalindrome(s,startIndex+1,endIndex-1);
        return dp[startIndex][endIndex] = false;
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
        memset(dp,-1,sizeof(dp));
        getAnswer(s,0,partition);
        return answer;
    }
};