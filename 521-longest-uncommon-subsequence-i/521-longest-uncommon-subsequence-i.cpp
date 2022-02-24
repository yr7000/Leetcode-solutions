class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()!=b.size()){
            return max(a.size(),b.size());
        }else{
            int result = a.size();
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]) break;
                result--;
            }
            if(result==0) return -1;
            return result;
        }
    }
};