#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin>>n>>q;
    vector<ll>prefix(n+1,0);
    ll a;
    for(int i = 1; i<=n; i++){
        cin>>a;
        prefix[i] = prefix[i-1]+a;
    }
    while(q--){
        ll l, r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<"\n";
    }
    return 0;
}