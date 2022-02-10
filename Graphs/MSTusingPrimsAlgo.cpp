#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>key(V+1,INT_MAX), parent(V+1,-1);
        vector<bool>mstSet(V+1,false);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
        p.push({0,0});
        
        key[0]=1, parent[0]=-1;
        
        while(!p.empty()){
            int frt=p.top().second;
            p.pop();
            
            mstSet[frt]=true;
            
            for(auto it:adj[frt]){
                int v=it[0], weight=it[1];
                if(mstSet[v]==false and key[v] > weight){
                    parent[v]=frt;
                    key[v]=weight;
                    p.push({key[v],v});
                }
            }
        }
        
        int ansWeight=0;
        for(int i=1;i<=V;i++){
            ansWeight += (key[i]==INT_MAX)?0:key[i];
        }
        return ansWeight;
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
