class Solution {
  public:
    bool helper(vector<vector<int>> &adj,vector<int>&vis,vector<int>&path,int src,int parent){
        vis[src]=1;
        path[src]=1;
        for(auto x:adj[src]){
            if(!vis[x]){
                if(helper(adj,vis,path,x,src))return true;
            }else if(path[x]){
                return true;
            }
        }
        path[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int>vis(V,0);
        vector<int>path(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(adj,vis,path,i,-1))return true;
            }
        }
        return false;
    }
};