#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

vector<lli>lazy;
vector<lli>arr;

void build(lli node, lli start, lli end){
    if(start == end){
        lazy[node] = arr[start];
    }else{
        lli mid = (start + end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        lazy[node] = 0;
    }
}

void update(lli node, lli start, lli end, lli l, lli r, lli val){
    if(end < l || start > r)return;

    if(start == end){
        lazy[node] += val;
    }else if(start >= l && end <= r){
        lazy[node] += val;
    }else{
        lli mid = (start + end)/2;
        update(node*2,start,mid,l,r,val);
        update(node*2+1,mid+1,end,l,r,val);
    }

}

void propagate(int node, int start, int end){
    if(start == end)return;
    int left = 2*node;
    int right = 2*node+1;
    lazy[left] += lazy[node];
    lazy[right] += lazy[node];
    lazy[node] = 0;
}

lli query(int node, int start, int end, int idx){
    propagate(node,start,end);
    if(start == end){
        return lazy[node];
    }else{
        lli mid = (start + end)/2;
        if(start <= idx && idx <= mid){
            return query(node*2,start,mid,idx);
        }else{
            return query(node*2+1,mid+1,end,idx);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli n,q;
    cin>>n>>q;
    arr.resize(n);
    lazy.resize(4*n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q-->0){
        lli t;
        cin>>t;
        if(t == 2){
            lli idx;
            cin>>idx;
            idx--;
            lli ans = query(1,0,n-1,idx);
            cout<<ans<<"\n";
        }else if(t == 1){
            lli l, r, val;
            cin>>l>>r>>val;
            l--,r--;
            update(1,0,n-1,l,r,val);
        }
    }
}