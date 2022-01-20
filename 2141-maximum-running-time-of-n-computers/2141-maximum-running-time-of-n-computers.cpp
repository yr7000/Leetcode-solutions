#define ll long long
class Solution {
public:
    
    bool good(ll m,ll n, vector<int>& batteries){
        ll timeCnt = 0;
        for(ll i:batteries) timeCnt += min(i,m);
        return timeCnt>=n*m;
    }
    
    ll maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(batteries.begin(),batteries.end());
        ll sum = 0;
        for(int i:batteries) sum += i;
        ll r = sum/n;
        r++;
        
        while(r>(l+1)){
            ll m = l+(r-l)/2;
            good(m,n,batteries)?l=m:r=m;
        }
        return l;
    }
};