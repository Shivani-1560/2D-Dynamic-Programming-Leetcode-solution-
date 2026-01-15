class Solution {
public:
     long long total_ways(int i,int value,vector<int>&coins,vector<vector<int>>&dp){
     if(i==0) return (value%coins[i]==0);
      if(dp[i][value]!=-1) return dp[i][value];
     long long notake=total_ways(i-1,value,coins,dp);
    long long take=0;
     if(coins[i]<=value) take=total_ways(i,value-coins[i],coins,dp);
     return dp[i][value]=take+notake;
          }

     
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return total_ways(n-1,amount,coins,dp);
    }
};