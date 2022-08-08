#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define MAXBIT 17

void dfs(int node,int l,vector<int>* adj, vector<int>& parent,vector<int>& level){
  level[node]=l;

  for(auto &it: adj[node]){
    parent[it]=node;
    dfs(it, l+1, adj, parent, level);
  }
}

int lca(int a,int b,vector<int>& parent,vector<int>& level, vector<vector<int>>& table){
  if(level[a] > level[b]) 
    swap(a,b);

  int k=level[b] - level[a];

  for(int i=MAXBIT;i>=0;--i){
    if((1<<i)&k)
      b=table[i][b];
  }

  if(a==b)  
    return a;

  for(int i=MAXBIT;i>=0;--i){
    int up=table[i][a];
    int vp=table[i][b];
    if(up!=vp){
      a=up;
      b=vp;
    }
  }

  a=parent[a];
  return a;

}

void build(vector<vector<int>>& table, vector<int>& parent,int n){
  table[0] = parent;

  for(int i=1;i<=MAXBIT;++i){
    for(int j=1;j<=n;++j)
      table[i][j] = table[i-1][table[i-1][j]];
  }
}
void solve(int testcase) {
    int n;
    cin>>n;

    vector<int> adj[n+1];

    for(int i=1;i<=n;i++){
      int cnt;
      cin>>cnt;

      for(int j=0;j<cnt;j++){
        int x;
        cin>>x;

        adj[i].emplace_back(x);
      }
    }

    vector<int> parent(n+1), level(n+1);

    dfs(1,1,adj,parent,level);

    vector<vector<int>> table(MAXBIT+1, vector<int>(n+2));
    build(table, parent,n);

    int q;
    cin>>q;

    cout<<"Case "<<testcase<<":\n";
    while(q--){
      int l,r;
      cin>>l>>r;

      cout<<lca(l,r,parent,level,table)<<'\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    for(int i=1;i<=t;++i) {
        solve(i);
    }
    
    return 0;
}
