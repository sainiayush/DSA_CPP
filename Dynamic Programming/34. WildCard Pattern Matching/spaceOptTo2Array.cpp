#include<vector>
bool wildcardMatching(string pattern, string text){
   // Write your code here.
    int n=pattern.size(), m=text.size();
    vector<bool> prev(m+1, false), curr(m+1, false);
    prev[0]=true;
    
    for(int i=1;i<=n;i++){
        bool flag{true};
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1]!='*'){
                flag=false;
                break;
            }
        }
        curr[0]=flag;
        for(int j=1;j<=m;j++){
            if(pattern[i-1]==text[j-1] || pattern[i-1]=='?') curr[j]=prev[j-1];
            else if(pattern[i-1]=='*') curr[j]= prev[j] | curr[j-1];
            else curr[j]=false;
        }
        prev=curr;
    }
    return prev[m];
}
