struct comp{
    bool operator()(const string& str1, const string& str2){
        return str1.size() < str2.size();
    }
};
inline bool checkPossibility(string& s1, string& s2){
    if(s1.size() != s2.size()+1) return false;
    int first{}, second{};
    
    while(first < s1.size()){
        if(s1[first]==s2[second]) first++, second++;
        else first++;
    }
    return (first==s1.size() && second==s2.size());
}
int longestStrChain(vector<string> &arr){
    // Write your code here.
    int n=arr.size();
    sort(arr.begin(), arr.end(), comp());
    
    vector<int>dp(n,1);
    int maxi=1;
    
    for(int index=0;index<n;index++){
        for(int prev_index=0;prev_index<index;prev_index++){
            if(checkPossibility(arr[index], arr[prev_index])
              &&
              dp[index] < 1 + dp[prev_index]){
                dp[index] = 1 + dp[prev_index];
            }
        }
        maxi = max(maxi, dp[index]);
    }
    return maxi;
}
