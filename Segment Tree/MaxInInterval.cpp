#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class segment_tree{
  vector<int> _nums, tree;
  int size;

  public:
  inline segment_tree(vector<int>& nums){
    size = nums.size();
    _nums.resize(size);
    _nums=nums;
    int k=ceil(log2(nums.size()));
    int max_size = 2*pow(2,k)-1;
    tree.resize(max_size);
    build(1,0,size-1);
  }

  inline int query(int l,int r){
    return query(1,0,size-1,l,r);
  }

  inline void update(int pos,int val){
    update(1,0,size-1,pos,val);
  }

  private:
  inline  void build(int node, int start, int end){
    if(start > end)
      return;
    if(start==end){
      tree[node]=_nums[start];
      return;
    }
    int mid = start + ((end-start)>>1);

    int left = 2*node;
    int right = 2*node+1;
    build(left, start, mid);
    build(right, mid+1, end);

    tree[node] = max(tree[left], tree[right]);
  }
  inline void update(int node,int start,int end,int pos,int val){
    if(start > end)
      return;

    if(start==end){
      tree[node]=val;
      _nums[start]=val;
      return;
    }

    int mid = start + ((end - start)>>1);

    if(pos >= start and pos <= mid)
      update(2*node, start, mid, pos, val);
    else
      update(2 * node + 1, mid+1, end, pos, val);
    
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }

  inline int query(int node, int start, int end,int l,int r){
    if(l > end || r < start || l>r) 
      return INT_MIN/1000;
    
    if(l <= start and r >= end)
      return tree[node];

    int mid = start + ((end-start)>>1);

    int left = query(2*node, start, mid, l, r);
    int right = query(2*node+1, mid+1, end, l, r);

    return max(left, right);
  }
};
void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &x: arr)  
      cin >> x;

    segment_tree s(arr);

    int q;
    cin>>q;

    while(q--){
      int l,r;
      cin >> l >> r;

      cout<<s.query(l,r)<<'\n';
    }
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
