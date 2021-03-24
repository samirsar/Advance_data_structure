#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//int  t[1002][1002];
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int>ii;

// construction of segmet tree 

void construct_tree(vector<int>&segment_tree,vector<int>arr,int Start,int End,int pos)
{
    if(Start>End)
    return ;
    if(Start==End)
    {
        segment_tree[pos]=arr[Start];
        return ;
    }
    int mid=Start+(End-Start)/2;
    construct_tree(segment_tree,arr,Start,mid,pos*2+1);
    construct_tree(segment_tree,arr,mid+1,End,pos*2+2);
   segment_tree[pos]=segment_tree[pos*2+1]+segment_tree[pos*2+2];


}

// get sum of range quaries 

int get_sum(vector<int>segment_tree,int a,int b,int Start,int End,int pos)
{
    
    if(a>End||b<Start)
    {
       return 0;
    }
    if(a<=Start&&b>=End)
    return segment_tree[pos];

    int mid=Start+(End-Start)/2;
    return get_sum(segment_tree,a,b,Start,mid,pos*2+1)+get_sum(segment_tree,a,b,mid+1,End,pos*2+2);
    
}
void update(vector<int>&segment_tree,int index,int value,int Start,int End,int pos)
{
    if(index<Start||index>End)
    return ;
    if(Start==index&&index==End)
    {
        segment_tree[pos]=value;
        return ;
    }
    int mid=Start+(End-Start)/2;
    update(segment_tree,index,value,Start,mid,pos*2+1);
    update(segment_tree,index,value,mid+1,End,pos*2+2);
    segment_tree[pos]=segment_tree[pos*2+1]+segment_tree[pos*2+2];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    vector<int>segment_tree(4*n+1);
    
    // memset(segment_tree,-1,sizeof(segment_tree));
    // for only array memset
    // fill for vector
    fill(segment_tree.begin(),segment_tree.end(),-1);
    construct_tree(segment_tree,arr,0,n-1,0);
    int a,b;
    cin>>a>>b;
    cout<<get_sum(segment_tree,a,b,0,n-1,0)<<endl;

    int index=2;
    int t=4;
    update(segment_tree,2,4,0,n-1,0);
    cout<<get_sum(segment_tree,a,b,0,n-1,0)<<endl;
   
    

}

