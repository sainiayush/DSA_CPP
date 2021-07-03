vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        
        int n=matrix.size(), m=matrix[0].size();
        int top=0, bottom=n-1, left=0, right=m-1;
        
        int d=0;
        
        while((top<=bottom) && (left<=right)){
            if(d==0){
                for(int i=left;i<=right;i++)
                    res.push_back(matrix[top][i]);
                d=1;
                top++;
            } else if(d==1){
                for(int i=top;i<=bottom;i++)
                    res.push_back(matrix[i][right]);
                right--;
                d=2;
            } else if(d==2){
                for(int i=right;i>=left;i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
                d=3;
            } else if(d==3){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
                d=0;
            }
        }
        return res;
    }
