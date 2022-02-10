class Solution {
    void dfsTraversal(int node,int parent,vector<int>& isArticulation, vector<bool>& vis,vector<int>&tin, vector<int>& low,int& timer,vector<int>adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        int child(0);
        
        for(auto it: adj[node]){
            if(it==parent) continue;
            
            if(!vis[it]){
                dfsTraversal(it,node,isArticulation,vis,tin,low,timer,adj);
                child++;
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1) isArticulation[node]=1;
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 and parent==-1) isArticulation[node]=1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>isArticulation(V,0), tin(V), low(V);
        vector<bool>vis(V,false);
        int timer(0);
        
        dfsTraversal(0,-1,isArticulation,vis,tin,low,timer,adj);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(isArticulation[i]) ans.emplace_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};
