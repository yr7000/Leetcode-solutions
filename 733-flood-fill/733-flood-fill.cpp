class Solution {
public:
    int M,N;
    void dfs(int sr,int sc,int newColor,vector<vector<int>>& image,int oldColor){
        if(sr<0 or sr>=M or sc<0 or sc>=N or image[sr][sc]!=oldColor) return;
        image[sr][sc] = newColor;
        dfs(sr+1,sc,newColor,image,oldColor);
        dfs(sr-1,sc,newColor,image,oldColor);
        dfs(sr,sc+1,newColor,image,oldColor);
        dfs(sr,sc-1,newColor,image,oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        M = image.size();
        N = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor==newColor) return image;
        dfs(sr,sc,newColor,image,image[sr][sc]);
        return image;
    }
};