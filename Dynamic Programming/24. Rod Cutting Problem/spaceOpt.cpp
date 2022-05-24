int cutRod(vector<int> &price, int n){
	// Write your code here.
    vector<int>dp(n+1,0);
    for(int i=0;i<n+1;i++) dp[i] = price[0]*i;
    
    for(int ind=1;ind<n;ind++){
        for(int len=0;len<=n;len++){
            int notTake=0+dp[len];
            int take=(ind+1<=len)?price[ind]+dp[len-(ind+1)]:INT_MIN;
            dp[len]=max(take,notTake);
        }
    }
    return dp[n];
}
