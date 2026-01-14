class Solution {
public:
   
   int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
       
         vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
     
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
               
        int below= matrix[i][j]+ dp[i-1][j];

        int left_diagonal= matrix[i][j];
        if(j>0) left_diagonal+=dp[i-1][j-1];
        else left_diagonal+=1e9;

        int right_diagonal= matrix[i][j];
        if(j<n-1) right_diagonal+=dp[i-1][j+1];
         else right_diagonal+=1e9;

        dp[i][j]=min(below, min(left_diagonal,right_diagonal));
            }
        }
        int ans=1e9;

        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
       
           return ans ;
    }
};