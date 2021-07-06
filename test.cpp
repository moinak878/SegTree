// #include<bits/stdc++.h>
// using namespace std;
// int add(int a,int b){
//     cout << "I am here in a,b = " << a << "," << b << endl;
//     return a + b;
// }
// int main(){
//     int a, b;
//     add(5, 7);
//     cout<<"The sum is : "<<add(1, 2);
// }

//testing if i can implement segment tree sleepily 
#include<bits/stdc++.h>
using namespace std;
//implementing segment tree
vector<int> tree;
int f(int node , int a , int b , int left , int right , int v){ //one func for both update and query
    if(a<=left && b>=right){
    if(v!=-1)
        tree[node] = v;
    return tree[node];
    }
    if(a>right || b<left)
        return 0;
    int l = (left + right) / 2;
    int sum = f(2 * node, a, b, left, l, v) + f(2 * node + 1, a, b, l + 1, right, v);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> x(n); //8 
    for (int i = 0; i < n;i++)
        cin >> x[i];
    //power of 2
    while(__builtin_popcount(n)!=1)
        n++;
    //build tree;
    tree.resize(2 * n); //16 ... use 1-15 
    for (int i = 0; i < n;i++){
        tree[n+i] = x[i];
    }
    for (int i = n - 1; i >= 1;i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];

}

//turns out i can .. had to look twice in the code while building the tree
// but thats because i am sleepy ...these assignments are killing me 



