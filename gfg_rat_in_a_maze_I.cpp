// Difficulty: Medium
class Solution {
  public:
    void helper(vector<vector<int>> &mat,vector<vector<int>> &visited,string a,vector<string>&ans,int i,int j,int n){
        if(i>=n || i<0 || j>=n || j<0 || mat[i][j]==0 || visited[i][j]==1)return;
        if(i==n-1 && j==n-1){
            ans.push_back(a);
            return;
        }
        visited[i][j]=1;
        helper(mat,visited,a+'U',ans,i-1,j,n);
        helper(mat,visited,a+'D',ans,i+1,j,n);
        helper(mat,visited,a+'L',ans,i,j-1,n);
        helper(mat,visited,a+'R',ans,i,j+1,n);
        visited[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        int n=mat.size();
        if(mat[0][0]==0 || mat[n-1][n-1]==0)return ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        helper(mat,visited,"",ans,0,0,n);
        return ans;
        
    }
};