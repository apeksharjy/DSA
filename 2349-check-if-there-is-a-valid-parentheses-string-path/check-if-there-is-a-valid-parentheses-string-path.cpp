class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m+n+1, -1)));
        return dfs(0, 0, 0, grid, dp);
    }
    bool dfs(int x, int y, int balance, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        int m = grid.size(), n = grid[0].size();
        if (grid[x][y] == '(') balance++;
        else balance--;
        if (balance < 0 || balance > m+n) return false;
        if (x == m-1 && y == n-1) return balance == 0;
        if (dp[x][y][balance] != -1) return dp[x][y][balance];
        bool res = false;
        if (x+1 < m) res |= dfs(x+1, y, balance, grid, dp);
        if (y+1 < n) res |= dfs(x, y+1, balance, grid, dp);

        return dp[x][y][balance] = res;
    }
};

      

        
