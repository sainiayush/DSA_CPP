int interpolationSearch(int *arr, int n,int x){
 
 int lo=0, hi=n-1;
  
  while(lo<=hi && x>=arr[lo] && arr[hi]>=x){
   
    if(lo==hi){
     if(arr[lo]==x)
       return lo;
      return -1;
      
    }
    int pos= lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
    
    if(arr[pos]==x)
      return pos;
    
    else if(arr[pos]>x)
      hi=pos-1;
    else
      lo=pos+1;
    
  }
  return -1;
  
}
