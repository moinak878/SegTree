#include<bits/stdc++.h>
#define ll long long
#define lc (node<<1)
#define rc (node<<1)|1
using namespace std;
vector<ll> tree;
ll INF = 1e9 + 7;
ll f(int node, int lo, int hi, int a, int b,int v)
{
    if(a<=lo && hi<=b){
        if (v != -1)
            tree[node] = v;
        return tree[node];
    }
       
    if(hi<a || lo>b)
        return INF;
    int l = (lo + hi) / 2;
    int m = min(f(lc, lo, l, a, b,v), f(rc, l + 1, hi, a, b,v));
    tree[node] = min(tree[lc], tree[rc]);
    return m;
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> x(n);
    for (int i = 0; i < n;i++)
        cin >> x[i];
    while(__builtin_popcount(n)!=1){
        x.push_back(INF);
        n++;
    }
    tree.resize(2 * n);
    for (int i = 0; i < n; i++)
        tree[n + i] = x[i];
    for (int node = n - 1; node >= 1;node--)
        tree[node] = min(tree[lc], tree[rc]);
    while(q--){
        int type;
        cin >> type;
        if(type==2){
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            cout << f(1, 0, n - 1, a, b,-1) << "\n";
        }
        else {
            int k, u;
            cin >> k >> u;
            k--;
            f(1, 0, n - 1, k, k, u);
        }
    }
    return 0;
}