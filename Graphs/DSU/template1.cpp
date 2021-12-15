/*
worst case O(n) -> union operation and O(n) -> root/find
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define mod 1000000007
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define ff first
#define ss second

class union_find{
    vi parent;
public:
    union_find(int n)
    {
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int root(int i)
    {
        if(i==parent[i])
            return i;

        return root(parent[parent[i]]);//to do some small optimization
    }

    int find(int i,int j)
    {
        return root(i)==root(j);
    }    

    void un(int i,int j)
    {
        int u=root(i);
        int v=root(j);

        if(u==v)    return;

        parent[u]=v;
    }
};

int main()
{
    FIO;
    union_find dsu(5);
    cout<<dsu.find(1,2)<<endl;
    dsu.un(1,2);
    cout<<dsu.find(1,2)<<endl;
    dsu.un(1,3);
    cout<<dsu.find(2,3)<<endl;
}