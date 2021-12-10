vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>auxQ;
	    
	    vector<int> topoSortVector;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) auxQ.push(i);
	    }
	    
	    while(!auxQ.empty()){
	        int Node = auxQ.front();
	        auxQ.pop();
	        topoSortVector.push_back(Node);
	        
	        for(auto it: adj[Node]){
	            indegree[it]--;
	            
	            if(indegree[it]==0) auxQ.push(it);
	        }
	    }
	    return topoSortVector;
	}
