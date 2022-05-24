int cutRod(vector<int> &price, int n){
	// Write your code here.
    vector<vector<int>>dp(n, vector<int>(n+1,0));
    for(int i=0;i<n+1;i++) dp[0][i] = price[0]*i;
    
    for(int ind=1;ind<n;ind++){
        for(int len=0;len<=n;len++){
            int notTake=0+dp[ind-1][len];
            int take=(ind+1<=len)?price[ind]+dp[ind][len-(ind+1)]:INT_MIN;
            dp[ind][len]=max(take,notTake);
        }
    }
    return dp[n-1][n];
}
