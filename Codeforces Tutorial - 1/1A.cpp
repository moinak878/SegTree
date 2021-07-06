#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> tree;

ll f(ll node , ll left , ll right , ll l , ll r , ll v ){
    if(l<=left && r>=right){
        if(v!=-1)
            tree[node] = v;
        return tree[node];
    }
    if(r<left || right<l)
        return 0;
    ll next = left + (right - left) / 2;
    ll sum = f(2 * node, left, next, l, r, v) + f(2 * node + 1, next + 1, right, l, r, v);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return sum;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while(__builtin_popcount(n)!=1)
            n++;
        
    tree.resize(2 * n);
    for (int i = 0; i < (int)a.size();i++) //a.size --> be careful easily missed results in silly runtime error 
        tree[n + i] = a[i];
    for (int i = n - 1; i >= 1;i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, v;
            cin >> i >> v;
            f(1, 0, n - 1, i, i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            r--;
            cout<<f(1, 0, n - 1, l, r,-1)<<"\n";
        }
        }
    return 0;
}
