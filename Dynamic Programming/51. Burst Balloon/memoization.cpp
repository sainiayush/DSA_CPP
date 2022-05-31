#include<climits>
int f(vector<int>& a,int i,int j,vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi=INT_MIN;
    for(int k=i;k<=j;k++){
        int cost = a[i-1]*a[k]*a[j+1] + f(a,i,k-1,dp) + f(a,k+1,j,dp);
        maxi=max(maxi,cost);
    }
    return dp[i][j]= maxi;
}
int maxCoins(vector<int>& a){
	// Write your code here.
    int n=a.size();
    a.insert(a.begin(),1);
    a.emplace_back(1);
    vector<vector<int>> dp(a.size()+1, vector<int>(a.size()+1,-1));
    return f(a,1,n,dp);
}
