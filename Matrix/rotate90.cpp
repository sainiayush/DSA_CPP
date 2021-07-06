void rotate90(vector<vector<int>>&matrix){
  for(int i=0;i<matrix.size();i++){
   for(int j=i+1;j<matrix[0].size();j++){
    swap(matrix[i][j],matrix[j][i]); 
   }
  }
  for(int i=0;i<matrx[0].size();i++){
  int lo=0, hi=matrix.size();
  while(lo<hi){
   swap(matrix[lo][i],matrix[hi][i]); 
    lo++;
    hi--;
  }
  }
}
