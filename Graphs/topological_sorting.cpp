/*
topological sorting is an ordering of the nodes of the graphs in such a way that 
if there is an edge from i->j then in the ordering i must appear before j
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
vector<vector<int>> adj;

//method i) via dfs (here can we use deque in place of vector to push our answer yes but pushing in front of deque 
//will cost us O(n) time complexity(do confirm) hence it's costlt)
bool dfs_for_topo(int i,vi &vis,vi &ans)
{
    vis[i]=1;

    for(int j:adj[i])
    {
        if(vis[j]==0)
        {
            bool possible = dfs_for_topo(j,vis);
            if(possible == 0)
            {
                return 0;
            }
        }

        //back edge
        else if(vis[j]==1)
        {
            return 0;
        }
    }

    //ans here stores the topo sort in reverse order
    //think why we can't write this line in line no 28?(i know it take graph :- {{1,2},{3,2},{1,3}})
    ans.push_back(i);
    vis[i]=2;
    
    return 1;
}

vi topo_by_dfs()
{
    vi vis(n+1,0),ans;
    int i;

    bool possible = 1;

    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            possible &= dfs_for_topo(i,vis,ans);
        }
    }

    reverse(ans.begin(),ans.end());

    return (possible == 1?ans:vi{});
}

/*
method ii) topo sort by bfs
here the idea is we need to process all those nodes first whose indegree is 0
*/
vi topo_by_bfs()
{
    vi indegree(n+1,0);
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j:adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    vi ans;

    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        ans.push_back(curr);

        for(j:adj[curr])
        {
            indegree[j]--;
            if(indegree[j]==0)
            {
                q.push(j);
            }
        }
    }

    return (ans.size() < n ? vi{} : ans);
}


void solve()
{
    int u,v,i;
    cin>>n>>m;

    adj.resize(n+1);

    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
    }

    vi topoSort = topo_by_dfs();
}

int main()
{
    solve();
}

/*
practice problem 
1) https://codeforces.com/contest/1573/problem/C
2) https://codeforces.com/problemset/problem/1217/D
*/