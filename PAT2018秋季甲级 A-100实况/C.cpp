#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=310;
const int INF=0x3f3f3f3f;
bool vis[maxn];
int ct[maxn];
int g[maxn][maxn];
int n,m,k;
int main()
{
	scanf("%d%d",&n,&m);
	int a,b,w;
	memset(g,INF,sizeof(g));
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		g[a][b]=min(g[a][b],w);
		g[b][a]=g[a][b];
	}
	scanf("%d",&k);
	int ans,answ=INF;
	for(int kk=1;kk<=k;kk++)
	{
		int T;scanf("%d",&T);
		for(int i=0;i<T;i++) scanf("%d",&ct[i]);
		int tot=0;
		bool iss=true,isc=true;
		memset(vis,false,sizeof(vis));
		int sumt=0;
		for(int i=0;i<T-1;i++)
		{
			tot+=g[ct[i]][ct[i+1]];
			if(vis[ct[i]]) iss=false;
			vis[ct[i]]=true;
		}
		for(int i=1;i<=n;i++) if(vis[i]) sumt++;
		if(ct[0]!=ct[T-1]||sumt!=n)iss=isc=false;
		printf("Path %d: ",kk);
		if(tot>=INF) {printf("NA ");iss=isc=false;}
		else printf("%d ",tot);
		if(iss) printf("(TS simple cycle)\n");
		else if(isc) printf("(TS cycle)\n");
		else printf("(Not a TS cycle)\n");
		if(iss||isc)
		{
			if(tot<answ)
			{
				answ=tot;
				ans=kk;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n",ans,answ);
}