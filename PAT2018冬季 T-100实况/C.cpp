#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1100;
struct Node
{
	int l,r,addv,sum;
}e[maxn*4];
int a[maxn];
void build(int l,int r,int o)
{
	e[o].l=l;e[o].r=r;
	e[o].addv=e[o].sum=0;
	if(l==r) return;
	int mid=l+(r-l)/2;
	build(l,mid,2*o);
	build(mid+1,r,2*o+1);	
}
void pushdown(int o)
{
	if(e[o].addv)
	{
		e[2*o].addv+=e[o].addv;
		e[2*o+1].addv+=e[o].addv;
		e[2*o].sum+=e[o].addv*(e[2*o].r-e[2*o].l+1);
		e[2*o+1].sum+=e[o].addv*(e[2*o+1].r-e[2*o+1].l+1);
		e[o].addv=0;
	}
}
void add(int l,int r,int o)
{
	if(e[o].l==l&&e[o].r==r)
	{
		e[o].addv++;
		e[o].sum+=(e[o].r-e[o].l+1);
		return;
	}
	pushdown(o);
	int mid=(e[o].r-e[o].l)/2+e[o].l;
	if(r<=mid) add(l,r,2*o);
	else if(l>mid) add(l,r,2*o+1);
	else
	{
		add(l,mid,2*o);
		add(mid+1,r,2*o+1);
	}
	e[o].sum=e[2*o].sum+e[2*o+1].sum;
}
int query(int l,int r,int o)
{
	if(e[o].l==l&&e[o].r==r) return e[o].sum;
	pushdown(o);
	int mid=(e[o].r-e[o].l)/2+e[o].l;
	if(r<=mid) return query(l,r,2*o);
	else if(l>mid) return query(l,r,2*o+1);
	else return query(l,mid,2*o)+query(mid+1,r,2*o+1);	
}
int px[maxn][maxn];
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	build(1,n,1);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int  g=0;
		if(a[i]==n) g=0;		
		else g=query(a[i]+1,n,1);
		add(a[i],a[i],1);
		ans+=g;
	}	
	for(int i=0;i<n;i++)
	{
		build(1,n,1);
		int x=0;
		for(int k=i;k<n;k++)
		{
			int  g=0;
			if(a[k]==n) g=0;		
			else g=query(a[k]+1,n,1);
			add(a[k],a[k],1);
			x+=g;
			px[i][k]=x;
		}			
	}
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int x,p;
			p=ans+(j-i)*(j-i+1)/2-2*px[i][j];
			if(flag) flag=false;
			else printf(" ");
			printf("%d",p);
		}
	}
	printf("\n");
}