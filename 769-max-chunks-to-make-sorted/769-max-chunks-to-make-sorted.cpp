class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0, prev =0, result = 0;
        for(int i=0;i<arr.size();i++){
            int tempSum = i*(i+1)/2 - prev*(prev+1)/2;
            sum += arr[i];
            if(tempSum==sum){
                result++;
                prev = i;
                sum = 0;
            }
        }
        return result;
    }
};