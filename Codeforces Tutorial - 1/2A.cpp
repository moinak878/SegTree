//Segment with maximum sum -- for when DP becomes too slow :P
//AC solution -- both iterative and recursive 
#include<bits/stdc++.h>
#define ll long long 
#define mt make_tuple
#define lc (i<<1)
#define rc (i<<1)|1
#define INF 1000000007
using namespace std;
vector< tuple<ll,ll,ll,ll> >tree; // max,pref,suf,sum

// tuple<ll,ll,ll,ll> f(ll i , ll left , ll right , ll l , ll r , ll v ){
//     //cout << "#i am in node : " << node << ", left :" << left << " ,right : " << right << endl;
//     if (l <= left && r >= right)
//     {
//         if(v>0)
//             {
//                 get<0>(tree[i]) = v;
//                 get<1>(tree[i]) = v;
//                 get<2>(tree[i]) = v;
//                 get<3>(tree[i]) = v;
//             }
//         else{
//             get<0>(tree[i]) = 0;
//             get<1>(tree[i]) = 0;
//             get<2>(tree[i]) = 0;
//             get<3>(tree[i]) = v;
//         }
//             return tree[i];
//     }
    
//     if(r<left || right<l)
//         return mt(-INF,-INF,-INF,-INF);

//     ll next = left + (right - left) / 2;
//     tuple<ll,ll,ll,ll> left_ans = f(lc, left, next, l, r, v);
//     tuple<ll,ll,ll,ll> right_ans = f(rc, next + 1, right, l, r, v);
    
//     ll seg,pref,suf,sum;
//     seg = max(get<0>(left_ans), get<0>(right_ans)); 
//     seg = max(seg ,get<2>(left_ans) + get<1>(right_ans));
//     pref = max(get<1>(left_ans), get<3>(left_ans) + get<1>(right_ans));
//     suf = max(get<2>(right_ans), get<3>(right_ans) + get<2>(left_ans));
//     sum = get<3>(left_ans) + get<3>(right_ans);
    
//     get<0>(tree[i]) = max(get<0>(tree[lc]), get<0>(tree[rc])); 
//     get<0>(tree[i]) = max(get<0>(tree[i]) ,get<2>(tree[lc]) + get<1>(tree[rc]));
//     get<1>(tree[i]) = max(get<1>(tree[lc]), get<3>(tree[lc]) + get<1>(tree[rc]));
//     get<2>(tree[i]) = max(get<2>(tree[rc]), get<3>(tree[rc]) + get<2>(tree[lc]));
//     get<3>(tree[i]) = get<3>(tree[lc]) + get<3>(tree[rc]);
    
//     return mt(seg,pref,suf,sum);
// }

void iterative_update(ll n ,ll i, ll v){
    i=n+i;
    if(v>0){
                get<0>(tree[i])= v;
                get<1>(tree[i]) = v;
                get<2>(tree[i]) = v;
                get<3>(tree[i]) = v;
            }
    else{
            get<0>(tree[i])=0;
            get<1>(tree[i]) =0;
            get<2>(tree[i]) =0;
            get<3>(tree[i]) = v;
        }
    for(i=i/2;i>=1;i/=2){
        get<0>(tree[i]) = max(get<0>(tree[lc]), get<0>(tree[rc])); 
        get<0>(tree[i]) = max(get<0>(tree[i]) ,get<2>(tree[lc]) + get<1>(tree[rc]));
        get<1>(tree[i]) = max(get<1>(tree[lc]), get<3>(tree[lc]) + get<1>(tree[rc]));
        get<2>(tree[i]) = max(get<2>(tree[rc]), get<3>(tree[rc]) + get<2>(tree[lc]));
        get<3>(tree[i]) = get<3>(tree[lc]) + get<3>(tree[rc]);
    }

}


int main(){
    int n,m;
    cin >> n>>m;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    while(__builtin_popcount(n)!=1)
        {
            a.push_back(-INF);
            n++;
        }
    tree.resize(2 * n);
    for (int i = 0; i < n; i++)
        {
            if(a[i]>0){
                get<0> (tree[n + i]) = a[i];
                get<1> (tree[n + i]) = a[i];
                get<2> (tree[n + i]) = a[i];
                get<3> (tree[n + i]) = a[i];
            }
            else{
                get<0>(tree[n + i]) = 0;
                get<1>(tree[n + i]) = 0;
                get<2>(tree[n + i]) = 0;
                get<3>(tree[n + i]) = a[i];
            }
                }
    for (int i = n - 1; i >= 1;i--)
        {
            get<0>(tree[i]) = max(get<0>(tree[lc]), get<0>(tree[rc])); 
            get<0>(tree[i]) = max(get<0>(tree[i]) ,get<2>(tree[lc]) + get<1>(tree[rc]));
            get<1>(tree[i]) = max(get<1>(tree[lc]), get<3>(tree[lc]) + get<1>(tree[rc]));
            get<2>(tree[i]) = max(get<2>(tree[rc]), get<3>(tree[rc]) + get<2>(tree[lc]));
            get<3>(tree[i]) = get<3>(tree[lc]) + get<3>(tree[rc]);
        }
        cout << get<0>(tree[1]) << "\n";
        while (m--)
        {
            ll i, v;
            cin>>i>>v;
            // f(1, 0, n - 1, i, i, v);
            iterative_update(n,i,v);
            cout << get<0>(tree[1]) << "\n";
        }

        return 0;
}