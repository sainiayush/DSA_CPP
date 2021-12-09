void dfsHelper(vector<int>adj [], unordered_map<int,bool>& mp, vector<int>&ans, int i){
        if (mp.find(i)==mp.end()){
            mp[i] = true;
            ans.emplace_back(i);
            for(int it: adj[i]){
                if(mp.find(it)==mp.end()) dfsHelper(adj, mp, ans, it);
            }
        }
        return ;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool>mp;
        vector<int>ans;
        dfsHelper(adj, mp, ans, 0);
        mp.clear();
        return ans;
    }
