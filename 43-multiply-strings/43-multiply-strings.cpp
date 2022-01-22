class Solution {
public:
    string multiply(string num1, string num2) {
      if(num1=="0" or num2=="0") return "0";

       int sizeOfAns = num1.size() + num2.size();
       vector<int> v(sizeOfAns,0);
       for(int i=num1.size()-1;i>=0;i--){
           for(int j=num2.size()-1;j>=0;j--){
               v[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
               v[i+j] += v[i+j+1]/10;
               v[i+j+1] %= 10; 
           }
       }
       string ans = "";
       int i = 0;
       while(v[i]==0) i++;
       while(i<v.size()) ans += (char)(v[i++] + 48);
       return ans;        
    }
};