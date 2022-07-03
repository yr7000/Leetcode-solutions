class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for(auto asteroid: asteroids){
            if(asteroid<0){
                bool equalFaced = false;
                while(!stack.empty() and stack.back() <= abs(asteroid) and stack.back()>0){
                    if(stack.back() == abs(asteroid)){
                        stack.pop_back();
                        equalFaced = true;
                        break;
                    }
                    stack.pop_back();
                }
                if((stack.empty() or stack.back()<0) and equalFaced == false){
                    stack.push_back(asteroid);
                }
                
            }else{
                stack.push_back(asteroid);
            }
        }
        return stack;
    }
};