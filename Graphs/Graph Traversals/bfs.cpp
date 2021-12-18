/*
here the profit of marking the unvisited neighbour at the time of explorations will give us the benifit that it can't be pushed in the queeu again
other wise it might happens that same node which is currently pushed in the queue might be neighbour of any other current node in the queue 
hence can be pushed again (example shown below like 3 is ngb of 1 and 2 as well)
6 8
1 3 
1 5 
1 2
2 3
3 5
3 4
3 6
4 6

this template is to start with only one node
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

void bfs_util(int src,vector<bool> &vis)
{
    int curr;
    vis[src]=1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int &nb:adj[curr])
        {
            if(!vis[nb])
            {
                vis[nb]=1;
                q.push(nb);
            }
        }
    }
}

void bfs()
{
    vector<bool> vis(n+1,false);
    int i;
    
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            bfs_util(i,vis);
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
    
    bfs();
}

int main()
{
    FIO;
    solve();
}
