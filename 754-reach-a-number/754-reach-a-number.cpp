class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        if(target==0) return 0;
        int sum = 0,steps = 0;
        while(sum<target){
            sum += steps;
            steps++;
        }
        while((sum-target)&1){
            sum += steps;
            steps++;
        }
        return steps-1;      
    }
};