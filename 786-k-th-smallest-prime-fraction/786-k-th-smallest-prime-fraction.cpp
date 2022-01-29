class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        int n = arr.size();
        while(l<r){
            double mid = l+ (r-l)/2.0;
            double maxFraction = 0.0;
            int ind1,ind2;
            int countLessEqual = 0;
            int j = 1;
            for(int i=0;i<n;i++){
                while(j<n and arr[i] > mid*arr[j]) j++;
                if(j==n) break;
                countLessEqual += n-j;
                double currentFraction = (arr[i]*1.0/arr[j]);
                if(currentFraction > maxFraction){
                    maxFraction = currentFraction;
                    ind1 = i;
                    ind2 = j;
                }
            }
            if(countLessEqual == k) return {arr[ind1],arr[ind2]};
            if(countLessEqual < k) l = mid;
            else r = mid;
        }
        return {};
    }
};