bool cycleCheck(vector<int>adj[], int* vis, int* dfsVis, int Node){
        dfsVis[Node]=1;
        vis[Node]=1;
        
        for(auto it: adj[Node]){
            if(!vis[it]){
                if(cycleCheck(adj, vis, dfsVis, it)) return true;
            } else if(dfsVis[it]) return true;
        }
        
        dfsVis[Node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V], dfsVis[V];
        
        memset(vis,0,sizeof vis);
        memset(dfsVis,0,sizeof dfsVis);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleCheck(adj, vis, dfsVis, i)) return true;
            }
        }
        return false;
    }
