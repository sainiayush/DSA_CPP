#include<vector>
bool f(int i,int j,string& pattern,string& text,vector<vector<int>>& dp){
    if(i==0 and j==0) return true;
    if(i>0 and j==0){
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 and j>0) return false;
    if(pattern[i-1]==text[j-1] || pattern[i-1]=='?') return dp[i][j]= f(i-1,j-1,pattern,text,dp);
    if(pattern[i-1]=='*'){
        return dp[i][j]= f(i-1,j,pattern,text,dp) | f(i,j-1,pattern,text,dp);
    }
    return dp[i][j]= false;
}
bool wildcardMatching(string pattern, string text){
   // Write your code here.
    int n=pattern.size(), m=text.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    return f(n,m,pattern,text,dp);
}
