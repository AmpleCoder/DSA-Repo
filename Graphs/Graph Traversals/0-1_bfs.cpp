/*
problem : https://www.codechef.com/problems/REVERSE
similar problem : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

when to use it :- when we're dealing with the weighted graph where we need to figure out min. dist etc in O(n+m) instead of O(nlogn)
where weights can only be of 2 types then use 01_bfs
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
#define inf (int)1e8
int n,m;
vector<vector<pii>> adj;
int dir[]={-1,0,1,0,-1,1,1,-1,-1};

class cell{
public:
    int x,y,d;
};

bool out(int x,int y)
{
    return (x<0 || x>=n || y<0 || y>=m);
}

void bfs_01(int src)
{
    vector<int> dist(n+1,inf);
    deque<int> q;
    dist[src]=0;
    q.push_front(src);
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop_front();
        for(auto &ngb:adj[curr])
        {
            int v=ngb.ff;
            int w=ngb.ss;
            if(dist[v]>dist[curr]+w)
            {
                dist[v]=dist[curr]+w;
                if(w==1)
                {
                    q.push_back(v);
                }
                
                else
                {
                    q.push_front(v);
                }
            }
        }
    }
    
    cout<<(dist[n]==inf?-1:dist[n]);
}

void solve()
{
    int u,v,i;
    cin>>n>>m;
    adj.resize(n+1);
    
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    
    bfs_01(1);
}

int main()
{
    solve();
}
