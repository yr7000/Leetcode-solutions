// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long a[], long long n) {
    	priority_queue<long long, vector<long long>, greater<long long>>min_heap;
    	for (int i = 0; i < n; i++) {
    		min_heap.push(a[i]);
    	}
    	long long totalCost = 0LL;
    	while (min_heap.size() > 1) {
    		long long x, y;
    		x = min_heap.top();
    		min_heap.pop();
    		y = min_heap.top();
    		min_heap.pop();
    		totalCost += (x + y);
    		min_heap.push(x + y);
    	}
    	return totalCost;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends