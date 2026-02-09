class Solution {
public:

    bool parti(vector<int>& nums, int target, int i, vector<vector<int>> &dp ){
        if(i==0) return nums[0]==target;
      if(target==0) return true;
      
      if(dp[i][target] != -1) return dp[i][target];
      bool not_valid= parti(nums, target,i-1, dp);
      bool valid= false;
      if(target>=nums[i]) valid=parti(nums, target-nums[i], i-1 ,dp);

      return dp[i][target]=not_valid | valid;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       
        int sum=0;
        for(int i=0; i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0 ) return false;
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return parti(nums, sum/2, n-1, dp);
    }
};