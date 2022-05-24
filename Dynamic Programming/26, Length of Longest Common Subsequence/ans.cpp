#include<bits/stdc++.h>
using namespace std;

void printLCS(string& str1, string& str2,int i1,int i2){
  vector<vector<int>>dp(i1+1, vector<int>(i2+1,0));

  for(int i=0;i<=i1;i++) dp[i][0]=0;
  for(int i=0;i<=i2;i++) dp[0][i]=0;

  for(int i=1;i<=i1;i++){
    for(int j=1;j<=i2;j++){
      if(str1[i-1]==str2[j-1]) dp[i][j] = 1+dp[i-1][j-1];

      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  int len=dp[i1][i2];
  cout<<"Length of the Longest Common Subsequence (LCS) is : "<<len<<'\n';
  string ans{""};

  for(int i=0;i<len;i++) ans.append("$");

  int index{len-1};

  int i{i1}, j{i2};

  while(i>0 and j>0){
    if(str1[i-1]==str2[j-1]) {
      ans[index] = str1[i-1];
      index--;
      j--; i--;
    }else if(dp[i-1][j]>dp[i][j-1]) i--;
    else j--;
  }

  cout<<"& The Longest Common Subsequence (LCS) is : "<<ans;
}

int main(){

  int t;
  cin>>t;
  while(t--){
    int n1,n2;
    cin>>n1>>n2;
    string s2,s1;
    cin>>s1;
    cin>>s2;

    printLCS(s1,s2,n1,n2);
    cout<<'\n';
  }

  return 0;
}
