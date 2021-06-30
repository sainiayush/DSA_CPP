 vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n=arr.size();
        vector<pair<int,int>>sorted;
        
        for(int i=0;i<n;i++)
            sorted.push_back(make_pair(arr[i],i));
        
        sort(sorted.begin(),sorted.end(),[](pair<int,int>a, pair<int,int>b){
            return a.first<b.first;
        });
        
        vector<int>ans(n);
        
        int rank=1;
        for(int j=0;j<n;j++){
            if(j!=0 && sorted[j].first==sorted[j-1].first){
                ans[sorted[j].second]=rank-1;
            } else{
                ans[sorted[j].second]=rank;
                rank++;
            }
        }
        return ans;
        
        
    }
