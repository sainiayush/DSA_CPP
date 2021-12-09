class Solution {
public:
    bool bfsCheck(int src, vector<vector<int>>& graph, int* color){
        queue<int>q;
        q.push(src);
        color[src] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int it: graph[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it] = 1-color[node];
                } else if(color[it] == color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int color[n];
        memset(color, -1, sizeof color);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfsCheck(i, graph, color)) return false;
            }
        }
        return true;
    }
};
