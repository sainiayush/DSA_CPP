int getMinDiff(int arr[], int n, int k) {
        vector<pair<int,int>>v;
        vector<int>vis(n);
        
        for(int i=0;i<n;i++){
            if(arr[i]-k>=0)
            v.push_back({arr[i]-k,i});
            
            v.push_back({arr[i]+k,i});
        }
        sort(v.begin(),v.end());
        
        int el=0,right=0,left=0;
        
        while(el<n && right<v.size()){
            if(vis[v[right].second]==0){
            el++;
            }
            vis[v[right].second]++;
            right++;
        }
        int ans=v[right-1].first-v[left].first;
        
        while(right < v.size()){
            if(vis[v[left].second]==1)
            el--;
            vis[v[left].second]--;
            left++;
            
            
            while(right<v.size() && el<n){
                if(vis[v[right].second]==0)
                el++;
                vis[v[right].second]++;
                right++;
            }
            if(el==n)
            ans=min(ans,v[right-1].first-v[left].first);
            
            else
            break;
        }
        return ans;
        
    }
