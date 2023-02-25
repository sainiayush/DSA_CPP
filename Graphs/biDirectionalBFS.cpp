vector<vector<int>> adj;
void BFS(queue<int>& q, bool* vis, int* parent){
    int curr = q.front();
    q.pop();

    for(auto v: adj[curr])
        if(!vis[v]){
            q.emplace(v);
            vis[v]=true;
            parent[v]=curr;
        }
}
int findIntersectingNode(bool* s_vis, bool* t_vis){
    for(int i=0; i<100; ++i)
        if(s_vis[i] && t_vis[i])
            return i;
    return -1;
}
void printPath(int* s_parent, int* t_parent, int s, int t,int intersectNode){
    vector<int> path;
    path.eb(intersectNode);

    int i=intersectNode;
    while(i != s){
        path.eb(s_parent[i]);
        i=s_parent[i];
    }

    reverse(all(path));

    i=intersectNode;
    while(i != t){
        path.eb(t_parent[i]);
        i=t_parent[i];
    }

    cout << "****PATH****\n";
    cout << path << '\n';
}
int biDirectionalSearch(int s, int t){
    bool s_vis[100], t_vis[100];
    int s_parent[100], t_parent[100];

    queue<int> s_q, t_q;
    int intersectNode=-1;

    fill(s_parent, s_parent+100, false);
    fill(t_parent, t_parent+100, false);

    s_q.emplace(s);
    t_q.emplace(t);
    s_parent[s]=-1;
    t_parent[t]=-1;
    s_vis[s]=true;
    t_vis[t]=true;

    while(!s_q.empty() && !t_q.empty()){
        BFS(s_q, s_vis, s_parent);
        BFS(t_q, t_vis, t_parent);

        intersectNode = findIntersectingNode(s_vis, t_vis);
        if(~intersectNode){
            cout << "Path exists between " << s << " and " << t << "\n";
            cout << "Intersection at: " << intersectNode << "\n";

            printPath(s_parent, t_parent, s, t, intersectNode);
            exit(0);
        }
    }
    return -1;
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

  cout << (biDirectionalSearch(s, t) == -1 ? "Path doesn't exists" : "") << '\n';
  return 0;
}
