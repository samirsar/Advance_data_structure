#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//int  t[1002][1002];
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int>ii;
void construct_tree(vector<int>&segment_tree,vector<int>arr,int Start,int End,int pos)
{
    if(Start==End)
    {
        segment_tree[pos]=arr[Start];
        return ;
    }
    int mid=Start+(End-Start)/2;
    construct_tree(segment_tree,arr,Start,mid,pos*2+1);
    construct_tree(segment_tree,arr,mid+1,End,pos*2+2);
    segment_tree[pos]=max(segment_tree[pos*2+1],segment_tree[pos*2+2]);
}

int get_max_element(vector<int>segment_tree,int l,int r,int Start,int End,int pos)
{
    if(l>End||r<Start)
    return -1;
    if(l<=Start&&r>=End)
    {
        return segment_tree[pos];
    }
    int mid=Start+(End-Start)/2;
   int left= get_max_element(segment_tree,l,r,Start,mid,pos*2+1);
   int right= get_max_element(segment_tree,l,r,mid+1,End,pos*2+2);
   return max(left,right);
    
}

void update(vector<int>&segment_tree,int index,int value,int Start,int End,int pos)
{
    if(index<Start||index>End)
    return ;
    if(index==Start&&index==End)
    {
        segment_tree[pos]=value;
        return ;
    }
    int mid =Start+(End-Start)/2;
    update(segment_tree,index,value,Start,mid,pos*2+1);
    update(segment_tree,index,value,mid+1,End,pos*2+2);
    segment_tree[pos]=max(segment_tree[pos*2+1],segment_tree[pos*2+2]);
}
void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    vector<int>segment_tree(4*n+1);
    fill(segment_tree.begin(),segment_tree.end(),-1);
    construct_tree(segment_tree,arr,0,n-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int m;
        cin>>m;
        if(m==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<get_max_element(segment_tree,l,r,0,n-1,0)<<endl;
        }
        if(m==2)
        {
            int index,value;
            cin>>index>>value;
            update(segment_tree,index,value,0,n-1,0);
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
