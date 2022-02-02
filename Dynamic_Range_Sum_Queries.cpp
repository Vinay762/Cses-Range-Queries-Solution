#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> preprocess(vector<ll>nums, int len){
    vector<ll>sq(len,0);
    for(int i = 0; i<nums.size(); i++){
        int sqrtidx = i/len;
        sq[sqrtidx] += nums[i];
    }
    return sq;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<ll>nums(n);
    for(int i= 0; i<n; i++){
        cin>>nums[i];
    }
    int len = (int)ceil(sqrt(n));
    vector<ll>sq = preprocess(nums,len);
    while(q-->0){
        int t;
        cin>>t;
        if(t == 1){
            ll idx, val;
            cin>>idx>>val;
            idx--;
            ll change = val-nums[idx];
            sq[idx/len] += change;
            nums[idx] = val;
        }else{
           int l,r;
           cin>>l>>r;
           l--;
           r--;
           ll ans = 0;
           while(l<=r){
               if(l%len == 0 and l+len-1 <= r){
                   ans += sq[l/len];
                   l += len;
               }else{
                   ans += nums[l];
                   l++;
               }
           }  
           cout<<ans<<"\n";         
        } 
    }
    return 0;
}