#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=200;
int a[maxn],state[maxn];
int ans[10];
int n,m;
struct Node
{
	int x,y;
	bool operator <(const Node& e) const
	{
		return x<e.x||(x==e.x&&y<e.y);
	}
}gg;
bool solve(int x,int y,int sum)
{		
	memset(state,0,sizeof(state));
	state[x]=-1;state[y]=1;
	for(int i=1;i<=sum;i++)
	{
		if(i==x||i==y)
		{
			int t=-a[i];
			if(t<0)
			{
				if(state[-t]<0||state[-t]==0) state[-t]=-1;
				else return false;	
			}
			else
			{
				if(state[t]>0||state[t]==0) state[t]=1;
				else return false;
			}
		}
		else
		{
			int t=a[i];if(t<0) t=-t;
			if(a[i]<0)
			{
				if(state[t]<0||state[t]==0) state[t]=-1;
				else return false;
			}
			else
			{
				if(state[t]>0||state[t]==0) state[t]=1;
				else return false;
			}
		}
	}
	int sumw=0;
	for(int i=1;i<=sum;i++) if(state[i]<0) sumw++;
	if(sumw>2) return false;
	if(sumw==1)
	{
		int tot=0;
		for(int i=1;i<=sum;i++) if(state[i]<=0&&i!=x) tot++;
		if(tot<2) return false;	
		for(int i=1;i<=sum;i++)
		{
			if(state[i]==0)
			{
				int ti=i,tx=x;
				if(ti>tx) swap(ti,tx);
				Node tn{ti,tx};
				gg=min(gg,tn);
				return true;
			}
		}
	}
	else 
	{
		for(int i=1;i<=sum;i++) if(state[i]<0&&i!=x)
		{
			int ti=i,tx=x;
			if(ti>tx) swap(ti,tx);
			Node tn{ti,tx};
			gg=min(gg,tn);
			return true;
		}
	}	
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool flag=false;
	bool ok=false;
	gg.x=n+10;gg.y=n+10;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(solve(i,j,n))  flag=true;
		}
	}
	if(flag) printf("%d %d\n",gg.x,gg.y);
	else printf("No Solution\n");
}