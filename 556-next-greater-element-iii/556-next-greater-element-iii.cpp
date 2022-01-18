class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int ind = -1;
        if(str.size()==1) return -1;
        for(int i = str.size()-2;i>=0;i--){
            if(str[i]<str[i+1]){
                ind = i;
                break;
            }
        }
        if(ind==-1) return ind;
        int j = ind+1;
        while(j<str.size() && str[ind]<str[j]) j++;
        j--;
        swap(str[ind],str[j]);
        reverse(str.begin()+ind+1,str.end());
        long long int result = stoll(str);
        return result <= 2147483647 ? result : -1;
    }
};