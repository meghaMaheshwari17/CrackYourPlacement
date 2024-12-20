class Solution 
{
    public:
    vector<int> x={2,2,1,-1,1,-1,-2,-2};
    vector<int>y={-1,1,2,2,-2,-2,-1,1};
    bool isValid(int x,int y,int N,vector<vector<int>>&visited){
        if(x>=N || y>=N || x<0 || y<0 || visited[x][y])return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>>visited(N,vector<int>(N,0));
	    queue<vector<int>>q1;
	    q1.push({KnightPos[0]-1,KnightPos[1]-1,0});
	    visited[KnightPos[0]-1][KnightPos[1]-1]=1;
	   
	    while(!q1.empty()){
	        vector<int>a=q1.front();
	        q1.pop();
	        if(a[0]==TargetPos[0]-1 && a[1]==TargetPos[1]-1){
	            return a[2];
	            
	        }
	        for(int i=0;i<8;i++){
	            if(isValid(a[0]+x[i],a[1]+y[i],N,visited)){
	                visited[a[0]+x[i]][a[1]+y[i]]=1;
	                q1.push({a[0]+x[i],a[1]+y[i],a[2]+1});
	            }
	        }
	    }
	    return -1;
	    
	   
	}
};