int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    vector<vector<int>> dp(lt+1, vector<int>(ls+1,0));
    int prime = 1e9+7;
    for(int i=0;i<=lt;i++) dp[i][0]=1;
    for(int j=1;j<=ls;j++) dp[0][j]=0;
    
    for(int i=1;i<=lt;i++){
        for(int j=1;j<=ls;j++){
            if(t[i-1]==s[j-1]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[lt][ls];
} 
