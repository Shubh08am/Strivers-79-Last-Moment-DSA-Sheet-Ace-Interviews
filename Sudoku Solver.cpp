class Solution {
public:
    bool canPlace(int i,int j,vector<vector<char>>& board , char ch) {
        for(int k=0;k<9;k++){
            if(board[k][j]==ch) return false;//column check
            if(board[i][k]==ch) return false;//row check
            int row = (i/3)*3+k/3;
            int col = (j/3)*3+k%3;
            if(board[row][col]==ch) return false;//3*3 check
        }
    return true;
    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size() ; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(canPlace(i,j,board,ch)) {
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                return false;
                }
            }
        }
    return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
