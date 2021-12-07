bool isSafe(int row, int col, vector<string>& board, int n){
  int duprow = row;
  int dupcol = col;

  //Checking for upper Diagonal
  while(row>=0 && col>=0){
    if(board[row][col]=='Q') return false;
    row--; col--;
  }

  row = duprow;
  col = dupcol;

  //Check for left side row
  while(col>=0){
    if(board[row][col]=='Q') return false;
    col--;
  }

  col = dupcol;
  row = duprow;

  //Check for lower diagonal
  while(row<n && col>=0){
    if(board[row][col]=='Q') return false;
    row++;
    col--;
  }

  return true;

}
void solveHelper(int col, vector<vector<string>>& ans, vector<string>& board, int n){
  if(col==n){
    ans.pb(board);
    return;
  }

  loop(row, 0, n){
    if(isSafe(row, col, board, n)){
      board[row][col]='Q';
      solveHelper(col+1 ,ans, board, n);
      board[row][col]='.';
    }
  }
  
}
vector<vector<string>> solve (int n){
  vector<vector<string>>ans;

  vector<string>board(n);
  string s(n,'.');

  loop(i,0,n){
    board[i] = s;
  }
  solveHelper(0, ans, board,n);

  return ans;
}
