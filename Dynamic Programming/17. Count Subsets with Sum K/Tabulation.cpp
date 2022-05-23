int findWays(vector<int> &arr, int tar){
    // Write your code here.
    int n=arr.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(tar>=arr[0]) dp[0][arr[0]]=1;
    
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=tar;target++){
            int notPick=dp[ind-1][target];
            int pick{};
            if(arr[ind]<=target) pick=dp[ind-1][target-arr[ind]];
            dp[ind][target]=pick+notPick;
        }
    }
    return dp[n-1][tar];
}
