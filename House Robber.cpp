class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take = nums[ind]+solve(ind-2,nums,dp) ; 
        int notTake  = solve(ind-1,nums,dp);
        return dp[ind]=max(take,notTake);
    }
    int tab(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>dp(n,0);
        dp[0]=nums[0] ; 
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+(i>1?dp[i-2]:0));
        }
    return dp[n-1];
    }
    int tabs(vector<int>& nums) {
        int n = nums.size(); 
        int prev=nums[0],prev2=0;
        for(int i=0;i<n;i++){
            int curr = max(prev,nums[i]+(i>1?prev2:0));
            prev2=prev;
            prev=curr;
        }
    return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size(); 
       // vector<int>dp(n,-1);
       // return solve(n-1,nums,dp);
       //return tab(nums);
       return tabs(nums);
    }
};
