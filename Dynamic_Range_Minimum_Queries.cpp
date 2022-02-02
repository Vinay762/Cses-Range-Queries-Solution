#include <bits/stdc++.h>
using namespace std;

long MAX = 1e9+7;

vector<long>preprocess(vector<long>& nums, int len){
    vector<long>sq(len,MAX);
    for(int i = 0; i<nums.size(); i++){
        int sqrtidx = i/len;
        sq[sqrtidx] = min(sq[sqrtidx], nums[i]);
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

    while(q-->0){
        int t;
        cin>>t;
        if(t == 1){
            int idx,val;
            cin>>idx>>val;
            idx--;
            nums[idx] = val;
            int sp = idx-idx%len;
            sq[sp/len] = MAX;
            for(int i = sp; i<sp+len; i++){
                sq[i/len] = min(sq[i/len],nums[i]);
            }
        }else{
            int l,r;
            cin>>l>>r;
            l--, r--;
            long ans = MAX;
            while(l<=r){
                if(l%len == 0 and l+len-1 <= r){
                    ans = min(ans,sq[l/len]);
                    l += len;
                }else{
                    ans = min(ans,nums[l]);
                    l++;
                }
            }
            cout<<ans<<"\n";
        }
    }

    return 0;
}