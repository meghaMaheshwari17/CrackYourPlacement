// Problem: Flood Fill
class Solution {
public:
    void helper(vector<vector<int>>& image,int i,int j, int m,int n,int target,int current){
        if(i>=m || i<0 || j>=n || j<0 || image[i][j]!=current || image[i][j]==target)return;
        image[i][j]=target;
        helper(image,i+1,j,m,n,target,current);
        helper(image,i-1,j,m,n,target,current);
        helper(image,i,j+1,m,n,target,current);
        helper(image,i,j-1,m,n,target,current);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        helper(image,sr,sc,m,n,color,image[sr][sc]);
        return image;
    }
};