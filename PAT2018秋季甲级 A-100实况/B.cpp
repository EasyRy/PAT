#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200010;
struct Node
{
	int v;
	int next;
}e[maxn];
int first[maxn];
bool vis[maxn];
int n,m,a,b;
int main()
{
	scanf("%d%d",&n,&m);
	int s=0;
	memset(first,-1,sizeof(first));
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		e[s].v=b;e[s].next=first[a];first[a]=s++;
		e[s].v=a;e[s].next=first[b];first[b]=s++;
	}
	while(m--)
	{
		int k;scanf("%d",&k);
		bool flag=true;
		memset(vis,false,sizeof(vis));
		for(int i=0;i<k;i++)
		{
			scanf("%d",&a);
			vis[a]=true;
			for(int j=first[a];j!=-1;j=e[j].next)
			{
				if(vis[e[j].v]) flag=false;
			}
		}
		flag?printf("Yes\n"):printf("No\n");
	}
}
