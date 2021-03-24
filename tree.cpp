#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//int  t[1002][1002];
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int>ii;
int n; 
vector<vector<int>>adj;
map<int,bool>visited;
vector<int>level;
vector<int>sub_tree;
void dfs(int src)
{
    // cout<<src<<" ";
    sub_tree[src]=1;
    visited[src]=true;
    for(int x:adj[src])
    {
        
        if(not visited[x])
        {
            level[x]=level[src]+1;
            dfs(x);
            sub_tree[src]+=sub_tree[x];
        }
    }
}
int main()
{
    cin>>n;
    adj.resize(n+1);
    level.resize(n+1);
    level[1]=1;
    sub_tree.resize(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<sub_tree[i]<<endl;
    }
    

}