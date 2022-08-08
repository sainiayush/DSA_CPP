#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define MAXBIT 20

vector<int> arr, minStart;
vector<vector<int>> table;

void build(int n){
  table[0]=minStart;

  for(int i=1;i<MAXBIT;++i){
    for(int j=0;j<n;++j){
      int par = table[i-1][j];
      table[i][j] = par==-1 ? par :table[i-1][par];
    }
  }
}
int cal(int mx,int k){
  int ret=mx;
  /*
  for(int i=1;i<=k and ret > -1 ;++i){
    ret = minStart[ret];
  }
  */

  for(int i=MAXBIT-1;i>=0 and ret > -1;i--){
    int mask = 1<<i;
    if((mask & k))
      ret = table[i][ret];
  }

  return mx-ret;
}
void solve() {
    int k,n,s;
    cin>>n>>k>>s;

    arr.resize(n);
    for(int i=0;i<n;i++)
      cin>>arr[i];

    minStart.resize(n+1);

    int j{}, sum{};

    for(int i=0;i<n;++i){
      sum += arr[i];

      while(sum > s)
        sum -= arr[j++];
      
      minStart[i]=j-1;
    }

    int mx{};
    
    

   //RESIZING THE SPARSE TABLE
    table.resize(MAXBIT);
    for(int i=0;i<MAXBIT;++i)
      table[i].resize(n+1);

    build(n);

    for(int i=n-1;i>=0;i--){
      mx = max(mx , cal(i, k));
    }
    cout<<mx<<'\n';
}


/*
Status:
Correct Answer
Submission ID:
70844323
Time:
0.14s
*/

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
