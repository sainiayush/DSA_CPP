//Most BRUTE_FORCE METHOD
#include <bits/stdc++.h>
using namespace std;

vector<int> parent, value;
vector<int> *child;
pair<int,int> *upperCeil;

void dfs(int node, int mx,int cnt){
  if(value[node] > mx){
    mx = value[node];
    cnt++;
  }

  upperCeil[node] = {mx, cnt};
  for(auto &it: child[node])
    dfs(it, mx, cnt);
}

int cal(int u,int w){
  int curr=u;

  while(true){
    int p = parent[curr];
    curr=p;
    if(upperCeil[p].first <= w)
      break;
  }
  return upperCeil[u].second - upperCeil[curr].second;
}
void solve() {
    int n;
    cin>>n;

    value.resize(n+1);
    parent.resize(n+1);

    for(int i=1;i<=n;++i) 
      cin>>value[i];
    
    child = new vector<int>[n+1];

    parent.resize(n+1);

    for(int i=2;i<=n;++i){
      cin>>parent[i];
      child[parent[i]].emplace_back(i);
    }

    upperCeil = new pair<int,int>[n+1];
    upperCeil[0]={0,0};

    dfs(1,0,0);

    int pr{};
    
    int q;
    cin>>q;

    while(q--){
      int u,w;
      cin>>u>>w;

      u ^= pr;
      w ^= pr;


      pr=cal(u,w);
      cout<<pr<<'\n';
    }
}

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
