class Solution {
public:
    int maxArea(vector<int>& height) {
		int maxWaterArea=0, left=0, right=height.size()-1;
		while(left<right) {
			maxWaterArea = max(maxWaterArea,(right-left)*min(height[left], height[right]));
			if(height[left]<height[right]) left++;
			else right--;
		}
		return maxWaterArea;
    }
};