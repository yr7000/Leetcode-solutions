class Solution {
public:
    string reverseVowels(string s) {
        int i =0,j=s.size()-1;
        string vowels = "aeiouAEIOU";
        while(i<=j){
            bool ifound = false,jfound = false;
            for(int k=0;k<vowels.size();k++){
                ifound = ifound or vowels[k]==s[i];
                jfound = jfound or vowels[k]==s[j];
            }
            if(ifound and jfound){
                swap(s[i++],s[j--]);
            }else if(ifound){
                j--;
            }else if(jfound){
                i++;
            }else{
                i++;
                j--;
            }
        }
        return s;
    }
};