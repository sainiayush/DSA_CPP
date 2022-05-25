#include<vector>
#include<algorithm>
int longestPalSub(string& str,string& str1,int i1){
    vector<vector<int>>dp(i1+1, vector<int>(i1+1,0));
    
    for(int i=1;i<=i1;i++){
        for(int j=1;j<=i1;j++){
            if(str[i-1]==str1[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[i1][i1];
}
int minInsertion(string &str){
    // Write your code here.
    string B{str};
    int i1=str.size();
    reverse(B.begin(),B.end());
    return i1-longestPalSub(str,B,i1);
}
