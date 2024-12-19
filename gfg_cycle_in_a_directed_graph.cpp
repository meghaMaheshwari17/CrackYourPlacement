class Solution {
  public:
    bool helper(int src,vector<vector<int>>& adj,vector<int>&visited){
        visited[src]=1;
        queue<pair<int,int>>q1;
        q1.push({src,-1});
        while(!q1.empty()){
            auto p1=q1.front();
            int current=p1.first;
            int parent=p1.second;
            q1.pop();
            for(auto &x:adj[current]){
                if(!visited[x]){
                    visited[x]=1;
                    q1.push({x,current});
                }else if(parent!=x){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(helper(i,adj,visited))return true;
            }
        }
        return false;
        
    }
};