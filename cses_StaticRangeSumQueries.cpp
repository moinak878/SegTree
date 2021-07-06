#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> tree;

ll sum(int node , int a , int b , int node_left , int node_right){
    //cout <<" -->sum (" << node << "," << a<<","<<b<<","<<node_left<<","<<node_right<<")" << endl;
    if(a<=node_left && node_right<=b)
            return tree[node];
    if(node_right<a || node_left>b)
        return 0;
    int left_low = (node_left + node_right) / 2;
    return sum(2*node, a, b, node_left, left_low) + sum(2*node+1, a, b, left_low + 1, node_right);
}


int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n;i++)
        cin >> x[i];
    //padding elements in x to make it power of 2 
    while(__builtin_popcount(n)!=1){
        x.push_back(0);
        n++;
    }
    tree.resize(2*n); //2n elements -> 0-(2n-1)

    //building the tree first by filling up leaves (n=8 0...7 ->array ... tree 1...15)
    
    //filling 8 through 15
    for (int i = 0; i < n;i++){ 
        tree[n + i] = x[i];
    }
    //filling 1 through 7
    for (int i = n - 1; i >= 1;i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << sum(1, a, b, 0, n - 1) << "\n";
    }
    return 0;
}