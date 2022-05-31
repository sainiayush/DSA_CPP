#include<stack>
int maxHistogramArea(vector<int>& heights){
    int n=heights.size();
    stack<int>stk;
    int maxArea{};
    
    for(int i=0;i<=n;i++){
        while(!stk.empty() && (i==n || (heights[stk.top()]>=heights[i]))){
            int height=heights[stk.top()];
            stk.pop();
            
            int width;
            if(stk.empty()) width=i;
            else width=i-stk.top()-1;
            
            maxArea=max(maxArea, height*width);
        }
        stk.push(i);
    }
    return maxArea;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
    
    int maxArea{};
    vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1) dp[j]++;
            else dp[j]=0;
        }
        maxArea=max(maxArea,maxHistogramArea(dp));
    }
    return maxArea;
}
