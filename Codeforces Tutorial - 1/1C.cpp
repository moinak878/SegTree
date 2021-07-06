//Step 1 - Prob C : calculate min and number of minimums in the segment 

#include<bits/stdc++.h>
#define ll long long
#define INF 1000000007
using namespace std;
#define mp make_pair
vector< pair<ll,ll> > tree;

pair<ll,ll> f(ll node , ll left , ll right , ll l , ll r , ll v ){
    //cout << "#i am in node : " << node << ", left :" << left << " ,right : " << right << endl;
    if (l <= left && r >= right)
    {
        if(v!=-1)
            {
                tree[node].first= v;
                tree[node].second = 1;

            }
            return tree[node];
    }
    if(r<left || right<l)
        return mp(INF,0);
    ll next = left + (right - left) / 2;
    pair<ll, ll> lc = f(2 * node, left, next, l, r, v);
    pair<ll, ll> rc = f(2 * node + 1, next + 1, right, l, r, v);
    ll sum = min(lc.first, rc.first);
    ll cnt = 0;
    if(lc.first==rc.first)
        cnt = lc.second + rc.second;
    else if (lc.first < rc.first)
        cnt = lc.second;
    else
        cnt = rc.second;
    
    tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
    if(tree[2 * node].first==tree[2 * node + 1].first)
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    else if (tree[2 * node].first < tree[2 * node + 1].first)
        tree[node].second = tree[2 * node].second;
    else 
        tree[node].second = tree[2 * node+1].second;
    return mp(sum, cnt);
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while(__builtin_popcount(n)!=1)
            {
                a.push_back(INF);
                n++;
            }
        
    tree.resize(2 * n);
    for (int i = 0; i < n;i++) 
        {
            tree[n + i] =mp(a[i],1);
        }
    for (int i = n - 1; i >= 1;i--)
        {
            tree[i].first = min(tree[2 * i].first , tree[2 * i + 1].first);
            if(tree[2 * i].first== tree[2 * i + 1].first)
                tree[i].second = tree[2 * i].second + tree[2 * i + 1].second;
            else
                {
                    if(tree[2*i].first<tree[2*i+1].first)
                        tree[i].second = tree[2 * i].second;
                    else
                        tree[i].second = tree[2 * i+1].second;
                }
        }
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
            pair<ll, ll> ans = f(1, 0, n - 1, l, r, -1);
            cout << ans.first << " " << ans.second << "\n";
        }
        }
    return 0;
}

