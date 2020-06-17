/*
    Surrounded Regions

    Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

    A region is captured by flipping all 'O's into 'X's in that surrounded region.

    Example:
    X X X X
    X O O X
    X X O X
    X O X X
    After running your function, the board should be:

    X X X X
    X X X X
    X X X X
    X O X X
    Explanation:
    Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
    Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
    Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
class Solution {
public:
    void floodFillUtil(vector<vector<char>>& mat, int x, int y, char prevV, char newV) 
    { 
        // Base cases 
        int M = mat.size();
        int N = mat[0].size();
        if (x < 0 || x >= M || y < 0 || y >= N) 
            return; 
        if (mat[x][y] != prevV) 
            return; 


        mat[x][y] = newV; 
 
        floodFillUtil(mat, x+1, y, prevV, newV); 
        floodFillUtil(mat, x-1, y, prevV, newV); 
        floodFillUtil(mat, x, y+1, prevV, newV); 
        floodFillUtil(mat, x, y-1, prevV, newV); 
    } 
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        if (M==0)
            return;
        int N = board[0].size();
        
        for (int i=0; i<M; i++) 
          for (int j=0; j<N; j++) 
              if (board[i][j] == 'O') 
                 board[i][j] = '-'; 
  
       
       for (int i=0; i<M; i++)   
          if (board[i][0] == '-') 
            floodFillUtil(board, i, 0, '-', 'O'); 
       for (int i=0; i<M; i++)  
          if (board[i][N-1] == '-') 
            floodFillUtil(board, i, N-1, '-', 'O'); 
       for (int i=0; i<N; i++)   
          if (board[0][i] == '-') 
            floodFillUtil(board, 0, i, '-', 'O'); 
       for (int i=0; i<N; i++)  
          if (board[M-1][i] == '-') 
            floodFillUtil(board, M-1, i, '-', 'O'); 
        
       for (int i=0; i<M; i++) 
          for (int j=0; j<N; j++) 
             if (board[i][j] == '-') 
                 board[i][j] = 'X'; 
    }
};