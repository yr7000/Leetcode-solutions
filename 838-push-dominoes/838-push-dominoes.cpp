class Solution {
public:
    string pushDominoes(string s) {
        s = "L" + s;
        s += "R";
        int i=0;
        while(i<s.size()-1){
            int j = i+1;
            while(j<s.size()){
                if(s[j]!='.') break;
                j++;
            }
            if(s[i]==s[j]){
                for(int k=j;k>=i;k--) s[k] = s[i];
            }else if(s[i]=='R' and s[j]=='L'){
                int tempI = i,tempJ = j;
                while(tempI<tempJ){
                    s[tempI++] = 'R';
                    s[tempJ--] = 'L';
                }
            }
            i = j;
        }
        s.pop_back();
        s = s.substr(1);
        return s;
    }
};