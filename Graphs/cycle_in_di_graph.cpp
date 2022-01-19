/*
pre-requisite : DFS on Di graph 
back edge 

if there's no cycle in di-graph then it's called DAG(directed acyclic graph)

problems regarding DAG 
a) given a weighted DAG we need to tell the largest sum of weights between any two nodes(positive weights only)
hint: it's  better to start with the node having 0 indegree (once we do so then all we need to do is apply dfs from all these nodes and 
we can easily get the result by applying dp ,as dp can be applied to dag)
//code aaj krunga  
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

void dfs_util(int i,vi &vis)
{
    vis[i]=1;

    for(auto &j:adj[i])
    {
        //considering the edge i->j

        if(vis[j]==0)
        {
            //tree edge
            bool isCyclePresent = dfs_util(j,vis);
            if(isCyclePresent)
            {
                return true;
            }
        }

        else if(vis[j]==1)
        {
            //back edge 
            //(as the currNode(i) is pointing to it's ancestor(j) how?if vis[j]==1 it simply means that ith node belongs to the 
            //dfs subtree of j)
            //exploring self loop is also a back edge
            return true;
        }
    }

    vis[i]=2;

    return false;
}

bool cycle_on_di_graph()
{
    vi vis(n+1,0);
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            bool flag=dfs_util(i,vis);
            if(flag==true)
            {
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    int u,v,i;
    cin>>n>>m;
    adj.resize(n+1);
    
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    bool ans = cycle_on_di_graph();
}

int main()
{
    solve();
}
