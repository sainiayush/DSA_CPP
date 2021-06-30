 vector<vector<int>> threeSum(vector<int>& num,int s) {
        vector<vector<int>>res;
        
        std::sort(num.begin(),num.end());
        
        for(int i=0;i<num.size();i++){
            int front = i+1, back=num.size()-1,target=sum-num[i];
            
            while(front < back){
                int sum = num[front]+num[back];
                
                if(sum+target<s) front++;
                
                else if (sum+target>s) back--;
                
                else{
                    vector<int>triplet = {num[i],num[front],num[back]};
                    res.push_back(triplet);
                    
                    while(front<back && num[front]==triplet[1]) front++;
                    while(front<back && num[back]==triplet[2]) back--;
                        
                }
            }
            while(i+1<num.size() && num[i]==num[i+1]) i++;
        }
        return res;
    }
