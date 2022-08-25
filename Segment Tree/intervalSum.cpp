#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class segment_tree{
  vector<int> _nums, tree;
  int size;

  public:
  segment_tree(vector<int>& nums){
    size = nums.size();
    _nums.resize(size);
    _nums = nums;
    int k = ceil(log2(size));
    int max_size = 2*pow(2,k)-1;
    tree.resize(max_size);
    build(1,0,size-1);
  }

  void update(int pos,int val){
    update(1,0,size-1,pos,val);
  }

  int query(int l,int r){
    return query(1,0,size-1,l,r);
  }

  private:
  inline int query(int node, int start, int end,int l,int r){
    if(l>end || r<start || l>r)
      return 0;
    
    if(start <=l and r >= end)  
      return tree[node];

    int mid = start + ((end-start)>>1);

    int left = query(2*node, start, mid, l, r);
    int right = query(2*node, mid+1, end, l, r);


    return left + right;
  }
  inline void build(int node, int start, int end){
    if(start > end) 
      return;
    if(start==end){
      tree[node]=_nums[start];
      return;
    }

    int mid = start + ((end-start)>>1);

    int left = 2*node;
    int right = 2*node + 1;

    build(left, start, mid);
    build(right, mid+1, end);

    tree[node] = tree[left] + tree[right];
  }

  inline void update(int node, int start, int end, int pos, int val){
    if(start > end)
      return;

    if(start==end){
      tree[node]=val;
      _nums[start]=val;
      return;
    }

    int mid = start + ((end-start)>>1);

    int left = 2*node;
    int right = 2*node + 1;

    if(pos >= start and pos <= mid)
      update(left, start, mid, pos, val);

    else
      update(right, mid+1, end, pos, val);

    tree[node] = tree[left] + tree[right];
  }
};
void solve() {
    int n;
    cin>>n;

    vector<int> vec(n);

    for(int &x: vec)  
      cin>>x;

    segment_tree st(vec);

    int q;
    cin>>q;

    //1. Update
    //2. Sum of Interval [l....r]

    while(q--){
      int queryType;
      cin >> queryType;

      if(queryType==1){
        int pos, val;
        cin>>pos>>val;

        st.update(pos,val);
      }
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
