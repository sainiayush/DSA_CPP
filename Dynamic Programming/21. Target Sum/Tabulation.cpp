int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int MOD =(int)1e9+7;
    int totSum=accumulate(arr.begin(), arr.end(), 0);
    if((totSum-target)<0 or (totSum-target)%2) return 0;
    int k = (totSum-target)/2;
    vector<vector<int>>dp(n, vector<int>(k+1, 0));
    
    if(!arr[0]) dp[0][0]=2;
    else dp[0][0]=1;
    
    if(arr[0] and arr[0]<=k) dp[0][arr[0]]=1;
    
    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=k;tar++){
            int notTake=dp[ind-1][tar];
            int take{};
            if(arr[ind]<=tar) take=dp[ind-1][tar-arr[ind]];
            dp[ind][tar]=(take+notTake)%MOD;
        }
    }
    return dp[n-1][k];
}
