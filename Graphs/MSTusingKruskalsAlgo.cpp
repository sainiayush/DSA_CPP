#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	vector<int>parent,rank;
	int findPar(int u){
	    if(parent[u]==-1) return u;
	    return parent[u]=findPar(parent[u]);
	}
	void combine(int u,int v){
	    u=findPar(u), v=findPar(v);
	    if(rank[u]<rank[v]){
	        parent[u]=v;
	    }else if(rank[u]>rank[v]){
	        parent[v]=u;
	    }else{
	        parent[v]=u;
	        rank[u]++;
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        parent.assign(V+1,-1);
        rank.assign(V+1,0);
        
        vector<array<int,3>>edges;
        
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                edges.push_back({x[1],i,x[0]});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int ans=0;
        
        for(auto x: edges){
            if(findPar(x[1])!=findPar(x[2])) combine(x[1],x[2]), ans += x[0];
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
