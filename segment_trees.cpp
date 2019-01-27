#include<iostream>
using namespace std;
int tree[50]={0};
int a[50];
void build_sum(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build_sum(2*node, start, mid);
        build_sum(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1] ;
    }
}

void build_max(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build_max(2*node, start, mid);
        build_max(2*node+1, mid+1, end);
        tree[node] = max( tree[2*node] , tree[2*node+1]) ;
    }
}

void build_min(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build_min(2*node, start, mid);
        build_min(2*node+1, mid+1, end);
        tree[node] = min( tree[2*node] , tree[2*node+1]) ;
    }
}

void update(int node , int start , int end , int index , int val)
{
    if(start==end)
    {
        a[index]+=val;
        tree[node] = a[index];
        return;
    }
    int mid = (start+end)/2;
    if(start<=index && index<=mid)
        update(2*node , start , mid , index , val);
    else
        update(2*node+1 , start , mid , index , val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void show(int n)
{
    int i;
    for(i=1;i<(2*n+1) ;i++)
    {
        if(tree[i]!=0)
        {
            cout<<"\t"<<tree[i];

        }
    }
}

int sum(int node , int start ,  int end , int l , int r)
{
    if(r < start || end < l)
        return 0;

   if(l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    return( sum(2*node, start, mid, l, r) + sum(2*node+1, mid+1, end, l, r) );
}

int max_range(int node , int start ,  int end , int l , int r)
{
    if(r < start || end < l)
        return 0;

   if(l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    return( max(max_range(2*node, start, mid, l, r) , max_range(2*node+1, mid+1, end, l, r) ));
}

int min_range(int node , int start ,  int end , int l , int r)
{
    if(r < start || end < l)
        return 0;

   if(l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    return( max(min_range(2*node, start, mid, l, r) , min_range(2*node+1, mid+1, end, l, r) ));
}

void input(int n)
{
    int i;
    cout<<"\nEnter the elements:- ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

int main()
{
    int n,i,val,j,ch;
    cout<<"\n Enter the no. of elements:- ";
    cin>>n;
    input(n);

    cout<<"\n1...Sum Segment Tree";
    cout<<"\n2...Max Segment Tree";
    cout<<"\n3...Min Segment Tree";
    cout<<"\nEnter your choice:-";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            cout<<"\n Created a Segment tree:- ";
            build_sum(1,0,n-1);
            show(n);

            cout<<"\n Enter the value and the index to be updated:- ";
            cin>>val>>i;
            update(1,0,n-1,i,val);
            cout<<"\n Updated tree:- ";
            show(n);

            cout<<"\n Enter the range to find the sum of elements:- ";
            cin>>i>>j;
            val = sum(1,0,n-1,i,j);
            cout<<"\n The sum is:- "<<val;
            break;
        }
    case 2:
        {
            cout<<"\n Created a Segment tree:- ";
            build_max(1,0,n-1);
            show(n);

            cout<<"\n Enter the range to find the max of elements:- ";
            cin>>i>>j;
            val = max_range(1,0,n-1,i,j);
            cout<<"\n The max is:- "<<val;
            break;
        }
    case 3:
        {
            cout<<"\n Created a Segment tree:- ";
            build_min(1,0,n-1);
            show(n);

            cout<<"\n Enter the range to find the min of elements:- ";
            cin>>i>>j;
            val = min_range(1,0,n-1,i,j);
            cout<<"\n The max is:- "<<val;
            break;
        }
    }

    return 0;
}
