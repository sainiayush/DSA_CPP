#include<bits/stdc++.h>
using namespace std;

//BIT INDEXED TREE
class fenwick{
  private: 
  vector<int> _nums, bit;

  public:
  fenwick(vector<int>& nums) : _nums(nums) {
    bit.resize(nums.size()+1);

    for(int i=0; i<nums.size();i++){
      addVal(nums[i], i);
    }
  }
  private:
  int lower_bit(int i){
    return i&-i;
  }

  int query(int ind){
    int s{};
    ind++;
    while(ind){
      s += bit[ind];
      ind -= lower_bit(ind);
    }
    return s;
  }
  private:
  void addVal(int val,int ind){
    ind++;
    while(ind < bit.size()){
      bit[ind] += val;
      ind += lower_bit(ind);
    }
  }

  public:
  void update(int ind, int val){
    if(_nums[ind]!=val){
      addVal(val-_nums[ind],ind);
    }
  }

  int preSum(int l,int r){
    return query(r)-query(l);
  }
};

#define vi vector<int>
#define each(x,a) for(auto &x: a) cin>>x;
#define w(tt) int tt; cin>>tt; while(tt--)


int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    w(tt){
      int n;
      cin>>n;

      vi nums(n);
      each(x, nums);

      int q;
      cin>>q;

      fenwick tree(nums);

      while(q--){
        int qNum;
        cin>>qNum;

        if(!qNum){
          int ind, val;
          cin>> ind >> val;
          tree.update(ind, val);
        }

        else if(qNum==1){
          int l,r;
          cin>>l>>r;

          cout<<tree.preSum(l,r);
        }
        cout<<'\n';
      }
    }
    return 0;
}
