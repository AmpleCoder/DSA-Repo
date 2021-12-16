/*
initially we have n persons
each of them are friend with each other 
after each day given pair {i,j} breaks there friendship
and (a,b) forms the part of same club if there exist some sequence a,i1,i2,....ix,b such that 
(a,i1) (i1,i2)....(ix,b) are friends 

after each day we need to print the number of clubs left
assuming offline query
*/

/*
pretty simple approach 
we can first form components with all the pairs which are not present in the query set after that we can iterate from the back and 
do union of that pair and figure out the number of components we have  
*/

//problem link :- https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

//solution
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

class union_find
{
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

class Query{
public:
    string str;
    int a;
    int b;
};

void solve()
{
    int n,m,k,i,a,b,size;
    string str;
    cin>>n>>m>>k;
    union_find DSU(n+1);
    vector<Query> v;
    Query q;
    vector<string> ans;
    bool flag;
    
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
    }
       
    for(i=0;i<k;i++)
    {
        cin>>str>>a>>b;
        q.a=a,q.b=b,q.str=str;
        v.push_back(q);
    }
    
    for(i=k-1;i>=0;i--)
    {
        str=v[i].str,a=v[i].a,b=v[i].b;
        if(str=="ask")
        {
            flag=DSU.find(a,b);
            if(flag==1)
            {
                ans.push_back("YES");
            } 
            
            else
            {
                ans.push_back("NO");
            }
        }
        
        else
        {
            DSU.un(a,b);
        }
    }
    
    size=ans.size();
    
    for(i=size-1;i>=0;i--)
    {
        cout<<ans[i]<<endl;
    }
}

int main()
{
    FIO;
    solve();
}
