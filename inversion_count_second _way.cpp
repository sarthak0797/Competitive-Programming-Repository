#include<bits/stdc++.h>

typedef long long int lli;

lli merge(int a[],int st,int mid,int ed)
{
    int i=st,j=mid+1,k=0,c[ed-st+1];
    lli cnt=0;

    while(i<=mid and j<=ed)
    {
        if(a[i]<=a[j])
            c[k++]=a[i++];
        if(a[j]<a[i])
        {
            cnt+=(mid-i+1);
            c[k++]=a[j++];
        }
    }

    while(i<=mid)
        c[k++]=a[i++];
    while(j<=ed)
        c[k++]=a[j++];
    k=0;
    for(i=st;i<=ed;i++)
        a[i]=c[k++];
    return cnt;
}

lli invcnt(int a[],int st,int ed)
{
    if(st==ed)
        return 0;
    int mid=(st+ed)/2;
    lli x1,x2,x3;
    x1=invcnt(a,st,mid);
    x2=invcnt(a,mid+1,ed);
    x3=merge(a,st,mid,ed);
    return x1+x2+x3;
}

long long solve(int A[], int n)
{
	lli x=invcnt(A,0,n-1);
    return x;
}
