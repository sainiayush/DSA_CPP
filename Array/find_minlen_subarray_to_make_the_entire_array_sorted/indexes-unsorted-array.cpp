vector<int> printUnsorted(int arr[],int n){
  vector<int>res;
  
  int s=0,e=0;
  
  for(int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
      s=i;
      break;
    }
}
  if(s==n-1){
   res.push_back(0);
    res.push_back(0); 
    return res;
  }
  
  for(int j=n-2;j>=0;j--){
   if(arr[j+1]<arr[j]){
   e=j;
     break;
   }
  }
  
  int mn=arr[s], mx=arr[s];
  
  for(int i=s+1;i<=e;i++){
   if(arr[i]>mx)
     mx=arr[i];
    if(arr[i]<mn)
      mn=arr[i];
  }
  
  for(int i=0;i<s;i++){
   if(arr[i]>mn) {
    s=i;
     break;
   }
  }
  
  for(int i=n-1;i<>=e+1;i--){
   if(arr[i]<mx) {
    e=i;
     break;
   }
  }
  res.push_back(s);
  res.push_back(e);
 return res; 
}
