class Solution {
public:
    string minWindow(string s, string p) {
        unordered_map<char,int> countP;
        unordered_map<char,int> countS;
        int startIndex = 0;
        int bestLen = s.size()+1;
        string bestString = "";
        for(int i=0;i<p.size();i++) countP[p[i]]++;
        for(int i=0;i<s.size();i++){
            countS[s[i]]++;
            bool allFound = true;
            for(auto c:countP){
                if(countS[c.first]<countP[c.first]){
                    allFound = false;
                    break;
                }
            }
            if(allFound){
                for(int j=startIndex;j<=i;j++){
                    countS[s[j]]--;
                    if(countS[s[j]]<countP[s[j]]){
                        startIndex = j;
                        countS[s[j]]++;
                        break;
                    }
                }
                if((i-startIndex+1)<bestLen){
                    bestLen = i-startIndex+1;
                    bestString = s.substr(startIndex,bestLen);
                }
            }
        }
        return bestString;        
    }
};