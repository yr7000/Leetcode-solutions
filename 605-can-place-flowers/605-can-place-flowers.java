class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int m = flowerbed.length;
        if(n==0) return true;
        if(n>m) return false;
        for(int i=0;i<m;i++){
            if(flowerbed[i]==1) continue;
            int left = i>=1?flowerbed[i-1]:0;
            int right = i+1<m?flowerbed[i+1]:0;
            if(left+right==0){
                flowerbed[i] = 1;
                n--;
                if(n==0) return true;
            }
        }
        return false;        
    }
}