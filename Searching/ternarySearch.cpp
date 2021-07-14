int ternarySearch(int *arr,int n,int x){
 
  int lo=0, hi=n-1;
  
  while(lo<=hi){
   int mid1 = l +(r-l)/3;
   int mid2 = r - (r-1)/3;
    
   if(arr[mid1]==x)
     return mid1;
   
   else if(arr[mid2]==x)
     return mid2;
    
   else if(arr[mid1]>x)
     hi=mid1-1;
    
   else{
     lo=mid1+1;
     hi=mid2-1;
   }
    
  }
  return -1;
  
}
