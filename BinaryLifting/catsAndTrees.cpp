#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define MAXBIT 19

vector<int> cats, parent;
vector<bool> occupied;
void build(vector<vector<int>>& table, int n){
  table[0]=parent;

  for(int i=1;i<=MAXBIT;++i)
    for(int j=1;j<=n;++j)
      table[i][j] = table[i-1][table[i-1][j]];
}

int cal(int cat,vector<vector<int>>& table){
  int curr=cats[cat];
  if(occupied[curr]) 
    return 0;

  int jump=1;

  for(int i=MAXBIT;i>=0;--i){
    int jp = table[i][curr]; //2^i parent of curr

    if(occupied[jp]){

    }else{
      jump += (1<<i);
      curr=jp;
    }
  }

  occupied[curr]=true;
  return jump;
}
void solve() {
    int n;
    cin>>n;

    parent.resize(n+1);
    cats.resize(n+1);

    parent[0]=0;
    for(int i=1; i<=n; i++)
      cin>>parent[i];

    for(int i=1; i<=n; i++)
      cin>>cats[i];

    vector<vector<int>> table(MAXBIT+1, vector<int>(n+1));

    build(table,n);

    occupied.resize(n+1);
    occupied[0] = true;

    for(int i=1; i<=n; i++){
      cout<<cal(i,table)<<'\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    //std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
