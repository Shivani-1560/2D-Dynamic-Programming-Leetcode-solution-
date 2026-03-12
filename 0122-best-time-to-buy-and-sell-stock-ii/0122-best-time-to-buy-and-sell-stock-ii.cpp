class Solution {
public:
      int best_time(vector<int>& prices, int i, int profit, int n,vector<vector<int>>&dp){
        if(i ==n ) return 0;
        if(dp[i][profit]!= -1) return dp[i][profit];
         long sum=0;
        if(profit){
            sum=max( -prices[i]+best_time(prices, i+1, 0,n,dp),
                       0+ best_time(prices, i+1, 1,n,dp));
        }

        else{
            sum= max(prices[i]+best_time(prices, i+1, 1,n,dp),
                       0+ best_time(prices, i+1, 0,n,dp));
        }
        return dp[i][profit]=sum;
      }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>>dp(n+1, vector<int>(2, -1));

        return best_time(prices,0,1,n,dp );
    }
};