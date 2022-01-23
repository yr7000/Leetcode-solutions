// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int countLessThanEqualK = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k) countLessThanEqualK++;
        }
        int ans;
        int countGreaterThanK = 0;
        for(int i=0;i<n;i++){
            if(i<countLessThanEqualK){
                if(arr[i]>k) countGreaterThanK++;
                if(i==countLessThanEqualK-1){
                    ans = countGreaterThanK;
                }
            }else{
                if(arr[i-countLessThanEqualK]>k) countGreaterThanK--;
                if(arr[i]>k) countGreaterThanK++;
                ans = min(ans,countGreaterThanK);
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends