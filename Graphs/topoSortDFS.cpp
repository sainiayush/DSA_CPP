	void topoSortFind(vector<bool>& vis, stack<int>& st, vector<int>adj[], int Node){
	    vis[Node]=true;
	    
	    for(auto it: adj[Node]){
	        if(!vis[it]){
	            topoSortFind(vis, st, adj, it);
	        }
	    }
	    st.push(Node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>st;
	    
	    vector<bool>vis(V, false);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            topoSortFind(vis, st, adj, i);
	        }
	    }
	    vector<int>ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
