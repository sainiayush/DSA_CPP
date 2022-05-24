int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
    vector<vector<int>>dp(n, vector<int>(maxWeight+1, 0));
  
    for(int t=weight[0];t<=maxWeight;t++) dp[0][t]=value[0];
    
    
    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int notTake= 0 + dp[ind-1][w];
            int take=INT_MIN;
            if(weight[ind]<=w) take = value[ind]+dp[ind-1][w-weight[ind]];
            dp[ind][w]=max(notTake,take);
        }
    }
    return dp[n-1][maxWeight];
}
