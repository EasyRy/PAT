#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=200000;
int v[maxn];
int a[maxn];
bool vis[maxn];
int main()
{
	int n;cin>>n;
	getchar();
	string line;
	getline(cin,line);
	stringstream ss(line);
	int x,p=1;
	while(ss>>x) v[p++]=x;
	for(int i=0;i<n;i++) cin>>a[i];
	memset(vis,false,sizeof(vis));
	int ansl,al,ar,ans=0,sum=0;
	int L=0,R=1;
	ans=v[a[0]];vis[a[0]]=true;al=0;ar=0;sum=v[a[0]];
	ansl=1;
	while(R<n)
	{
		while(vis[a[R]]){vis[a[L]]=false;sum-=v[a[L]];L++;}
		sum+=v[a[R]];vis[a[R]]=true;
		if(R-L+1>ansl)
		{
			ansl=R-L+1;
			ans=sum;
			al=L;ar=R;
		}
		else if(R-L+1==ansl&&sum>ans)
		{
			ansl=R-L+1;
			ans=sum;
			al=L;ar=R;			
		}				
		R++;
	}
	printf("%d %d %d\n",ans,al,ar);
}