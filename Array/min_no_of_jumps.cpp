int minJumps(vector<int>& arr){
 
  if(arr[0]==0)
    return -1;
  else if(arr.size()==1)
    return 0;
  
  else{
   int maxReach=arr[0], jumps=1, step=arr[0];
    
    for(int i=1;i<arr.size();i++){
     
      if(i==n-1)
        return jumps;
      maxReach=max(maxReach,i+arr[i]);
      step--;
      if(step==0){
        jumps++;
        if(i>=maxReach)
          return -1;
        step=maxReach-i;        
    }
  }
  
}
