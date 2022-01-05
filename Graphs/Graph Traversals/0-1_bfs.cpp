/*
problem :- https://www.codechef.com/problems/SNSOCIAL
*/

/*
suppose there are 3 special kinds of sources(depending on problem eg:- having smallest value largest value etc.)
let's name them as s1,s2,s3 then after applying multi source bfs we'll get the shortest distance of every node from 
these sources i.e shortest_distance_of_(i,j)=min(dis(i,j) from s1 , 
                                                 dis(i,j) from s2 ,
                                                 dis(i,j) from s3)
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
int a[501][501];
int dir[]={-1,0,1,0,-1,1,1,-1,-1};
class cell{
public:
    int x,y,d;
};

bool out(int x,int y)
{
    return (x<0 || x>=n || y<0 || y>=m);
}

//given a list of sources we're applying multi source bfs to figure out min dist of all points from these nodes
void ms_bfs(vector<cell> &src)
{
    queue<cell> q;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<int>> dis(n,vector<int>(m,-1));
    int x,y,dx,dy,d,i,ans=0;
    
    for(auto &s:src)
    {
        x=s.x,y=s.y,d=0;
        q.push(s);
        vis[x][y]=true;
        dis[x][y]=0;
    }
    
    while(!q.empty())
    {
        cell curr=q.front();
        q.pop();
        x=curr.x,y=curr.y,d=curr.d;
        
        for(i=0;i<8;i++)
        {
            dx=x+dir[i];
            dy=y+dir[i+1];
            
            if(out(dx,dy) || vis[dx][dy])   
            {
                continue;
            }
            
            vis[dx][dy]=true;
            dis[dx][dy]=d+1;
            cell n;
            n.x=dx,n.y=dy,n.d=d+1;
            q.push(n);
            ans=max(ans,dis[dx][dy]);
        }
    }
    
    cout<<ans<<endl;
}

void solve()
{
    int i,j,mx=0;
    cin>>n>>m;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            mx=max(mx,a[i][j]);
        }
    }
    
    vector<cell> src;
    cell curr;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==mx)
            {
                curr.x=i,curr.y=j,curr.d=0;
                src.push_back(curr);            
            }
        }
    }
    
    ms_bfs(src);
}

int main()
{
    FIO;
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
}
