class Solution {
public:
    void dfs(vector<vector<int>>& grid, queue<vector<int>>& q1,
             vector<vector<int>>& vis, int i, int j, int n) {
        if (i >= n || i < 0 || j >= n || j < 0 || grid[i][j] == 0 ||vis[i][j] == 1)
            return;
        q1.push({i, j});
        vis[i][j] = 1;
        dfs(grid, q1, vis, i + 1, j, n);
        dfs(grid, q1, vis, i - 1, j, n);
        dfs(grid, q1, vis, i, j + 1, n);
        dfs(grid, q1, vis, i, j - 1, n);
    }
    bool isValid(int i, int j, int n, vector<vector<int>>& vis) {
        if (i >= n || i < 0 || j >= n || j < 0 || vis[i][j] == 1)
            return false;
        return true;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<vector<int>> q1;
        int found=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, q1, vis, i, j, n);
                    found=1;
                }
            }
        }
        vector<int> x = {1, -1, 0, 0};
        vector<int> y = {0, 0, 1, -1};
        int dist = 0;
        while (!q1.empty()) {
            int k = q1.size();
            for (int j = 0; j < k; j++) {
                auto temp = q1.front();
                q1.pop();
                for (int i = 0; i < 4; i++) {
                    int a = temp[0] + x[i];
                    int b = temp[1] + y[i];
                    if (isValid(a, b, n, vis)) {
                        if (grid[a][b] == 0) {
                            q1.push({a, b});
                            vis[a][b] = 1;
                        } else return dist;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};