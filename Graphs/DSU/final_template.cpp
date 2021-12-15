/*
here we do union by rank
we can do ranking on the basis of either size height of the component

and path compression(it means while finding the root for a particular ele we will set the parent of all ele which will lie in the path
from given ele to root equal to root of the component)

here we'll be applying both these optimizations together

here the amortized complexity for both the operations Union and find comes out to be 
alpha(n) -> inverse ackerman function
alpha(n) <= 4 for all n <= 10**100
inverse ackerman function grows as slow as log*n
log*(2**65536) ->
log(2**65536) -> log(65536) -> log(2**16) -> log(16) ->log(4) ->log(2) -> log(1)(0 stop here)
total steps = log*(2**65536) = 6 
hence our union and find complexity is going to be nearly O(1)

this is so beautiful template that here we can figure out the gcd for a component, number of total component
just by augmenting things in the class 
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
    vi size;
public:
    union_find(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int root(int i)
    {
        if(i == parent[i])
            return i;

        return parent[i] = root(parent[parent[i]]);//to do some small optimization
    }

    int find(int i,int j)
    {
        return root(i) == root(j);
    }    

    void un(int i,int j)
    {
        int u=root(i);
        int v=root(j);

        if(u==v)    return;

        if(size[u]>size[v]) 
            swap(u,v);

        parent[u]=v;
        size[v]+=size[u];
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