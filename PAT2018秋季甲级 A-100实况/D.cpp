#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=10100;
int in[maxn],pre[maxn];
int left[maxn],right[maxn];
int fe[maxn],dep[maxn];
int build(int l1,int r1,int l2,int r2)
{
	if(l1>r1) return -1;
	if(l1==r1) return l1;
	int p=l1;
	for(;p<=r1;p++) if(in[p]==pre[l2]) break;
	left[p]=build(l1,p-1,l2+1,l2+p-l1);
	right[p]=build(p+1,r1,l2+p-l1+1,r2);
	return p;
}
int m,n;
void get(int x,int fa,int d)
{
	fe[x]=fa;dep[x]=d;
	if(left[x]!=-1) get(left[x],x,d+1);
	if(right[x]!=-1) get(right[x],x,d+1);
}
int lca(int tx,int ty)
{
	int x=tx,y=ty;
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fe[x];
	while(x!=y)
	{
		x=fe[x];y=fe[y];	
	}	
	return x;
}
int main()
{
	scanf("%d%d",&m,&n);
	map<int,int> id;
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&in[i]);
		id[in[i]]=i;
	}
	for(int i=0;i<n;i++) scanf("%d",&pre[i]);
	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));
	int root=build(0,n-1,0,n-1);
	get(root,-1,0);
	int a,b;
	/*
	LCA of 2 and 6 is 3.
8 is an ancestor of 1.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.
	*/
	while(m--)
	{
		scanf("%d%d",&a,&b);
		if(!id.count(a)&&id.count(b)) printf("ERROR: %d is not found.\n",a);
		else if(id.count(a)&&!id.count(b)) printf("ERROR: %d is not found.\n",b);
		else if(!id.count(a)&&!id.count(b)) printf("ERROR: %d and %d are not found.\n",a,b);
		else
		{
			int ans=lca(id[a],id[b]);
			if(ans==id[a]) printf("%d is an ancestor of %d.\n",a,b);
			else if(ans==id[b]) printf("%d is an ancestor of %d.\n",b,a);
			else printf("LCA of %d and %d is %d.\n",a,b,in[ans]);
		}
	}
	
}
