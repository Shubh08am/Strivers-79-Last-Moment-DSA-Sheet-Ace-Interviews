class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size()  ; 
        int dp[n+1][2*k+1]; 
        memset(dp,0,sizeof(dp)) ; 
        for(int i=n-1;i>=0;i--){
            for(int m=2*k-1;m>=0;m--){
               if(m%2==0) dp[i][m]=max(-prices[i]+dp[i+1][m+1],dp[i+1][m]) ;
               else{
                int take = INT_MIN;
                if(m>0) take=prices[i]+dp[i+1][m+1];
                dp[i][m]=max(take,dp[i+1][m]) ; 
               }
            }
        }
    return dp[0][0];
    }
};
      
