void printSnake(int **arr,int r,int c){
 
 for(int i=0;i<n;i++){
  if(i%2==0){
   for(int j=0;i<c;i++) 
     cout<<arr[i][j]<<" ";
  } else{
   for(int j=c-1;j>=0;j--)
     cout<<arr[i][j]<<" ";
  }
 }
}
