vector<vector<int>> tripletSum(int *arr, int n,int sum){
 
  
  vector<vector<int>>res;
  for(int i=0;i<n-2;i++){
   for(int j=i+1;j<n-1;j++){
   for(int k=j+1;k<n;k++){
     vector<int>v;
    if(arr[i]+arr[j]+arr[k]==sum){
    v.push_back({arr[i],arr[j],arr[k]});
      res.push_back(v);
    }
   }
   }
  }
  return res;
  
}
