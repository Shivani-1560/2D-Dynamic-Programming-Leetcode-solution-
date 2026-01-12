class Solution {
public:

    int sum_path(vector<vector<int>>& grid, int i,int j, vector<vector<int>> &dp){

        if(i==0 && j==0) return grid[i][j];
        if(i==-1 || j==-1) return 1e9;
        if(dp[i][j]!= -1) return dp[i][j];
    int sum=0;
        int left= grid[i][j]+sum_path(grid,i,j-1,dp);
        int up= grid[i][j]+ sum_path(grid,i-1,j,dp);
         sum+=min(left,up);
        return dp[i][j]=sum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sum_path(grid,m-1,n-1,dp);
    }
};