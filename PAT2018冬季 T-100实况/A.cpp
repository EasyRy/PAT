#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=20000;
int a[maxn];
int n;
vector<int> v;
int mod;//-1 0 1 2
void dfs(int x)
{
	v.push_back(x);	
	if(2*x>n)
	{
		for(int i=0;i<v.size();i++) 
		{
			if(i) printf(" ");
			printf("%d",a[v[i]]);
		}
		printf("\n");
		bool ismax=true,ismin=true;
		for(int i=1;i<v.size();i++) 
		{
			if(a[v[i]]>a[v[i-1]]){ismax=false;break;}
 		}
 		for(int i=1;i<v.size();i++) 
		{
			if(a[v[i]]<a[v[i-1]]){ismin=false;break;}
 		}
 		if(mod<0) mod=-1;
 		if(mod==0)
 		{
 			if(ismax&&ismin) mod=0;
			else if(ismax) mod=1;
			else if(ismin) mod=2;
			else mod=-1;	
		}
		if(mod==1&&!ismax) mod=-1;
		if(mod==2&&!ismin) mod=-1;
		v.pop_back();
		return;
	}
	if(2*x+1<=n) dfs(2*x+1);
	if(2*x<=n) dfs(2*x);
	v.pop_back();		
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	mod=0;
	dfs(1);
	if(mod<0) printf("Not Heap\n");
	else if(mod<=1) printf("Max Heap\n");
	else printf("Min Heap\n");
}