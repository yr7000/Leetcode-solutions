class Solution {
public:
    
    bool checkPalindrome(string s,int l,int r){
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return checkPalindrome(s,i+1,j) or checkPalindrome(s,i,j-1);
            }
        }
        return true;
    }
};