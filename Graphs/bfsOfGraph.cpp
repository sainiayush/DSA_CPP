vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V+1,false);
        
        vector<int>result;
        list<int>q;
        q.push_back(0);
        visited[0] = true;
        
        while(!q.empty()){
            int front = q.front();
            result.emplace_back(front);
            q.pop_front();
            visited[front] = true;
            
            for(auto i: adj[front]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push_back(i);
                }
            }
        }
        return result;
    }
