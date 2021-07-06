//AC : stuck for a long time cuz was not updating a[i] 🤦🏻‍♂️
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> tree;

//f(1,0,n-1,1-a[i])
void f(ll node, ll left, ll right, ll l, ll r, ll v)
{
    if (l <= left && r >= right)
    {
        tree[node] = v;
        return;
    }
    if (r < left || right < l)
        return;
    ll next = left + (right - left) / 2;
    f(2 * node, left, next, l, r, v);
    f(2 * node + 1, next + 1, right, l, r, v);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

//f(1,0,n-1,k)
ll f1(int node, int left, int right, int k)
{
    // cout <<"node : "<<node<<" with left : " << left << " , right : " << right << "\n";
    if (left == right)
        return left;
    int mid = (left + right) / 2;
    int sl = tree[2 * node];
    //cout << " sl : " << tree[2 * node]<<"\n";
    if (k < sl)
        return f1(2 * node, left, mid, k);
    else
        return f1(2 * node + 1, mid + 1, right, k - sl);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    while (__builtin_popcount(n) != 1)
    {
        a.push_back(0);
        n++;
    }
    tree.resize(2 * n);
    for (int i = 0; i < n; i++)
    {
        tree[n + i] = a[i];
    }
    for (int i = n - 1; i >= 1; i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            cin >> i;
            a[i] = 1 - a[i];
            f(1, 0, n - 1, i, i, a[i]);
        }
        else
        {
            int k;
            cin >> k;
            cout << f1(1, 0, n - 1, k);
            cout << "\n";
        }
    }
}