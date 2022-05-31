#include<vector>
bool isPalindrome(string&str, int start,int end){
    while(start<end) if(str[start++]!=str[end--]) return false;
    return true;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
    vector<int> dp(n+1,0);
    
    for(int i=n-1;i>=0;i--){
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(str,i,j)){
                int cost = 1+dp[j+1];
                minCost = min(minCost,cost);
            }
        }
        dp[i]=minCost;
    }
    return dp[0]-1;
}
