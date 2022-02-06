class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        int n = asteroids.size();
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(asteroids[i]<0) {
                s.push(i);
                continue;
            }
            bool bothCrash = false;
            while(!s.empty() and asteroids[i] >= abs(asteroids[s.top()])){
                if(asteroids[i] == abs(asteroids[s.top()])){
                    bothCrash = true;
                }
                s.pop();
                if(bothCrash) break;
            }
            if(s.empty() and !bothCrash){
                result.push_back(asteroids[i]);
            }
        }
        int cnt = s.size();
        while(!s.empty()) {
            result.push_back(asteroids[s.top()]);
            s.pop();
        }
        reverse(result.begin(),result.end());
        reverse(result.begin(),result.begin()+cnt);
        return result;
    }
};