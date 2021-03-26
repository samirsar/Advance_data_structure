#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//int  t[1002][1002];
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int>ii;
void update(vector<int>&segment_tree,int index,int Start,int End,int type,int pos)
{
    if(index<Start||index>End)
    return ;
    if(index==Start&&index==End)
    {
        if(type==1)
        {
            segment_tree[pos]+=1;
            
        }
        if(type==2)
        {
            if(segment_tree[pos]!=0)
            {
                segment_tree[pos]-=1;
            }
        }
        return ;

    }
        int mid=Start+(End-Start)/2;
        update(segment_tree,index,Start,mid,type,pos*2+1);
        update(segment_tree,index,mid+1,End,type,pos*2+2);
        segment_tree[pos]=segment_tree[pos*2+1]+segment_tree[pos*2+2];
    
}

int get_setbit(vector<int>segment_tree,int l,int r,int Start,int End,int pos)
{
    if(l>End||r<Start)
    return 0;
    if(l<=Start&&r>=End)
    {
        return segment_tree[pos];
    }
    int mid=Start+(End-Start)/2;
    return get_setbit(segment_tree,l,r,Start,mid,pos*2+1)+get_setbit(segment_tree,l,r,mid+1,End,pos*2+2);
}
int main()
{
    int  n;
    cin>>n;
    vector<int>segment_tree(4*n+1);
    fill(segment_tree.begin(),segment_tree.end(),0);

    int q;
    cout<<"Enter query"<<endl;
    cin>>q;
    while(q--)
    {
        int m;
        cout<<"type number"<<endl;
        cin>>m;
        if(m==1)
        {
            int x;
            cout<<"Enter index for type1"<<endl;
            cin>>x;
            update(segment_tree,x,0,n-1,1,0);
            
        }
        if(m==2)
        {
            int x;
            cout<<"Enter index for type2"<<endl;
            cin>>x;
            update(segment_tree,x,0,n-1,2,0);
        }
        if(m==3)
        {
            int l,r;
            cout<<"Enter left and right of type3"<<endl;
            cin>>l>>r;
            cout<<get_setbit(segment_tree,l,r,0,n-1,0)<<endl;
        }
    }
}

