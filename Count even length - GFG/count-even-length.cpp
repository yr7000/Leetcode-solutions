//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
#define ll long long int
class Solution{
	public:
	
	ll fact[100001];
	
	ll findPow(int a, int b){
	    if(b==0) return 1LL;
	    ll sub = findPow(a,b/2);
	    ll x = (sub * sub)%mod;
	    if(b&1) return (a * x)%mod;
	    return x;
	}
	
	ll ncr(int n, int r){
	    if(r==n or r==0) return 1LL;
	    
	    ll den1 = findPow(fact[r],mod-2);
	    ll den2 = findPow(fact[n-r], mod-2);
	    ll den = (den1%mod * den2%mod)%mod;
	    return (fact[n]%mod * den%mod)%mod;
	    
	}
	
	int compute_value(int n)
	{
	    
	    
	    fact[0] = 1;
	    for(int i = 1;i<=100000;i++) fact[i] = (i%mod*fact[i-1]%mod)%mod;
	    
	    
	    ll result = 0LL;
	    
	    for(int i = 0;i<=(n/2);i++){
	        result = (result%mod + findPow(ncr(n,i) , 2)%mod)%mod;
	    }
	    result = (result%mod * 2%mod)%mod;
	    
	    if(n%2==0) return (result%mod - findPow(ncr(n,n/2) , 2)%mod + mod)%mod;
	    
	    return result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends