class Solution {
public:
         vector<vector<int>>dp;
    bool ispal(string &s, int i, int j){
   
          if(i>=j) return true;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]) 
        return dp[i][j]= ispal(s, i+1, j-1);
        return dp[i][j]= false;
    }
    string longestPalindrome(string s) {
       int n=s.length();
       dp.assign(n, vector<int>(n, -1));

       int maxi_len=INT_MIN;
       int starting_idx=0;

       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(ispal(s,i,j)){
                if(j-i+1>maxi_len){
                    starting_idx=i;
                    maxi_len=j-i+1;
                }
            }
        }
       }
      return s.substr(starting_idx,maxi_len);
    }
};