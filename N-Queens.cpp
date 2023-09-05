class Solution {
public:
    bool canPlace(int row,int col,int n,vector<string>&chessBoard){
        //3 direction check -> [1] left , [2] lowerDiagonal [3] UpperDiagonal 
        //since, filling from left to right and in one column one queen 
        //therefore , no up and down check 

        int nrow = row , ncol = col ; 

        //[1] left Check --
        while(col>=0){
            if(chessBoard[row][col--]=='Q') return false;
        }
        row=nrow; col=ncol;
        //[2] lowerDiagonal Check /
        while(row<n && col>=0){
            if(chessBoard[row++][col--]=='Q') return false;
        }
        row=nrow; col=ncol;
        //[3] UpperDiagonal  Check \-
        while(row>=0 && col>=0){
            if(chessBoard[row--][col--]=='Q') return false;
        }
    return true; //else possible to place Queen
    }
    void solve(int col,int n, vector<int>&left, vector<int>&lowerDiagonal, vector<int>&UpperDiagonal,vector<string>&chessBoard,vector<vector<string>>&Queen){
        //fill Queen Column by Column 
        if(col==n){
            Queen.push_back(chessBoard);
            return;
        }
        // Try every possibilties in each row to fill queen 
        for(int row=0;row<n;row++){
          //  if(canPlace(row,col,n,chessBoard)){
              if(!left[row] && !lowerDiagonal[row+col] && !UpperDiagonal[n-1+col-row]){
                //Place a Queen
                chessBoard[row][col]='Q' ; 
                left[row]=1;
                lowerDiagonal[row+col]=1;
                UpperDiagonal[n-1+col-row]=1;
                //further recursion call for filling queen in next column 
               // solve(col+1,n,chessBoard,Queen);
               solve(col+1,n,left,lowerDiagonal,UpperDiagonal,chessBoard,Queen);
                //Backtrack 
                chessBoard[row][col]='.' ; 
                left[row]=0;
                lowerDiagonal[row+col]=0;
                UpperDiagonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>Queen ; 
        vector<string>chessBoard(n , string(n,'.') ) ; 
        vector<int>left(n,0) , lowerDiagonal(2*n-1,0) , UpperDiagonal(2*n-1,0) ; 
        solve(0,n,left,lowerDiagonal,UpperDiagonal,chessBoard,Queen);
    return Queen ;
    }
};
