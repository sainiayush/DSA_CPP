//LCA Calculations
void buildLCA(int n, vector<vector<int>>& LCA, vector<int>& parent){
  LCA[0]=parent;

  for(int i=1; i<MAXBIT; ++i)
    for(int j=1; j<=n; ++j)
      LCA[i][j] = LCA[i-1][LCA[i-1][j]];
}
int computeLCA(int a,int b, vector<int>& lvl, vector<vector<int>>& LCA){
  if(lvl[a] > lvl[b])
    swap(a, b);

  int k = lvl[b]-lvl[a];

  for(int i=MAXBIT-1; i>=0; --i)
    if((1<<i) & k)
      b=LCA[i][b];

  if(a==b)  
    return a;

  for(int i=MAXBIT-1; i>=0; --i){
    int ap = LCA[i][a];
    int bp = LCA[i][b];
    if(ap != bp){
      a=ap;
      b=bp;
    }
  }
  return LCA[0][a];
}
int computeDistance(int a, int b, vector<int>& lvl, vector<vector<int>>& LCA){
  return lvl[a] + lvl[b] - 2*lvl[computeLCA(a, b, lvl, LCA)];
}
void DFS(int node, vector<int>& p, vector<int>& lvl, vector<vector<int>>& g,int par=0, int level=1){
  lvl[node]=level;
  for(int &v: g[node]){
    if(v==par) continue;
    p[v]=node;
    DFS(v, p, lvl, g, node, level+1);
  }
}

//Centroid Decomposition
int subtree_sz;
void set_subtreesize(int node, vector<int>& sz, vector<vector<int>>& g, vector<bool>& done, int par=0){
  subtree_sz++;
  sz[node]=1;

  for(auto v: g[node]){
    if(v==par || done[v]) continue;
    set_subtreesize(v, sz, g, done, node);
    sz[node] += sz[v];
  }
}
int get_centroid(int node, vector<bool>& done, vector<vector<int>>& g, vector<int>& sz,int par=0){
  for(auto v: g[node]){
    if(v==par || done[v]) continue;
    else if(sz[v] > subtree_sz / 2) 
      return get_centroid(v, done, g, sz, node);
  }
  return node;
}
void decompose(int node, vector<int> &sz, vector<vector<int>> &g, vector<bool>& done, vector<int>& cenpar, int par=0){
  subtree_sz=0;
  set_subtreesize(node ,sz, g, done, par);
  int centroid = get_centroid(node, done, g, sz, par);
  done[centroid]=true;
  cenpar[centroid]=par;
  for(auto v: g[centroid]){
    if(v==par || done[v]) continue;
    decompose(v ,sz, g, done, cenpar, centroid);
  }
}

void upd(vector<int>& ans, int node, vector<int>& lvl, vector<vector<int>>& LCA, vector<int>& cenpar){
  int curr = node;
  while(curr){
    chmin(ans[curr], computeDistance(curr, node, lvl, LCA));
    curr = cenpar[curr];
  }
}

int query(int node, vector<int>& ans, vector<int>& lvl, vector<vector<int>>& LCA, vector<int>& cenpar){
  int ret=1e9;
  int curr=node;
  while(curr){
    chmin(ret, ans[curr] + computeDistance(curr, node, lvl, LCA));
    curr=cenpar[curr];
  }
  return ret;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  INT(n, q);
  vector<vector<int>> g(n+1);

  for(int i=0; i<n-1; ++i){
    INT(u, v);
    g[u].eb(v);
    g[v].eb(u);
  }

  vector<int> parent(n+1);
  vector<int> lvl(n+1);
  vector<vector<int>> LCA(MAXBIT, vector<int>(n+1));
  DFS(1, parent, lvl, g);
  buildLCA(n, LCA, parent);

  vector<int> sz(n+1), cenpar(n+1);
  vector<bool> done(n+1);
  
  decompose(1, sz, g, done, cenpar);
  //cout << done << endl;
  vector<int> ans(n+2, 1e9);

  upd(ans, 1, lvl, LCA, cenpar);
  for(int i=0; i<q; ++i){
    INT(type, node);
    if(type==1)
      upd(ans, node, lvl, LCA, cenpar);
    else
      cout << query(node, ans, lvl, LCA, cenpar) << endl;
  }
  //cout << cenpar;
  return 0;
}
