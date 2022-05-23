bool canPartition(vector<int> &arr, int n){
	// Write your code here.
    int s=accumulate(arr.begin(),arr.end(),0);
    if(s%2) return false;
    int k=s/2;
    vector<vector<bool>>dp(n, vector<bool>(k+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake = dp[ind-1][target];
            bool take{false};
            if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take|notTake;
        }
    }
    return dp[n-1][k];
}
