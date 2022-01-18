/*
strongly connected comp. : if in a component of di-graph each node is reachable via other node then it is SCC

while doing dfs traversal in Di-graph we get a dfs tree (maybe more than one comp. all will be having there own dfs tree)
and in addition to tree there are some edges which may not be direct part of tree and we label them acc. to the role they play 
basically there are 4 types of edges we encounter 
a)tree edges 
b)back edge
c)forward edge
d)cross edge

to understand them first thing which we need to keep track of is time at which given node curr is explored or putted under 
recursion stack 

here we mark the visited value of node as 
0-> the nodes which are not explored yet
1-> the nodes which are in the process of exploration(all the nodes inside recursion call stack)
2-> the nodes who's exploration(i.e node + it's dfs subtree) is done

in the below code i'll be mentioning all the 4 cases and i'll be labelling the nodes under corresponding case

now the classification of these 4 edges in dfs of di-graph depends on the following 
a)the dfs order in which they are called 
b)the adj list order in which nodes are stored

question 
1)given a di-graph find how many dfs trees can be possible for it ?
2)if in a given classification of edges in a comp. there are 1 back edge and one forward edge then is it gauranteed to have 
one back edge and one forward edge in all other configuration?

if there's a back edge in a component in a graph then it'll be having a cycle 
question 
a)given a di-graph how many comp. are cyclic
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
int tim=0,vis_time[100001];

void dfs_util(int i,vi &vis)
{
    vis[i]=1;
    vis_time[i]=++tim;

    for(auto &j:adj[i])
    {
        //considering the edge i->j

        if(vis[j]==0)
        {
            //tree edge
            dfs_util(j,vis);
        }

        else if(vis[j]==1)
        {
            //back edge 
            //(as the currNode(i) is pointing to it's ancestor(j) how?if vis[j]==1 it simply means that ith node belongs to the 
            //dfs subtree of j)
            //exploring self loop is also a back edge
        }

        //vis[j]=2 i.e j is already explored completely
        //now the question is , is it explored by dfs tree of node i or not 
        //if yes then vis_time[i] < vis_time[j]
        //then this edge is called forward edge
        else if(vis_time[i] < vis_time[j])
        {
            //forward edge
        }

        //if vis_time[j] < vis_time[i] that means j is explored by dfs tree of some node other than i 
        //this type of edge is called as cross edge
        else
        {
            //cross edge
        }
    }

    vis[i]=2;
}

void dfs_diGraph()
{
    vi vis(n+1,0);
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs_util(i,vis);
        }
    }
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
    
    dfs_diGraph();
}

int main()
{
    solve();
}
