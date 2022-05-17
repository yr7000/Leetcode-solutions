// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
    	long long int actualSum = 0LL, actualSquareSum = 0LL;
    	long long int N = n;
    	for(int i=0;i<n;i++){
    	    long long int x = arr[i];
    		actualSum += x;
    		actualSquareSum += x*x;
    	}
    	long long int formulaSum = N*(N+1)/2;
    	long long int formulaSquareSum = (N*(N+1)*(2*N + 1))/6;
    	
    	long long int sqareOfRMinusSquareofM = -actualSquareSum + formulaSquareSum;
    	long long int rMinusM = -actualSum + formulaSum;
    	
    	long long int rPlusM = sqareOfRMinusSquareofM/rMinusM;
    	
    	long long int r = (rMinusM + rPlusM)/2;
    	long long int m = rPlusM - r;
    	
        int* result = new int[2];
        result[0] = m;
        result[1] = r;
    	return result; // code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends