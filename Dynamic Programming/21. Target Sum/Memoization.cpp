int f(int ind,int target,vector<vector<int>>&dp,vector<int>& arr){
    if(ind==0){
        if(!target and !arr[0]) return 2;
        else if(!target or arr[0]==target)return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notTake=0 + f(ind-1,target,dp,arr);
    int take=(arr[ind]<=target)?f(ind-1,target-arr[ind],dp,arr):0;
    return dp[ind][target]=notTake+take;
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int MOD =(int)1e9+7;
    int totSum=accumulate(arr.begin(), arr.end(), 0);
    if((totSum-target)<0 or (totSum-target)%2) return 0;
   int k = (totSum-target)/2;
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    
    /*if(!arr[0]) dp[0][0]=2;
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
    return dp[n-1][k]; */
    return f(n-1,k,dp,arr);
}
