int peakElement(int arr[],int n){
 
  int lo=0, hi=n-1;
  while(lo<hi){
   int mid = lo +(hi-lo)>>1;
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 && arr[mid]>=arr[mid+1]))
      return mid;
    else if(mid>0 && arr[mid]<arr[mid+1])
      lo=mid+1;
    else
      hi=mid-1;
  }
  return -1;
}
