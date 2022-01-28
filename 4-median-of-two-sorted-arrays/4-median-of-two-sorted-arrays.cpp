class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n = nums1.size();
        int m = nums2.size();
        int s = 0,e = n;
        double ans = 0.0;
        while(s<=e){
            int mid = (s+e)>>1;
            int cut1 = mid;
            int cut2 = (n+m+1)/2 - cut1;
            int l1 = cut1==0?INT_MIN:nums1[cut1-1];
            int l2 = cut2==0?INT_MIN:nums2[cut2-1];
            int r1 = cut1==n?INT_MAX:nums1[cut1];
            int r2 = cut2==m?INT_MAX:nums2[cut2];
            if(l1<=r2 and l2<=r1){
                if((n+m)&1){
                    ans = max(l1,l2);
                }else{
                    ans =  (max(l1,l2)+min(r1,r2))/2.0;                    
                }
                break;
            }else if(l1>r2){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};