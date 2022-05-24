int f(int ind,vector<int>&v, vector<int>& w,int maxWeight,vector<vector<int>>& dp){
    if(ind==0){
        return (maxWeight>=w[0]) ? v[0]:0;
    }
    if(dp[ind][maxWeight]!=-1) return dp[ind][maxWeight];
    int notTake= 0 + f(ind-1,v,w,maxWeight,dp);
    int take=INT_MIN;
    if(w[ind]<=maxWeight) take = v[ind]+f(ind-1,v,w,maxWeight-w[ind],dp);
    return dp[ind][maxWeight]=max(notTake,take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
    vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
    return f(n-1,value,weight,maxWeight,dp);
}
