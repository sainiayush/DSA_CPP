int f(int ind,vector<int>& num,int tar,vector<vector<int>>& dp){
    if(tar==0) return 1;
    if(ind==0) return tar==num[0];
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int notPick = f(ind-1,num,tar,dp);
    int pick = 0;
    if(num[ind]<=tar) pick=f(ind-1,num,tar-num[ind],dp);
    return dp[ind][tar]=pick+notPick;
}
int findWays(vector<int> &num, int tar){
    // Write your code here.
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return f(num.size()-1,num,tar,dp);
}
