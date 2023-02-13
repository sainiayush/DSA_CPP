#include<bits/stdc++.h>
using namespace std;
#define int long long

bool brute(int N){
  for(int i=2; i*i <= N; ++i)
    if(N % i == 0)
      return false;
  return true;
}
int mulMod(int a,int b,int c){
  int x=0, y=a%c;
  while(b > 0){
    if(b%2==1)
      x=(x+y)%c;
    y=(y*2ll)%c;
    b /= 2;
  }
  return x%c;
}
int binPower(int a,int n,int mod){
  a %= mod;
  int res=1;
  while(n > 0){
    if(n & 1)
      res = mulMod(res, a, mod);
    n >>= 1ll;
    a = mulMod(a, a, mod);
  }
  return res % mod;
}
bool FermatPrimalityTest(int n,int iterationCount=5){
  if(n < 4)
    return (n==2 || n==3);

  for(int i=1; i<=iterationCount; ++i){
    int a = 2 + rand() % (n-3);
    if(binPower(a, n-1, n) != 1)
      return false;
  }
  return true;
}
bool check_composite(int n,int a,int d,int s){
  int x=binPower(a, d, n);
  if(x==1 || x==n-1)
    return false;
  
  for(int r=1; r<s; ++r){
    x=x*x%n;
    if(x==n-1)
      return false;
  }
  return true;
}
bool MillerRabin(int n,int iter=5){
  if(n<4)
    return n==2 || n==3;
  
  int s=0;
  int d=n-1;
  while((d&1)==0)
    d >>= 1, ++s;

  for(int i=0; i<iter; ++i){
    int a=2+rand()%(n-3);
    if(check_composite(n, a, d, s))
      return false;
  }
  return true;
}
bool fastMillerRabin(int n){
  if(n < 2)
    return false;
  
  int r=0;
  int d=n-1;
  while((d&1))
    d >>= 1, ++r;

  for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
    if(n==a)
      return true;
    if(check_composite(n, a, d, r))
      return false;
  }
  return true;
}
signed main(){
  int tt;
  cin >> tt;
  while(tt--){
    int N;
    cin >> N;
    cout << (fastMillerRabin(N) ? "YES" : "NO");
    if(tt) cout << endl;
  }
  return 0;
}
