
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int mod =1e9+7;
    int sum=accumulate(arr.begin(), arr.end(), 0);
    if((sum-d)<0 or (sum-d)%2) return 0;
    int k=(sum-d)/2;
    vector<vector<int>>dp(n, vector<int>(k+1, 0));
    
    if(!arr[0]) dp[0][0]=2;
    else dp[0][0]=1;
    
    if(arr[0] and arr[0]<=k) dp[0][arr[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int target=0;target<=k;target++){
            int notTake=dp[i-1][target];
            int take=0;
            if(arr[i]<=target) take=dp[i-1][target-arr[i]];
            dp[i][target]=(take+notTake)%mod;
        }
    }
    return (dp[n-1][k])%mod;
}


