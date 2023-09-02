class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size() , n = grid[0].size() ; 
        vector<vector<int>>dp(m,vector<int>(n,0)) ; 

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
            if(i==m-1 && j==n-1) dp[m-1][n-1] = grid[m-1][n-1] ; 
            else{
                    int down = grid[i][j] , right = grid[i][j] ; 
                    if(i+1<m){
                        down+= dp[i+1][j] ; 
                    }
                    else{
                        down+=1e9;
                    }
                    if(j+1<n){
                        right+=dp[i][j+1] ; 
                    }  
                    else{
                        right+=1e9;
                    } 
                dp[i][j] = min(down,right);
                }
            }
        }
    return dp[0][0];
    }
};
 
