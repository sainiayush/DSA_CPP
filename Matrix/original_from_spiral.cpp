void spiralOrder(vector<vector<int>>&res,vector<int>& matrix,int n,int m) {
        
      
        int top=0, bottom=n-1, left=0, right=m-1;
        
        int d=0;

        while((top<=bottom) and (left<=right)){
            if(d==0){
                for(int i=left;i<=right;i++)
                  res[top][i]=matrix[index++];
                d=1;
                top++;
            } else if(d==1){
                for(int i=top;i<=bottom;i++)
                    res[i][right]=matrix[index++];
                right--;
                d=2;
            } else if(d==2){
                for(int i=right;i>=left;i--)
                    res[bottom][i]=matrix[index++];
                bottom--;
                d=3;
            } else if(d==3){
                for(int i=bottom;i>=top;i--)
                    res[i][left]=matrix[index++];
                left++;
                d=0;
            }
        }
        return res;
    }
