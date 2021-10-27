#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int minNum = prices[0];
        int profit = INT_MIN;
        for(int i=1;i<prices.size();i++){
                profit = max(profit,prices[i]-minNum);
                minNum = min(minNum,prices[i]);
        }
        return (profit<=0)?0:profit;
    }

int main(){

  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;

    vector<int> prices;

    int num;  
    for(int i=0;i<n;i++){
      cin>>num;
      prices.push_back(prices[i]);
    }

    cout<<"The Best profit obtained will be "<<maxProfit(prices)<<endl;
  }

  return 0;
}