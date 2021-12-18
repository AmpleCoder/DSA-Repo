/*
simle and sweet dfs
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

int n,m;
vi adj[1001];

void dfs_util(int src,vector<bool> &vis)
{
    vis[src]=true;
    cout<<src<<" ";
    
    for(int &nb:adj[src])
    {
        if(!vis[nb])
        {
            dfs_util(nb,vis);
        }
    }
}

void dfs()
{
    vector<bool> vis(n+1,false);
    int i;

    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs_util(i,vis);
            cout<<'\n';
        }
    }
}

void solve()
{
    cin>>n>>m;
    int i,u,v;
    
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }    
    
    dfs();
}

int main()
{
    FIO;
    solve();
}
