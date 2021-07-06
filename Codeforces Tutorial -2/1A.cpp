#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> tree;
ll f(ll i , ll lx , ll rx , ll left , ll right , ll v){
    if(lx>right || rx<left){
        return 0;
    }
    if(lx>=left && rx<=right){
        if(v==-1)
            return tree[i];
        tree[i] += v;
        return 0;
    }
    ll mid = (lx + rx )/ 2;
    ll ans = f(2 * i, lx, mid, left, right, v) + f(2 * i + 1, mid + 1, rx, left, right, v);
    return (tree[i] + ans);
}
int main()
{
    ll n, m;
    cin >> n >> m;
    while(__builtin_popcount(n)!=1)
        n++;
    tree.resize(2 * n);
    while(m--){
        ll type;
        cin >> type;
        if(type==1){
            ll l,r,v;
            cin>>l>>r>>v;
            r--;
            f(1, 0, n - 1, l, r, v);
        }
        else{
            ll i;
            cin >> i;
            cout << f(1, 0, n - 1, i, i, -1)<<"\n";
        }
    }
    return 0;
}
