int f(int ind,int w,vector<int>& weight,vector<int>&value,vector<vector<int>>& dp){
    if(ind==0){
        return value[0]*((int)w/weight[0]);
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake=0+f(ind-1,w,weight,value,dp);
    int take = (weight[ind]<=w)?value[ind]+f(ind,w-weight[ind],weight,value,dp):INT_MIN;
    return dp[ind][w]= max(notTake,take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>>dp(n, vector<int>(w+1,-1));
    return f(n-1,w,weight,profit,dp);
}
