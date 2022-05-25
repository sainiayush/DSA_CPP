#include<vector>
#include<algorithm>
int longestPalindromeSubsequenceUtil(string& str1,string& str2,int ind){
    vector<vector<int>>dp(ind+1, vector<int>(ind+1,0));
    
    for(int i=1;i<=ind;i++){
        for(int j=1;j<=ind;j++){
            if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[ind][ind];
}
int longestPalindromeSubsequence(string s){
    // Write your code here.
    int i1=s.size();
    string B{s};
    reverse(B.begin(),B.end());
    return longestPalindromeSubsequenceUtil(s,B,i1);
}
