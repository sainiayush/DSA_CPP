int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>>dp(n, vector<int>(w+1,0));
    
    for(int i=weight[0];i<=w;i++) dp[0][i]=profit[0]*((int) i/weight[0]);
    
    for(int ind=1;ind<n;ind++){
        for(int wg=0;wg<=w;wg++){
            int notTake=0+dp[ind-1][wg];
            int take = INT_MIN;
                if(weight[ind]<=wg) take=profit[ind]+dp[ind][wg-weight[ind]];
            dp[ind][wg]=max(notTake,take);
        }
    }
    return dp[n-1][w];
}
