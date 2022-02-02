#include <bits/stdc++.h>
using namespace std;

vector<int>preprocess(vector<int>& nums, int len){
    vector<int>sq(len,INT_MAX);
    for(int i = 0; i<nums.size(); i++){
        int sqrtidx = i/len;
        sq[sqrtidx] = min(sq[sqrtidx],nums[i]);
    }
    return sq;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int>nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    int len = (int)ceil(sqrt(n));
    vector<int>sq = preprocess(nums,len);
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int ans = INT_MAX;
        while(l<=r){
            if(l%len == 0 and l+len-1 <= r){
                ans = min(sq[l/len],ans);
                l += len;
            }else{
                ans = min(ans,nums[l]);
                l++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}