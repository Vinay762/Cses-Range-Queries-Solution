#include <bits/stdc++.h>
using namespace std;

vector<long> preprocess(vector<long>nums, int len){
    vector<long>sq(len,0);
    for(int i = 0; i<nums.size(); i++){
        int sqrtidx = i/len;
        sq[sqrtidx] = sq[sqrtidx]^nums[i];
    }
    return sq;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<long>nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    int len = (int)ceil(sqrt(n));
    vector<long>sq = preprocess(nums,len);

    while(q--){
        int l,r;
        cin>>l>>r;
        l--, r--;
        long ans = 0;
        while(l<=r){
            if(l%len == 0 and l+len-1 <= r){
                ans = ans^sq[l/len];
                l += len;
            }else{
                ans = ans^nums[l];
                l++;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}