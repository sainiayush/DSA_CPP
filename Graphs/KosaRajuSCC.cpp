#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{   void findTopo(vector<int>adj[], stack<int>& stk,vector<bool>&vis,int node){
        vis[node]=true;
        for(auto it: adj[node]){
            if(!vis[it]){
                findTopo(adj,stk,vis,it);
            }
        }
        stk.push(node);
    }
    void revDfs(int node,vector<bool>& vis,vector<int>transposeGraph[]){
        vis[node]=true;
        for(auto it: transposeGraph[node]){
            if(!vis[it]){
                revDfs(it,vis,transposeGraph);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]){
        //code here
        stack<int>st;
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                findTopo(adj,st,vis,i);
            }
        }
        
        vector<int>transposeGraph[V];
        
        for(int i=0;i<V;i++){
            vis[i]=false;
            for(auto it: adj[i]){
                transposeGraph[it].push_back(i);
            }
        }
        
        int num(0);
        
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                num++;
                revDfs(node,vis,transposeGraph);
            }
        }
        return num;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
