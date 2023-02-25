int reachArrayEnd(vector<int>& arr){
    int n=len(arr);
    vector<int> digit[10];
    for(int i=1; i<n; ++i)
        digit[arr[i]].emplace_back(i);

    vector<bool> vis(n);
    vector<int> dist(n);

    vis[0]=true;
    queue<int> q{{0}};

    while(!q.empty()){
        int idx = q.front();
        q.pop();

        if(idx == n-1) break;

        int d = arr[idx];

        for(int v: digit[d]){
            if(!vis[v]){
                vis[v]=true;
                q.emplace(v);
                dist[v]=dist[idx]+1;
            }
        }

        digit[d].clear();

        if(idx-1 >= 0 && !vis[idx-1]){
            q.emplace(idx-1);
            vis[idx-1]=true;
            dist[idx-1]=dist[idx]+1;
        }
        if(idx+1 < n && !vis[idx+1]){
            q.emplace(idx+1);
            vis[idx+1]=true;
            dist[idx+1]=dist[idx]+1;
        }
    }

    return dist[n-1];
}
