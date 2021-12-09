bool isCyclic(vector<int>adj[], vector<bool>& vis, int& i){
        vis[i] = true;
        queue<pair<int,int>>q;
        q.push({i,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it,node});
                } else if(par != it) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V+1, false);
        for(int i=0;i<V;i++){
            if(!vis[i])
            if(isCyclic(adj, vis, i)) return true;
        }
        
        return false;
    }
