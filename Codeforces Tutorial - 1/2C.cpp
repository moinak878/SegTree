#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> tree;

void update(ll index, ll v){
    tree[index] = v;
    for (ll i = index/2; i >= 1; i /= 2)
        tree[i] = max(tree[2 * i] ,tree[2 * i + 1]);
}

ll  f1(ll i , ll left , ll right , ll x){
    //cout << "in node " << i << " with value = " << tree[i] << "\n";
    if(tree[i]<x)
        return -1;
    if (left == right)
        return left;
    ll mid = (left + right) / 2;
    ll res = f1(2 * i, left, mid, x);
    if (res == -1 )
        res =  f1(2 * i + 1, mid + 1, right, x);
    return res;
}
int main()
{
    ll n, m;
    cin >> n>> m;
    vector<ll> a(n);
    for (ll i = 0; i < n;i++ )
        cin >> a[i];
    while(__builtin_popcount(n)!=1){
            a.push_back(INT_MIN);
            n++;
        }
    tree.resize(2 * n);
    for (ll i = 0; i < n; i++)
        tree[n + i] = a[i];
    for (ll i = n - 1; i >= 1;i--)
        tree[i] = max(tree[2 * i] , tree[2 * i + 1]);
    while(m--){
        int type;
        cin >> type;
        if(type==1){
            ll i;
            ll v;
            cin >> i >> v;
            update(n + i, v);
        }
        else{
            ll x;
            cin >> x;
            cout<<f1(1,0,n-1,x)<<"\n";
        }
    }
    return 0;
}
