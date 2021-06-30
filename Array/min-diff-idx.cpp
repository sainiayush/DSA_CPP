int findMinDiff(int arr[],int n,int x,int y){
 
  int x_idx=n, y_idx=n, min_diff=INT_MAX;
  
  for(int i=0;i<n;i++){
    if(x==arr[i]){
      x_idx=i;
      if(y_idx!=n){
        min_diff = min(min_diff,x_idx-y_idx);
      }
    } if(arr[i]==y){
      y_idx=i;
      if(x_idx!=n){
        min_diff=min(min_diff,x_idx=y_idx);
      }
    }
    
  }
  return min_diff;
}
