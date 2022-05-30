#include<vector>
int longestIncreasingSubsequence(int arr[], int n){
    // Write Your Code here
    vector<int>temp;
    temp.emplace_back(arr[0]);
    int len{1};
    
    for(int i=1;i<n;i++){
        if(temp.back() < arr[i]) temp.emplace_back(arr[i]), len++;
        else{ 
            int ind=lower_bound(temp.begin(), temp.end(),arr[i]) - temp.begin();
            temp[ind]=arr[i];
        }
    }
    return len;
}
