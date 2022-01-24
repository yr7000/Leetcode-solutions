class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1) return true;
        
        bool firstLetterIsUppercase = (word[0]>=65 && word[0]<=90);
        bool isCapitalPresent = false;
        bool allcapitals = firstLetterIsUppercase;
        
        for(int i=1;i<word.size();i++){
            isCapitalPresent = isCapitalPresent or (word[i]>=65 && word[i]<=90);
            allcapitals = allcapitals && (word[i]>=65 && word[i]<=90);
        }
        
        if(firstLetterIsUppercase){
            if(allcapitals or !isCapitalPresent){
                return true;
            }else{
                return false;
            }
        }else{
            if(isCapitalPresent){
                return false;
            }else{
                return true;
            }
        }
    }
};