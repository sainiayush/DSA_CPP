int DFS(int node, int parent, int& currMax){
    int max1=0, max2=0;
    int total=0;

    for(auto v: adj[node]){
        if(v == parent)
            continue;
        
        total = max(total, DFS(v, node, currMax));

        if(max1 < currMax){
            max2 = max1;
            max1 = currMax;
        }
        else if(max2 < currMax)
            max2 = currMax;
    }
    
    //including current node in result
    currMax = max1+1;
    return total;
}
int maxProductOfTwoPaths(int N){
    int res=INT_MIN;
    
    for(int i=0; i<N; ++i)
        for(auto v: adj[i]){
            int currMax=0;
            
            //excluding edge from i ---> v
            int path1=DFS(i, v, currMax);

            currMax=0;
            
            //excluding edge from v ---> i
            int path2=DFS(v, i, currMax);

            res=max(res, path1 * path2);
        }
}
int main(){
  int n, m;
  cin >> n >> m;
  adj.assign(n, vector<int>());
  for(int i=0; i<m; ++i){
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  cout << maxProductOfTwoPaths(n) << endl;
  return 0;
}
