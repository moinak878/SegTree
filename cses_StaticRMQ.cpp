#include<bits/stdc++.h>
#define ll long long
#define lc (node<<1)
#define rc (node<<1)|1
using namespace std;
vector<ll> tree;
ll INF = 1e9 + 7;
ll f(int node, int lo, int hi, int a, int b)
{
    if(a<=lo && hi<=b)
        return tree[node];
    if(hi<a || lo>b)
        return INF;
    int l = (lo + hi) / 2;
    return min(f(lc, lo, l, a, b), f(rc, l + 1, hi, a, b));
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
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        cout << f(1, 0, n - 1, a, b) << "\n";
    }
    return 0;
}