#include<vector>
#include<algorithm>
int longestPalindromeSubsequenceUtil(string& str1,string& str2,int ind){
    vector<int> prev(ind+1,0), curr(ind+1,0);
    
    for(int i=1;i<=ind;i++){
        for(int j=1;j<=ind;j++){
            if(str1[i-1]==str2[j-1]) curr[j]=1+prev[j-1];
            else curr[j] = max(prev[j], curr[j-1]);
        }
        prev=curr;
    }
    return prev[ind];
}
int longestPalindromeSubsequence(string s){
    // Write your code here.
    int i1=s.size();
    string B{s};
    reverse(B.begin(),B.end());
    return longestPalindromeSubsequenceUtil(s,B,i1);
}
