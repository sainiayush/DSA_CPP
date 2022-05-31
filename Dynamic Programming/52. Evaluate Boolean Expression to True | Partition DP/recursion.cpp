#include<bits/stdc++.h>
#define ll long long
int mod=1e9+7;
ll f(int i,int j,string& exp,int isTrue){
    if(i>j) return 0;
    if(i==j){
        if(isTrue) return exp[i]=='T';
        else return exp[i]=='F';
    }
    ll ways=0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        ll lT = f(i,ind-1,exp,1);
        ll lF = f(i,ind-1,exp,0);
        ll rT = f(ind+1,j,exp,1);
        ll rF = f(ind+1,j,exp,0);
        
        if(exp[ind] == '&'){ 
            // true -> T&T 
            //false -> F&F, T&F, F&T
            if(isTrue) {
                ways = (ways + (lT*rT) % mod ) % mod;
            }
            else {
                ways = (ways + (lF*rF) % mod + (lT*rF) % mod + (lF*rT) % mod) % mod;
                 }
        } 
        else if(exp[ind] == '|'){ 
            // true -> T|T, T|F, F|T
            //false -> F|F
            if(isTrue){ 
                ways = (ways + (lT*rT) % mod + (lT*rF) % mod + (lF*rT) % mod ) % mod;
            }
            else {
                ways = (ways + (lF*rF) % mod ) % mod;
            }
        }
        else { 
            // true-> T^F, F^T 
            //false-> T^T, F^F
            if(isTrue){ 
                ways = (ways + (lT*rF) % mod+ (lF*rT) % mod) % mod;
             }
            else {
                ways = (ways + (lT*rT) % mod+ (lF*rF) % mod) % mod;
            }
        }
     }
    return ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    ll n=exp.size();
    return (int)f(0,n-1,exp,1);
}
