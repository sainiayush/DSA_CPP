#include<vector>
#include<algorithm>
int longestPalSub(string& str,string& str1,int i1){
    vector<int> prev(i1+1,0), curr(i1+1,0);
    
    for(int i=1;i<=i1;i++){
        for(int j=1;j<=i1;j++){
            if(str[i-1]==str1[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j], curr[j-1]);
        }
        prev=curr;
    }
    return prev[i1];
}
int minInsertion(string &str){
    // Write your code here.
    string B{str};
    int i1=str.size();
    reverse(B.begin(),B.end());
    return i1-longestPalSub(str,B,i1);
}
