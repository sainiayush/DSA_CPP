int f(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
    if(ind==0){
        if(target%nums[0]==0)return target/nums[0];
        else return 1e9;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int noTake= 0 + f(ind-1,nums,target,dp);
    int take = 1e9;
    if(nums[ind]<=target) take=1+f(ind,nums,target-nums[ind],dp);
    return  dp[ind][target]=min(take,noTake);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n, vector<int>(x+1, -1));
    // Write your code here.
    int ans=f(n-1,num,x,dp);
    if(ans>=1e9)return -1;
    else return ans;
}
