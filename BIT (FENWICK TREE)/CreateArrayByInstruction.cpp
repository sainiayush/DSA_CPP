#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


//Create Array by adding cost of min of greater and smaller elements than arr[i].....

void update(int x,vector<int>& fen){
  while(x < 10000001){
    fen[x]++;
    x += x&-x;
  }
}

int find(int x, vector<int>& fen){
  int cnt{};
  
  while(x){
    cnt += fen[x];
    x -= x&-x;
  }

  return cnt;
}
void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &x: arr)  
      cin>>x;

    vector<int> fen(10000001);
    
    int cost{};


    for(int i=0;i<n;++i){
      int smaller = find(arr[i]-1, fen);
      int larger = i-find(arr[i], fen);

      cost += min(smaller, larger);
      update(arr[i], fen);
    }

    cout<<cost<<'\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
