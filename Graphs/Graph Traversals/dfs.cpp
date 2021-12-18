/*
simle and sweet dfs

application 
1) if we have to print the cycle / detect the cycle in the undirected graph using dfs how to do that?
    simple to observe if any of my neighbour is not my parent and it is already visited then cycle is present 
2) how to print cycle if present?
    it's good problem the moment we get to the ngb which is already visited and it's not currents parent then it is the point 
    which can lead us to cycle so at this moment of time we can maintain from and to (i.e from this point to start and to keep going with
    the help of parent till we reach to)  

some good problems 
1)find the number of cycles in the given graph(will the answer vary for undirected , directed , unweighted etc.?) 
2)print all the cycles in the given graph
3)given a src and dest in a graph print the lexicographically smallest path to reach from src to dest
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

int n,m,from,to;
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

bool detect_cycle_dfs_util(int cur,int par,vector<bool> &vis)
{
    cout<<cur<<' ';
    vis[cur]=true;

    for(int nb:adj[cur])
    {
        if(nb==par) continue;
        
        if(vis[nb]==1)
        {
            //from to will help us to track the cycle detected
            from=nb , to=cur;
            //cycle detected
            return true;
        }

        bool cyc = detect_cycle_dfs_util(nb,cur,vis);

        if(cyc)
            return true;
    }

    return false;
}

bool detect_cycle_dfs()
{
    vector<bool> vis(n+1,false);
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            bool found = detect_cycle_dfs_util(i,-1,vis);
            if(found)
            {
                return 1;
            }

            cout<<'\n';
        }
    }

    return 0;
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
    
    cout<<detect_cycle_dfs();
}

int main()
{
    FIO;
    solve();
}
