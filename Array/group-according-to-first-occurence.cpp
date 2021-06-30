void groupArray(int *arr, int n){
 
  unordered_map<int,int>mp;
  
  for(int i=0;i<n;i++){
   mp[arr[i]]++; 
  }
  
  for(int i=0;i<n;i++){
    if(mp.find(arr[i])!=mp.end()){
   int n=freq[arr[i]];
    while(n--)
      cout<<arr[i]<<" ";
    mp.erase(arr[i]);
      }  
    }
}
