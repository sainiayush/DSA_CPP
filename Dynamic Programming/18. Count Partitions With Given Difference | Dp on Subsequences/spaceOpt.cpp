int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int mod =1e9+7;
    int sum=accumulate(arr.begin(), arr.end(), 0);
    if((sum-d)<0 or (sum-d)%2) return 0;
    int k=(sum-d)/2;
    vector<int>prev(k+1,0), curr(k+1,0);
    
    if(!arr[0]) prev[0]=2;
    else prev[0]=1;
    
    if(arr[0] and arr[0]<=k) prev[arr[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int target=0;target<=k;target++){
            int notTake=prev[target];
            int take=0;
            if(arr[i]<=target) take=prev[target-arr[i]];
            curr[target]=(take+notTake)%mod;
        }
        prev=curr;
    }
    return (prev[k])%mod;
}


