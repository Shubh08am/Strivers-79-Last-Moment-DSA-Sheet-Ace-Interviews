class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size() ; 
        vector<int>ahead(n,0),curr(n,0) ; 
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j) curr[j]=1;
                
                else if(s[i]==s[j]){
                    curr[j]=2+ahead[j-1];
                }
                else{
                    curr[j]=max(ahead[j],curr[j-1]);
                }
            }
        ahead=curr;
        }
    return ahead[n-1];
    }
};
