#include<bits/stdc++.h>
#define ll long long 
using namespace std;
vector<ll> tree;
ll f(int node , int lo , int hi , int a , int b){
    if(lo>=a && hi<=b)
        return tree[node];
    if(lo>b || hi<a)
        return 0;
    int l = (lo + hi) / 2;
    return f(2 * node, lo, l, a, b) ^ f(2 * node + 1, l + 1, hi, a, b); 
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    while(__builtin_popcount(n)!=1)
        n++;
    tree.resize(2 * n); //fills in with zeroes

    //building the Xor seg-tree
    for (int i = 0; i < (int)a.size();i++)
        tree[n + i] = a[i];
    for (int i = n - 1; i >= 1;i--)
        tree[i] = tree[2 * i] ^ tree[2 * i + 1];
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << f(1, 0, n - 1, a, b)<<"\n";
    }
    return 0;
}