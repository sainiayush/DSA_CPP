class Solution {
public:
    // Using DFS
    bool dfsCheck(int src, vector<vector<int>>& graph, int* color){
        
        if(color[src]==-1)
        color[src] = 1;
        
        for(auto it: graph[src]){
            if(color[it]==-1){
                color[it] = 1-color[src];
                if(!dfsCheck(it,graph,color)) return false;
            } else if(color[it]==color[src]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int color[n];
        memset(color, -1, sizeof color);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfsCheck(i, graph, color)) return false;
            }
        }
        return true;
    }
};
