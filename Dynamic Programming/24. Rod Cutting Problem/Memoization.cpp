int f(int ind,vector<int>& price,int N,vector<vector<int>>& dp){
    if(ind==0) return N*price[0];
    if(dp[ind][N]!=-1) return dp[ind][N];
    int notTake=0+f(ind-1,price,N,dp);
    int take=INT_MIN;
    if((ind+1)<=N) take=price[ind]+f(ind,price,N-ind-1,dp);
    return dp[ind][N] = max(take,notTake);
}
int cutRod(vector<int> &price, int n){
	// Write your code here.
    vector<vector<int>>dp(n, vector<int>(n+1,-1));
    return f(n-1,price,n,dp);
}
