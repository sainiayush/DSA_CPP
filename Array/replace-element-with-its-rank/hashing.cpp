 vector<int> arrayRankTransform(vector<int>& arr) {
        
        set<int>s(arr.begin(),arr.end());
        unordered_map<int,int>m;
        
        for(auto el: s)
            m[el]=m.size()+1;
        
        vector<int>out;
        
        for(auto el: arr)
           out.push_back(m[el]);
        return out;
    }
