int missingTerm(int arr[],int n){
 
 int d=(arr[n-1]-arr[0])/n;
  
  int lo=0, hi=n-1;
  
  while(lo<=hi){
    int mid = lo + (hi-lo)>>2;
    
    if(mid+1<n && arr[mid+1]-arr[mid]!=d)
      return arr[mid+1]-d;
    
    if(mid-1>=0 && arr[mid]-arr[mid-1]!=d)
      return arr[mid-1]+d;
    
    if(arr[mid]-arr[0]!=(mid*d))
      hi=mid-1;
    
    else
      lo=mid+1;
  }
  return -1;
  
}
