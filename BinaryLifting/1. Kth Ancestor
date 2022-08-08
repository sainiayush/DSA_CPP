#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define MAXBIT 17

void build(vector<vector<int>>& table, vector<int>& parent, int n){
  for(int i=0;i<n;++i)
    table[0][i]=parent[i];

  for(int i=1;i<MAXBIT;++i){
    for(int j=0;j<n;++j)
      table[i][j] = table[i-1][table[i-1][j]];
  }
}

int query(vector<vector<int>>& table, int a,int k){
  for(int i=0;i<MAXBIT;++i){
    if((1<<i) & k)
      a=table[i][a];
  }
  return a;
}
void solve() {
    int n;
    cin>>n;

    vector<int> parent(n);

    for(int i=0; i<n; i++)
      cin>>parent[i];
    
    vector<vector<int>> table(MAXBIT, vector<int>(n));
    build(table, parent, n);

    int q;
    cin>>q;

    while(q--){
      int a,k;
      cin>>a>>k;

      cout<<query(table, a, k)<<'\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
