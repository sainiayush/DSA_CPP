void DFS(int node, int parent, const int& totalSum, vector<int>& subtreeSum, int& res){
    int sum = subtreeSum[node];

    for(auto v: adj[node]){
        if(v == parent)
            continue;
        DFS(v, node, totalSum, subtreeSum, res);
        sum += subtreeSum[v];
    }

    subtreeSum[node]=sum;
    
    /* 
        at one side subtree sum is 'sum' and other side
        subtree sum is 'totalSum - sum' so their difference
        will be totalSum - 2*sum, by which we'll update
        res 
    */
    if(node && abs(totalSum - 2*sum) < res)
        res=totalSum - 2*sum;
}
int getMinSubtreeSumDifference(int n){
    vector<int> subtreeSum(n);
    for(int& x: subtreeSum) cin >> x;

    int res=INT_MAX;
    int totalSum = SUM(subtreeSum);
    DFS(0, -1, totalSum, subtreeSum, res);
}
int main(){
  int n, m;
  cin >> n >> m;
  int s=0, t=14;
  adj.assign(n, vector<int>());
  for(int i=0; i<m; ++i){
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  cout << getMinSubtreeSumDifference(n) << endl;
  return 0;
}
