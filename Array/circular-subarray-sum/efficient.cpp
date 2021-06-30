int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        
        int temp_max_sum=0, temp_min_sum=0, max_sum=INT_MIN, min_sum=INT_MAX;
        
        int array_sum=0;
        
        for(int i=0;i<n;i++){
            array_sum+=nums[i];
            
            temp_max_sum+=nums[i];
            max_sum=max(max_sum,temp_max_sum);
            temp_max_sum= (temp_max_sum<0)?0:temp_max_sum;
            
            temp_min_sum+=nums[i];
            min_sum=min(min_sum,temp_min_sum);
            temp_min_sum = (temp_min_sum>0)?0:temp_min_sum;
        }
        if(array_sum == min_sum)
            return max_sum;
        return max(max_sum,(array_sum-min_sum));
    }
