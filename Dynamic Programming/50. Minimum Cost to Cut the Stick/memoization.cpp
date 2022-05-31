#include<algorithm>
int f(vector<int>& cuts,int i,int j,vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost = cuts[j+1]-cuts[i-1] + f(cuts,i,ind-1,dp) +
                   f(cuts,ind+1,j,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] =  mini;
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    vector<vector<int>>dp(n+3, vector<int>(n+3,-1));
       cuts.emplace_back(n);
       cuts.insert(cuts.begin(), 0);
       sort(cuts.begin(),cuts.end());
    return f(cuts,1,c,dp);
}
