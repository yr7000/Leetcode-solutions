class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        priority_queue<string> pq;
        vector<vector<string>> result;
        for(int i=0;i<searchWord.size();i++){
            int j = 0;
            while(j<products.size()){
                if(searchWord[i]!=products[j][i]){
                    int m = products.size();
                    swap(products[j],products[m-1]);
                    products.pop_back();
                }else{
                    pq.push(products[j]);
                    if(pq.size()>3) pq.pop();
                    j++;
                }
            }
            vector<string> sub;
            while(!pq.empty()){
                sub.push_back(pq.top());
                pq.pop();
            }
            reverse(sub.begin(),sub.end());
            result.push_back(sub);
        }
        return result;
    }
};