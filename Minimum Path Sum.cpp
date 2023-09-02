class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size() , n = grid[0].size() ; 
        vector<int>prev(n,0),curr(n,0) ; 

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
            if(i==m-1 && j==n-1) curr[n-1] = grid[m-1][n-1] ; 
            else{
                    int down = grid[i][j] , right = grid[i][j] ; 
                    if(i+1<m){
                        down+= prev[j] ; 
                    }
                    else{
                        down+=1e6;
                    }
                    if(j+1<n){
                        right+=curr[j+1] ; 
                    }  
                    else{
                        right+=1e6;
                    } 
                curr[j] = min(down,right);
                }
            }
        prev=curr;
        }
    return prev[0];
    }
};
 
