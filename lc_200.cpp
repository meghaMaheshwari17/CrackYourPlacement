// Title: 200. Number of Islands
class Solution {
public:
    void helper(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j,int m,int n){
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]=='0' || visited[i][j]==1)return;
        visited[i][j]=1;
        helper(grid,visited,i+1,j,m,n);
        helper(grid,visited,i-1,j,m,n);
        helper(grid,visited,i,j+1,m,n);
        helper(grid,visited,i,j-1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    helper(grid,visited,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};